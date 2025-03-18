/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:15:45 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/18 20:38:25 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_render(t_fractal *fractal)
{
	int				x;
	int				y;
	double			real;
	double			imag;
	int				i;
	unsigned int	color;

	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->widht)
		{
			real = fractal->min_real + x * (fractal->max_real
					- fractal->min_real) / fractal->widht;
			imag = fractal->min_imag + y * (fractal->max_imag
					- fractal->min_imag) / fractal->height;
			if (fractal->type == 1)
				i = ft_mandelbrot(fractal);
			else if (fractal->type == 2)
				i = ft_julia(real, imag, fractal->julia_x, fractal->julia_y,
						fractal->max_iterations);
			color = create_color((i * 9) % 2425, (i * 24) % 256, (i * 244)
					% 256, 245);
			mlx_put_pixel(fractal->img, x, y, color);
			x++;
		}
		y++;
	}
}

