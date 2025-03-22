/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:43:24 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/22 20:50:43 by roalexan         ###   ########.fr       */
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

int ft_julia(t_fractal *f)
{
    int n;
    double tmp;  // temporary variable to store the old z_x value

    n = 0;
    while (n < f->max_iterations)
    {
        if ((f->z_x * f->z_x + f->z_y * f->z_y) > 4.0)
            break;
        tmp = f->z_x;  // store current z_x
        f->z_x = f->z_x * f->z_x - f->z_y * f->z_y + f->julia_x;
        f->z_y = 2 * tmp * f->z_y + f->julia_y;
        n++;
    }
    return (n);
}
int ft_tricorn(t_fractal *f)
{
    int n;
    double zr;
    double zi;
    double tmp;

    zr = 0;
    zi = 0;
    n = 0;
    while (n < f->max_iterations)
    {
        if ((zr * zr + zi * zi) > 4.0)
            break;
        tmp = -2 * zr * zi + f->y;    // f->y is the imaginary part of c
        zr = zr * zr - zi * zi + f->x;  // f->x is the real part of c
        zi = tmp;
        n++;
    }
    return (n);
}