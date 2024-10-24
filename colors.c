/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:50:41 by eriviere          #+#    #+#             */
/*   Updated: 2024/10/24 17:15:24 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	*init_colors(void)
{
	int	*colors;

	colors = (int *)malloc(sizeof(int) * 10);
	if (!colors)
		return (NULL);
	colors[0] = 0xFF0000;
	colors[1] = 0x00FF00;
	colors[2] = 0x0000FF;
	colors[3] = 0xFFFF00;
	colors[4] = 0xFF00FF;
	colors[5] = 0x00FFFF;
	colors[6] = 0xFFFFFF;
	colors[7] = 0x000000;
	colors[8] = 0xFFA500;
	colors[9] = 0x800080;
	return (colors);
}

int	get_color(int *colors, int size)
{
	return (colors[rand() % size]);
}

void	free_colors(int *colors)
{
	free(colors);
}

unsigned int	map_iterations_to_color(t_fractal *fractal, int iteration)
{
	double			normalized_value;
	unsigned int	color;

	if (iteration < 0)
		return (fractal->color_s);
	else if (iteration >= fractal->iterations_definition)
		return (fractal->color_e);
	normalized_value = (double)iteration / fractal->iterations_definition;
	color = (unsigned int)((1.0 - normalized_value) * fractal->color_s
			+ normalized_value * fractal->color_e);
	return (color);
}
