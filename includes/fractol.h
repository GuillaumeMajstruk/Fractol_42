/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:48:51 by gmajstru          #+#    #+#             */
/*   Updated: 2018/10/19 17:30:00 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <pthread/pthread.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define MANDELBROT		"Mandelbrot"
# define JULIA			"Julia"
# define WHITE			0xFFFFFF
# define BLACK			0x000000
# define GREEN_I		0x35FF5B
# define THREAD_N		120
# define THREAD_WIDTH	5
# define WIDTH			700

typedef struct s_color			t_color;
typedef struct s_imaginary		t_im;
typedef struct s_point			t_point;
typedef struct s_dimension		t_dim;
typedef struct s_camera			t_cam;
typedef struct s_fractal		t_f;
typedef struct s_environement	t_env;
typedef enum e_keycode			t_key;
typedef unsigned int			t_u_int;

struct						s_color
{
	int r;
	int g;
	int b;
	int a;
};

struct						s_imaginary
{
	double	re;
	double	im;
};

struct						s_point
{
	double	x;
	double	y;
};

struct						s_dimension
{
	int	width;
	int	height;
};

struct						s_camera
{
	void	*img_ptr;
	int		*img_data;
	int		bpp;
	int		sizeline;
	int		endian;
	t_point	cam_pos;
};

struct						s_environement
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			it;
	t_cam		*mlx_cam;
	double		zoom;
	t_color		main_color;
	char		*fractal_name;
	int			max_iter;
	int			in_iter;
	double		mv_rate;
	t_point		mouse_pos;
	t_f			*fr;
	int			x;
	int			y;
	int			y_m;
	t_point		bound1;
	t_point		bound2;
	t_im		z;
	t_im		c;
	t_im		julia_param;
	double		temp;
};

enum						e_keycode
{
	Esc = 53,
	Left = 123,
	Right,
	Down = 125,
	Up,
	Plus = 24,
	Minus = 27,
	Multiple = 67,
	Divide = 75,
	Reset_view = 15
};

/*
** init.c:
**	Functions that initialize environement stuff etc...
*/
void						init_bounds(t_env *fr, char *fractal);
t_cam						*init_cam(t_env *env);
t_env						*init_env(char *fractal, int in_zoom, int in_iter);
/*
** errors.c:
**	Functions that deals with errors etc...
*/
int							on_init_error_exit(char const *err_msg,
												int exit_code);
/*
** utils.c:
**	Functions that have simple utilities such as
**	assigning values to point, imaginaries numbers etc...
*/
int							is_only_digit(char *str);
void						set_point_value(t_point *pt,
											double in_x,
											double in_y);
void						set_im_value(t_im *im, double in_re, double in_im);
void						set_dim_value(t_dim *dim, int in_w, int in_h);
void						print_point(double x, double y);
/*
** colors.c:
**	Create, manipulate
**	convert from or to t_color / unsigned int values etc...
*/
t_color						init_color(int r, int g, int b, int a);
t_u_int						convert_color_touint(t_color color);
t_color						convert_color_tocolor(t_u_int col_val);
/*
** drawer.c:
**	Functions that draw the fractal according to the asked type
*/
void						set_fractim_val(t_env *env, int x, int y);
void						compute_fractal(t_env *env);
void						set_pixel_color(t_env *env, int i, int x, int y);
void						*draw_fract(void *data);
void						draw_th(t_env *env);
/*
** moves.c:
**	Functions that allow the user to move into the fractal representation
*/
void						move_right(t_env *env);
void						move_left(t_env *env);
void						move_up(t_env *env);
void						move_down(t_env *env);
/*
** zoom.c:
**	Functions that allow the user to zoom in and zoom out in the fractal
**	according to the mouse pointer position and increase/decrease iter number
*/
void						zoom_in(t_env *env);
void						zoom_out(t_env *env);
void						incr_iter(t_env *env);
void						decr_iter(t_env *env);
/*
** overlay.c:
**	Basic overlay to display basic informations
*/
void						display_overlay(t_env *env);
/*
** event_manager.c:
**	Functions to deal with mlx_events such as keyboard events, mouse and etc...
*/
void						update_screen(t_env *env);
int							key_hook(int keycode, t_env *env);
int							mouse_mv_hook(int x, int y, t_env *env);
int							mouse_hook(int mouse_button, int x, int y,
										t_env *env);
/*
** viewport.c:
**	Function that reset the viewpoint to its original state
*/
void						reset_viewport(t_env *env);

#endif
