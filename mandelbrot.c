/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:58:45 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/19 19:55:05 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	ft_mandelbrot(t_fractal *fractal)
// {
// 	int	i;
// 	double temp;
// 	int	max_iter;
	

// 	 i = 0;
// 	max_iter = ft_max_iterations(fractal);
// 	fractal->i_real = 0.0;
// 	fractal->i_imag = 0.0;
// 	fractal->c_real = fractal->min_real + (fractal->max_real - fractal->min_real) * ((double)fractal->real / WIDTH);
// 	fractal->c_imag = fractal->min_imag + (fractal->min_imag - fractal->min_imag) * ((double)fractal->imag / HEIGHT);
// 	while (++i < max_iter)
// 	{
// 		if (fractal->i_real * fractal->i_real + fractal->i_imag * fractal->i_imag > 4.0)
// 				break ;
// 		temp = fractal->i_real * fractal->i_real - fractal->i_imag * fractal->i_imag + fractal->c_real;
// 		fractal->i_imag = 2.0 * fractal->i_real * fractal->i_imag + fractal->c_imag;
// 		fractal->i_imag = temp;
// 	}
// 	if (i == max_iter)
// 		mlx_put_pixel(fractal->img, fractal->real, fractal->imag, 0x000000);
// }


int	ft_mandelbrot(double real, double imag, int max_iter)
{
	double z_real;
	double z_imag;
	double z_real_sqr;
	double z_imag_sqr;
	// t_pattern y;
	// t_pattern x;

	
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
