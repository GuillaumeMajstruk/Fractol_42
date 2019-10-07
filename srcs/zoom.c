/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:37:35 by gmajstru          #+#    #+#             */
/*   Updated: 2018/10/17 19:13:36 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_in(t_env *env)
{
	env->zoom *= (env->zoom * 1.3 >= __LONG_MAX__) ? 1 : 1.3;
	env->bound1.x = (env->mouse_pos.x / (env->zoom / 1.3) +
		env->bound1.x) - (env->mouse_pos.x / (env->zoom));
	env->bound1.y = (env->mouse_pos.y / (env->zoom / 1.3) +
		env->bound1.y) - (env->mouse_pos.y / (env->zoom));
	env->max_iter++;
	env->mv_rate /= 1.3;
}

void	zoom_out(t_env *env)
{
	env->zoom /= (env->zoom / 1.3 > 0) ? 1.3 : 1;
	env->bound1.x = (env->mouse_pos.x / (env->zoom * 1.3) +
		env->bound1.x) - (env->mouse_pos.x / (env->zoom));
	env->bound1.y = (env->mouse_pos.y / (env->zoom * 1.3) +
		env->bound1.y) - (env->mouse_pos.y / (env->zoom));
	env->max_iter -= (env->max_iter - 1 > 0) ? 1 : 0;
	env->mv_rate *= 1.3;
}

void	incr_iter(t_env *env)
{
	env->max_iter += (env->max_iter + 10 < __INT_MAX__) ? 10 : 0;
}

void	decr_iter(t_env *env)
{
	env->max_iter -= (env->max_iter - 10 > 0) ? 10 : 0;
}
