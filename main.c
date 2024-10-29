/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:23:30 by eriviere          #+#    #+#             */
/*   Updated: 2024/10/29 12:09:15 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//Para tests
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if ((argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10)
				||!ft_strncmp(argv[1], "burningship", 11)))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)
			&& (is_double(argv[2]) && is_double(argv[3]))))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_con);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
