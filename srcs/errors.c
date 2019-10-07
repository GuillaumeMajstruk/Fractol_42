/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:05:10 by gmajstru          #+#    #+#             */
/*   Updated: 2018/10/19 17:29:32 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	on_init_error_exit(char const *err_msg, int exit_code)
{
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(exit_code);
}
