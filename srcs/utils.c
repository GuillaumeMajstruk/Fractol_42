/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:28:11 by gmajstru          #+#    #+#             */
/*   Updated: 2018/10/19 17:29:50 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		is_only_digit(char *str)
{
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

void	set_point_value(t_point *pt, double in_x, double in_y)
{
	if (!pt)
		return ;
	pt->x = in_x;
	pt->y = in_y;
}

void	set_im_value(t_im *im, double in_re, double in_im)
{
	if (!im)
		return ;
	im->re = in_re;
	im->im = in_im;
}

void	set_dim_value(t_dim *dim, int in_w, int in_h)
{
	if (!dim)
		return ;
	dim->width = in_w;
	dim->height = in_h;
}

void	print_point(double x, double y)
{
	ft_putstr("[x = ");
	ft_putnbr(x);
	ft_putstr(" : y = ");
	ft_putnbr(y);
	ft_putendl("]");
}
