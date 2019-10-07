/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:42:25 by gmajstru          #+#    #+#             */
/*   Updated: 2018/10/19 17:29:42 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	check_args(int argc, char **argv)
{
	if (argc != 3)
		on_init_error_exit("args number is incorrect !", EXIT_FAILURE);
	if ((ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")) &&
		ft_strncmp(argv[1], "julia", ft_strlen("julia"))) &&
		ft_strncmp(argv[1], "burningship", ft_strlen("burningship")))
		on_init_error_exit("Fractal is not recognized !", EXIT_FAILURE);
	if (!is_only_digit(argv[2]))
		on_init_error_exit("iterations must be a number", EXIT_FAILURE);
	if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[2]) > 1000)
		on_init_error_exit("iterations must be [ > 0 ; <= 1000 ]",
			EXIT_FAILURE);
}

int			main(int argc, char **argv)
{
	t_env	*env;

	check_args(argc, argv);
	if (!(env = init_env(argv[1], 300, ft_atoi(argv[2]))))
		on_init_error_exit("Env failed to init !", EXIT_FAILURE);
	draw_th(env);
	update_screen(env);
	mlx_hook(env->mlx_win, 2, 1, key_hook, env);
	mlx_hook(env->mlx_win, 6, 1, mouse_mv_hook, env);
	mlx_hook(env->mlx_win, 4, 1, mouse_hook, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
