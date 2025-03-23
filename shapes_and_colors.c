/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_and_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:22:57 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/23 20:06:15 by roalexan         ###   ########.fr       */
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
	color = create_color(255, 0, 5, 50);
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

void	ft_zoom(t_fractal *f, double zoom, double mouse_cy)
{
	int32_t	mouse_x;
	int32_t	mouse_y;
	double	mouse_cx;
	double	new_x_range;
	double	new_y_range;

	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	mouse_cx = f->min_x + (f->max_x - f->min_x) * (mouse_x / (double)f->widht);
	mouse_cy = f->min_y + (f->max_y - f->min_y) * (mouse_y / (double)f->height);
	new_x_range = (f->max_x - f->min_x) / zoom;
	new_y_range = (f->max_y - f->min_y) / zoom;
	f->min_x = mouse_cx - ((mouse_cx - f->min_x) / zoom);
	f->max_x = f->min_x + new_x_range;
	f->min_y = mouse_cy - ((mouse_cy - f->min_y) / zoom);
	f->max_y = f->min_y + new_y_range;
	fractal_render(f);
}

int	window(t_fractal *fractal)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	fractal->mlx = mlx_init(fractal->widht, fractal->height, "fract-ol", true);
	fractal->img = mlx_new_image(fractal->mlx, fractal->widht, fractal->height);
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	mlx_loop_hook(fractal->mlx, &event_key, fractal);
	mlx_scroll_hook(fractal->mlx, &mouse_scroll, fractal);
	return (0);
}
