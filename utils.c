/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:46:49 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/14 18:12:32 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// double	ft_atodbl(char *str)
// {
// 	long	interger;
// 	double	fraction;
// 	double	pow;
// 	int		sign;

// 	interger = 0;
// 	fraction = 0;
// 	sign = 1;
// 	pow = 1;
// 	while ((*str >= 9 && *str <= 13) || *str == 32)
// 			str++;
// 	while (*str == '+' || *str == '-')
// 			if (*str++ == '-')
// 				sign = -sign;
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		interger = (interger * 10) + (*str - '0');
// 		str++;
// 	}
// 	if (*str == '.')
// 	{
// 		str++;
// 		while (*str >= '0' && *str <= '9')
// 			pow /= 10;
// 			fraction += (*str - '0') * pow;
// 			str++;
// 	}
// 	return (interger + fraction) * sign;
// }

double	atodbl(char *s)
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

void	ft_mouse_scroll(double xdelta, double ydelta, void *param)
{
	t_julia	*j = (t_julia *)param;
}