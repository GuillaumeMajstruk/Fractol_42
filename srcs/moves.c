/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:30:47 by gmajstru          #+#    #+#             */
/*   Updated: 2018/10/17 19:08:48 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move_right(t_env *env)
{
	env->bound1.x -= env->mv_rate;
}

void	move_left(t_env *env)
{
	env->bound1.x += env->mv_rate;
}

void	move_up(t_env *env)
{
	env->bound1.y -= env->mv_rate;
}

void	move_down(t_env *env)
{
	env->bound1.y += env->mv_rate;
}
