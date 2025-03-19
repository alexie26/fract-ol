/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:15:45 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/19 20:09:30 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_render(t_fractal *f)
{
	int				x;
	int				y;
	double			real;
	double			imag;
	int			i;
	unsigned int	color;
	y = 0;
	
	while (y < f->height)
	{
		x = 0;
		while (x < f->widht)
		{
			real = f->min_x + x * (f->max_x - f->min_x) / f->widht;
			imag = f->min_y + y * (f->max_y - f->min_y) / f->height;
			if (f->type == 1)
				i = ft_mandelbrot(real, imag, f->max_iterations);
			else if (f->type == 2)
				i = ft_julia(real, imag, f->julia_x, f->julia_y,
						f->max_iterations);
			color = create_color((((i * 9) + f->col)) % 256, (((i * 24) + f->col)) % 256, (((i * 244) + f->col))
					% 256, 255);
			mlx_put_pixel(f->img, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}
