/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:35:08 by gmajstru          #+#    #+#             */
/*   Updated: 2018/10/19 17:29:38 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_bounds(t_env *fr, char *fractal)
{
	if (!ft_strncmp(fractal, "mandelbrot", ft_strlen("mandelbrot")) ||
		!ft_strncmp(fractal, "burningship", ft_strlen("burningship")))
	{
		set_point_value(&fr->bound1, -2.4, -1.2);
		set_point_value(&fr->bound2, 2.0, 1.2);
	}
	else if (!ft_strncmp(fractal, "julia", ft_strlen("julia")))
	{
		set_point_value(&fr->bound1, -1, -1.2);
		set_point_value(&fr->bound2, 1, 1.2);
	}
}

t_cam	*init_cam(t_env *env)
{
	t_cam	*cam;

	cam = NULL;
	if (!(cam = (t_cam*)malloc(sizeof(t_cam))) ||
		!(cam->img_ptr = mlx_new_image(env->mlx_ptr, WIDTH, WIDTH)) ||
		!(cam->img_data = (int*)mlx_get_data_addr(cam->img_ptr, &cam->bpp,
			&cam->sizeline, &cam->endian)))
		on_init_error_exit("CAM NOT SUCCESSFULLY INITIALIZED !", EXIT_FAILURE);
	set_point_value(&cam->cam_pos, 0, 0);
	return (cam);
}

t_env	*init_env(char *fractal, int in_zoom, int in_iter)
{
	t_env *env;

	env = NULL;
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		on_init_error_exit("Malloc error (env -> init_env() !", EXIT_FAILURE);
	env->fractal_name = fractal;
	env->it = 0;
	env->zoom = in_zoom;
	env->max_iter = in_iter;
	env->in_iter = in_iter;
	set_im_value(&env->julia_param, 0.285, 0.01);
	init_bounds(env, fractal);
	if (!(env->mlx_ptr = mlx_init()) ||
		!(env->mlx_win = mlx_new_window(env->mlx_ptr,
			WIDTH, WIDTH, fractal)) ||
		!(env->mlx_cam = init_cam(env)))
		on_init_error_exit("init failed !", EXIT_FAILURE);
	env->main_color = convert_color_tocolor(BLACK);
	env->mv_rate = 0.1;
	return (env);
}
