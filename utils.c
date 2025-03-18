/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:46:49 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/18 20:36:44 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atodbl(char *s)
{
	long	integer;
	double	fraction;
	double	pow;
	int		sign;

	integer = 0;
	fraction = 0;
	sign = +1;
	pow = 1;
	while ((*s == 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		integer = (integer * 10) + (*s++ - 48);
	if (*s == '.')
		s++;
	while (*s)
	{
		pow /= 10;
		fraction = fraction + (*s++ - 48) * pow;
	}
	return ((integer + fraction) * sign);
}
double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}	

// t_complex	sum_complex(t_complex z1, t_complex z2)
// {
// 	t_complex	result;

// 	result.x = z1.x + z2.x;
// 	result.y = z1.y + z2.y;
// 	return (result);
// }

// t_complex	square_complex(t_complex z)
// {
// 	t_complex	result;

// 	result.x = (z.x * z.x) - (z.y * z.y);
// 	result.y = 2 * z.x * z.y;
// 	return (result);
// }
