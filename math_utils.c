/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:42:34 by eriviere          #+#    #+#             */
/*   Updated: 2024/10/24 17:11:11 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, t_fractal *fractal)
{
	return ((fractal->new_max - fractal->new_min) * (unscaled_num
			- fractal->old_min) / (fractal->old_max - fractal->old_min)
		+ fractal->new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

/*
   (x_real + y_imaginary)^2
   (x + yi) * (x + yi)
   x^2 + xyi + xyi + y^2i^2 --> i^2 = -1
   x^2 + 2xyi - y^2 		--> mixed real & imaginary
   (x^2 - y^2) + (2xyi)		--> real part & imaginary part
   REAL = (x^2 - y^2)
   IMAG = 2*x*y
*/
t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
