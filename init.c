/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:13:19 by eriviere          #+#    #+#             */
/*   Updated: 2024/10/29 12:12:21 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problem with malloc");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 6;
	fractal->iterations_definition = 20;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->color_s = 0x000000;
	fractal->color_e = 0xFFFFFF;
	fractal->color_f = 0xFF0000;
	fractal->new_min = -2;
	fractal->new_max = 2;
	fractal->old_min = 0;
	fractal->old_max = WIDTH;
}

static void	event_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_win, ButtonPress, ButtonPressMask, mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_win, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_con = mlx_init();
	if (fractal->mlx_con == NULL)
		malloc_error();
	fractal->mlx_win = mlx_new_window(fractal->mlx_con, WIDTH,
			HEIGHT, fractal->name);
	if (fractal->mlx_win == NULL)
	{
		mlx_destroy_display(fractal->mlx_con);
		free(fractal->mlx_con);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_con, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_con, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_con);
		free(fractal->mlx_con);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	event_init(fractal);
	data_init(fractal);
}
