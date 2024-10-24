/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:23:05 by eriviere          #+#    #+#             */
/*   Updated: 2024/10/24 17:24:09 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# define ERROR_MESSAGE "params: mandelbrot/burninship/julia<n1><n2>\n"
# define WIDTH 800
# define HEIGHT 800

//Complex value
typedef struct s_complex
{
	double	x;//real number
	double	y;//imaginary number
}			t_complex;

//Image structure
typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

//Range structure
typedef struct s_range
{
	double	min;
	double	max;
}			t_range;

//Fractal structure
typedef struct s_fractal
{
	char	*name;
	void	*mlx_con;
	void	*mlx_win;
	t_img	img;
	//Hooks member variables
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		color_s;
	int		color_e;
	int		color_f;
	double	old_min;
	double	old_max;
	double	new_min;
	double	new_max;
}			t_fractal;

//s_utils
int				ft_strncmp(char *s1, char *s2, int n);
void			ft_putstr_fd(char *s, int fd);
void			fractal_init(t_fractal *fractal);
double			atodbl(char *s);

//math utils
double			map(double unscaled_num, t_fractal *fractal);
t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		square_complex(t_complex z);

//render
void			fractal_render(t_fractal *fractal);

//Hooks/Events
int				key_handler(int keysym, t_fractal *fractal);
int				close_handler(t_fractal *fractal);
int				mouse_handler(int button, int x, int y, t_fractal *fractal);

//Colors
int				*init_colors(void);
int				get_color(int *colors, int size);
void			free_colors(int *colors);
unsigned int	map_iterations_to_color(t_fractal *fractal, int iteration);
#endif
