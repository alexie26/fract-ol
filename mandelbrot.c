/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:58:45 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/21 17:16:42 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mandelbrot(t_fractal *f)
{
	double	zx_sqr;
	double	zy_sqr;
	int	i;

	i = 0;
	f->z_x = 0.0;
	f->z_y = 0.0;
	zx_sqr = 0;
	zy_sqr = 0;
	
	while (zx_sqr + zy_sqr <= 4 && i < f->max_iterations)
	{
		f->z_y = 2 * f->z_x * f->z_y + f->y;
		f->z_x = zx_sqr - zy_sqr + f->x;

		zx_sqr = f->z_x * f->z_x;
		zy_sqr = f->z_y * f->z_y;
		i++;
	}
	return (i);
}


// int	ft_mandelbrot(double real, double imag, int max_iter)
// {
// 	double z_real;
// 	double z_imag;
// 	double z_real_sqr;
// 	double z_imag_sqr;
// 	// t_pattern y;
// 	// t_pattern x;

	
// 	int	i;

// 	z_real = 0;
// 	z_imag = 0;
// 	z_real_sqr = 0;
// 	z_imag_sqr = 0;
// 	i = 0;

// 	while (z_real_sqr + z_imag_sqr <= 4.0 && i < max_iter)
// 	{
// 		z_imag = 2 * z_real * z_imag + imag;
// 		z_real = z_real_sqr - z_imag_sqr + real;

// 		z_real_sqr = z_real * z_real;
// 		z_imag_sqr = z_imag * z_imag;

// 		i++;
// 	}
// 	return (i);
// }
