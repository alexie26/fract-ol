/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:46:49 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/23 21:20:07 by roalexan         ###   ########.fr       */
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

int	is_valid_number(const char *str)
{
	int		i;
	int		has_digit;
	int		has_dot;

	i = 0;
	has_digit = 0;
	has_dot = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			has_digit = 1;
		else if (str[i] == '.' && !has_dot)
			has_dot = 1;
		else
			return (0);
		i++;
	}
	return (has_digit);
}

void	info_message(void)
{
	ft_printf("⊱ ───────────────── {.⋅ Fractol ⋅.} ───────────────── ⊰\n\n");
	ft_printf("Which fractal would you like to see?\n\n");
	ft_printf("Generate \033[1;35mMandelbrot\033[0m fractal.\n");
	ft_printf("\033[36m ./fractol mandelbrot\033[0m\n\n");
	ft_printf("Generate \033[1;35mTricorn\033[0m fractal.\n");
	ft_printf("\033[36m ./fractol tricorn\033[0m\n\n");
	ft_printf("Generate \033[1;35mJulia\033[0m fractal.\n");
	ft_printf("\e[36mUsage example:\t");
	ft_printf("./fractol julia\n\t\t./fractol julia 0.285 0.01\n");
	ft_printf("\t\t./fractol julia -0.4 0.6\n");
	ft_printf("\t\t./fractol julia -1.476 0.0\n");
	ft_printf("\t\t./fractol julia 0.3 -0.01\e[0m\n\n");
	ft_printf("\033[36m ./fractol julia\033[0m <real_param> <imag_param>\n\n");
	exit(1);
}
