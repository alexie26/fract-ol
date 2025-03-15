/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:22:57 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/15 19:27:34 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	create_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	color_image(mlx_image_t *img)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	color;

	x = 0;
	y = 0;

	color = create_color(255, 0,5,50);

	while (y < img->height)
	{
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
		x = 0;
	}
}

void	esc_key(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(fractal->mlx);
		exit(0);
	}
}

int	window(t_fractal *fractal)
{
	fractal->mlx = mlx_init(1920, 1080, "fract-ol", true);
	fractal->img = mlx_new_image(fractal->mlx, 1920, 1080);
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	mlx_key_hook(fractal->mlx, &esc_key, fractal);
	// INTERRUPTS the program at the exact time the key is pressed
	// mlx_loop_hook();	// gets executed ONCE EVERY LOOP. no interrupt.1
	return(0);
}