/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:04:37 by gmajstru          #+#    #+#             */
/*   Updated: 2018/10/19 17:29:27 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_fractim_val(t_env *env, int x, int y)
{
	if (!ft_strncmp(env->fractal_name, "mandelbrot",
			ft_strlen("mandelbrot")) ||
		!ft_strncmp(env->fractal_name, "burningship",
			ft_strlen("burningship")))
	{
		set_im_value(&env->c, x / (double)env->zoom + env->bound1.x,
					y / (double)env->zoom + env->bound1.y);
		set_im_value(&env->z, (double)0, (double)0);
	}
	else if (!ft_strncmp(env->fractal_name, "julia",
		ft_strlen("julia")))
	{
		set_im_value(&env->c, env->julia_param.re, env->julia_param.im);
		set_im_value(&env->z, x / (double)env->zoom + env->bound1.x,
					y / (double)env->zoom + env->bound1.y);
	}
}

void	compute_fractal(t_env *env)
{
	while (env->z.re * env->z.re + env->z.im * env->z.im < 4 &&
		env->it < env->max_iter)
	{
		if (!ft_strncmp(env->fractal_name, "burningship",
			ft_strlen("burningship")))
		{
			env->temp = (env->z.re * env->z.re) - (env->z.im * env->z.im) +
				env->c.re;
			set_im_value(&env->z,
				env->temp,
				fabs(2 * env->z.re * env->z.im) + env->c.im);
		}
		else
		{
			env->temp = env->z.re;
			set_im_value(&env->z,
				env->z.re * env->z.re - env->z.im * env->z.im + env->c.re,
				2 * env->temp * env->z.im + env->c.im);
		}
		env->it++;
	}
}

void	set_pixel_color(t_env *env, int i, int x, int y)
{
	int		pi_pos;
	t_color	alt_color;

	pi_pos = y * WIDTH + x;
	if (!ft_strncmp(env->fractal_name, "burningship", ft_strlen("burningship")))
		alt_color = init_color(0, i * 40, i * 400 / env->max_iter, 0);
	else
		alt_color = init_color(i * 800 / env->max_iter, 0,
			i * 400 / env->max_iter, 0);
	if (i == env->max_iter)
		env->mlx_cam->img_data[pi_pos] = convert_color_touint(env->main_color);
	else
		env->mlx_cam->img_data[pi_pos] = convert_color_touint(alt_color);
}

void	*draw_fract(void *data)
{
	t_env	*env;
	int		tmp;

	env = (t_env*)data;
	env->x = -1;
	tmp = env->y;
	while (++env->x < WIDTH)
	{
		env->y = tmp;
		while (env->y < env->y_m)
		{
			env->it = 0;
			set_fractim_val(env, env->x, env->y);
			compute_fractal(env);
			set_pixel_color(env, env->it, env->x, env->y);
			env->y++;
		}
	}
	return (data);
}

void	draw_th(t_env *env)
{
	t_env		tab[THREAD_N];
	pthread_t	t[THREAD_N];
	int			i;

	i = 0;
	while (i < THREAD_N)
	{
		ft_memcpy((void*)&tab[i], (const void*)env, sizeof(t_env));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].y_m = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, draw_fract, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
}
