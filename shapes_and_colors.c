/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_and_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:22:57 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/19 20:10:08 by roalexan         ###   ########.fr       */
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
// calculates the max num of iterations for each point in the fractal. For fractal rendering and zoom 
// max_real and min_real are for limits on the real axis (x)
// x_range for 
// int	ft_max_iterations(t_fractal *fractal)
// {
// 	int		max_iter;
// 	double	x_range;

// 	x_range = fractal->max_real - fractal->min_real;
// 	max_iter = 100 + 50 * (int)log2(2.0 / x_range);
// 	if (max_iter < 100)
// 		max_iter = 100;
// 	if (max_iter > 2000)
// 		max_iter = 2000;
// 	return (max_iter);
// }


void	ft_zoom(t_fractal *f, double	zoom)
{
	int32_t	mouse_x;
	int32_t	mouse_y;
	double			mouse_cx;
	double			mouse_cy;

	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	mouse_cx = f->min_x + (f->max_x - f->min_x) * (mouse_x / (double)WIDTH);
	mouse_cy = f->min_y + (f->max_y - f->min_y) * (mouse_y / (double)WIDTH);
	f->min_x = mouse_cx - (mouse_cx - f->min_x) / zoom;
	f->max_x = mouse_cx + (f->max_x - mouse_cx) / zoom;
	f->min_y = mouse_cy - (mouse_cy - f->min_y) / zoom;
	f->max_y = mouse_cy + (f->max_y - mouse_cy) / zoom;
	f->col = 1;
	fractal_render(f);
	// color_image(fractal->img);
}
// esc key exit, zoom with + and -, change color when SPACE KEY is pressed

void	function(void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
	{
		f->y -= 0.1 * f->zoom_factor;
		fractal_render(f);
	}
	else if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
	{
		f->y += 0.1 * f->zoom_factor;
		fractal_render(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
	{
		f->x -= 0.1 * f->zoom_factor;
		fractal_render(f);
	}
	else if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
	{
		f->x += 0.1 * f->zoom_factor;
		fractal_render(f);
	}
}
void	event_key(void *param)
{
	function(param);
	t_fractal	*f;

	f = (t_fractal *)param;

	if (mlx_is_key_down(f->mlx, MLX_KEY_KP_ADD))
	{
		f->max_iterations += 10;
		fractal_render(f);
	}
	else if (mlx_is_key_down(f->mlx, MLX_KEY_KP_SUBTRACT))
	{
		f->max_iterations -= 10;
		fractal_render(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_SPACE))
	{
		f->col++;
		fractal_render(f);
	}
}
//handling mouse scroll, zooms and zoom out 
void	mouse_scroll(double xd, double yd, void *param)
{
	t_fractal *f;

	(void)xd;
	f = (t_fractal *)param;
	if (yd > 0)
		ft_zoom(f, 1.1);
	else if (yd < 0)
		ft_zoom(f, 0.9);
	fractal_render(f);
}

int	window(t_fractal *fractal)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	fractal->mlx = mlx_init(1920, 1080, "fract-ol", true);
	fractal->img = mlx_new_image(fractal->mlx, 1920, 1080);
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	mlx_loop_hook(fractal->mlx, &event_key, fractal);
	mlx_scroll_hook(fractal->mlx, &mouse_scroll, fractal);
	// INTERRUPTS the program at the exact time the key is pressed
	// mlx_loop_hook(fractal->mlx, &my_loop,fractal);	// gets executed ONCE EVERY LOOP. no interrupt.1
	return (0);
}