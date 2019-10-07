/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 20:46:15 by gmajstru          #+#    #+#             */
/*   Updated: 2018/10/19 16:50:36 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	reset_viewport(t_env *env)
{
	env->zoom = 300;
	if (!ft_strncmp(env->fractal_name, "julia", ft_strlen("julia")))
	{
		set_point_value(&env->bound1, -1, -1.2);
		set_point_value(&env->bound2, 1, 1.2);
	}
	else
	{
		set_point_value(&env->bound1, -2.4, -1.2);
		set_point_value(&env->bound2, 2.0, 1.2);
	}
	env->mv_rate = 0.1;
	env->max_iter = env->in_iter;
}
