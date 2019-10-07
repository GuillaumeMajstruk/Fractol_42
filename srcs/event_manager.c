/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:50:59 by gmajstru          #+#    #+#             */
/*   Updated: 2018/10/19 16:55:41 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	update_mouse_pos(t_env *env, int x, int y)
{
	if ((x >= 0 && y >= 0) &&
		x <= WIDTH && y <= WIDTH)
		set_point_value(&env->mouse_pos, x, y);
	else
		set_point_value(&env->mouse_pos, 0, 0);
}

void		update_screen(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->mlx_win);
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_cam->img_ptr,
		0, 0);
	display_overlay(env);
}

int			key_hook(int keycode, t_env *env)
{
	if (keycode == Esc)
		exit(EXIT_SUCCESS);
	else if (keycode == Right)
		move_right(env);
	else if (keycode == Left)
		move_left(env);
	else if (keycode == Up)
		move_up(env);
	else if (keycode == Down)
		move_down(env);
	else if (keycode == Plus)
		zoom_in(env);
	else if (keycode == Minus)
		zoom_out(env);
	else if (keycode == Multiple)
		incr_iter(env);
	else if (keycode == Divide)
		decr_iter(env);
	else if (keycode == Reset_view)
		reset_viewport(env);
	draw_th(env);
	update_screen(env);
	return (0);
}

int			mouse_mv_hook(int x, int y, t_env *env)
{
	update_mouse_pos(env, x, y);
	if (!ft_strncmp(env->fractal_name, "julia", ft_strlen("julia")))
	{
		set_im_value(&env->julia_param,
			(env->mouse_pos.x / (env->zoom * 1.3) + env->bound1.x),
			(env->mouse_pos.y / (env->zoom * 1.3) + env->bound1.y));
		set_im_value(&env->c, env->julia_param.re, env->julia_param.im);
		draw_th(env);
	}
	update_screen(env);
	return (0);
}

int			mouse_hook(int mouse_button, int x, int y, t_env *env)
{
	if (!ft_strncmp(env->fractal_name, "julia", ft_strlen("julia")))
		return (0);
	update_mouse_pos(env, x, y);
	if (mouse_button == 4)
		zoom_in(env);
	else if (mouse_button == 5)
		zoom_out(env);
	draw_th(env);
	update_screen(env);
	return (0);
}
