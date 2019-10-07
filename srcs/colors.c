/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:58:36 by gmajstru          #+#    #+#             */
/*   Updated: 2018/10/19 17:29:15 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_color		init_color(int r, int g, int b, int a)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

t_u_int		convert_color_touint(t_color color)
{
	t_u_int	col;

	col = (color.a << 24) + (color.r << 16) + (color.g << 8) + color.b;
	return (col);
}

t_color		convert_color_tocolor(t_u_int col_val)
{
	t_color	color;

	color.a = (col_val >> 24) & 255;
	color.r = (col_val >> 16) & 255;
	color.g = (col_val >> 8) & 255;
	color.b = col_val & 255;
	return (color);
}
