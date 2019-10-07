/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:48:53 by gmajstru          #+#    #+#             */
/*   Updated: 2018/10/19 17:04:52 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	display_overlay(t_env *env)
{
	char	*current_iter;
	char	*current_set;
	char	*help1;
	char	*help2;
	char	*m_iter;

	m_iter = ft_itoa(env->max_iter);
	current_iter = ft_strjoin("Current iteration number: ", m_iter);
	current_set = ft_strjoin("Current set: ", env->fractal_name);
	help1 = ft_strdup("move: arrows | zoom in/out '+'/'-'/mouse wheel");
	help2 = ft_strdup("increase/decrease iteration: '*'/'/' | reset: 'r'");
	mlx_string_put(env->mlx_ptr, env->mlx_win, 20, 605, WHITE, current_set);
	mlx_string_put(env->mlx_ptr, env->mlx_win, 20, 625, WHITE, current_iter);
	mlx_string_put(env->mlx_ptr, env->mlx_win, 20, 645, GREEN_I, help1);
	mlx_string_put(env->mlx_ptr, env->mlx_win, 20, 665, GREEN_I, help2);
	ft_strdel(&m_iter);
	ft_strdel(&current_iter);
	ft_strdel(&current_set);
	ft_strdel(&help1);
	ft_strdel(&help2);
}
