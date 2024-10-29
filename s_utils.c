/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:30:07 by eriviere          #+#    #+#             */
/*   Updated: 2024/10/29 12:09:01 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		ft_putstr_fd(s + 1, fd);
	}
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = 1;
	pow = 1.0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -1;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - '0') * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

int	is_double(char *s)
{
	while (*s)
	{
		while ((*s >= 9 && *s <= 13) || *s == 32)
			s++;
		if (*s == '+' || *s == '-')
			s++;
		while (*s != '.' && (*s >= '0' && *s <= '9'))
			s++;
		if (*s == '.')
			s++;
		while (*s >= '0' && *s <= '9')
			s++;
		if (*s)
			return (0);
	}
	return (1);
}
