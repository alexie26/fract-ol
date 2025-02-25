/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:07:23 by roalexan          #+#    #+#             */
/*   Updated: 2025/02/25 19:58:27 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int ft_julia(double real, double imag, double j_real, double j_imag, int max_i)
{
	double z_real;
	double z_imag;
	double z_real_sqr;
	double z_imag_sqr;
	int	i;

	z_real = real;
	z_imag = imag;
	z_real_sqr = z_real * z_real;
	z_imag_sqr = z_imag * z_imag;
	i = 0;
	
	while (z_real_sqr + z_imag_sqr <= 4.0 && i <= max_i)
	{
		z_imag = 2 * z_real + j_imag;
		z_real = z_real_sqr - z_imag_sqr + j_real;

		z_real_sqr = z_real * z_real;
		z_imag_sqr = z_imag * z_imag;

		i++;
	}
	return (i);
}

void fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;
	double real;
	double imag;
	int i;
	unsigned int color;

	y= 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = fractal->min_real + x * (fractal->max_real - fractal->min_real) / WIDTH;
			imag = fractal->min_imag + y * (fractal->max_imag - fractal->min_imag) / HEIGHT;
			if (fractal->type == 1)
				i = ft_mandelbrot(real, imag, fractal->max_iterations);
			else if (fractal->type == 2)
				i = ft_julia(real, imag, fractal->julia_x, fractal->julia_y, fractal->max_iterations);
			color = create_color((i * 9) % 256, (i * 2) % 256, (i * 3) % 256, 255);
			mlx_put_pixel(fractal->img, x, y, color);
			x++; 
		}
		y++;
	}
}

