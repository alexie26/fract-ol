/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:58:45 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/16 19:13:07 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	mandelbrot(t_fractal *fractal)
// {
// 	int	i;
// 	double temp;
// 	int	max_iter;

// 	 i = 0;
// 	 max_iter = 
// }


int	ft_mandelbrot(double real, double imag, int max_iter)
{
	double z_real;
	double z_imag;
	double z_real_sqr;
	double z_imag_sqr;
	int	i;

	z_real = 0;
	z_imag = 0;
	z_real_sqr = 0;
	z_imag_sqr = 0;
	i = 0;

	while (z_real_sqr + z_imag_sqr <= 4.0 && i < max_iter)
	{
		z_imag = 2 * z_real * z_imag + imag;
		z_real = z_real_sqr - z_imag_sqr + real;

		z_real_sqr = z_real * z_real;
		z_imag_sqr = z_imag * z_imag;

		i++;
	}
	return (i);
}
