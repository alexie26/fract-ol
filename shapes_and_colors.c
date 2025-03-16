/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_and_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:22:57 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/16 20:15:49 by roalexan         ###   ########.fr       */
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
int	ft_max_iterations(t_fractal *fractal)
{
	int		max_iter;
	double	x_range;

	x_range = fractal->max_real - fractal->min_real;
	max_iter = 100 + 50 * (int)log2(2.0 / x_range);
	if (max_iter < 100)
		max_iter = 100;
	if (max_iter > 2000)
		max_iter = 2000;
	return (max_iter);
}
void	ft_zoom(t_fractal *fractal, double	zoom)
{
	int32_t	mouse_x;
	int32_t	mouse_y;
	double			mouse_cx;
	double			mouse_cy;

	mlx_get_mouse_pos(fractal->mlx, &mouse_x, &mouse_y);
	mouse_cx = fractal->min_real + (fractal->max_real - fractal->min_real) * (mouse_x / (double)WIDTH);
	mouse_cy = fractal->min_imag + (fractal->max_imag - fractal->min_imag) * (mouse_y / (double)WIDTH);
	fractal->min_real = mouse_cx - (mouse_cx - fractal->min_real) / zoom;
	fractal->max_real = mouse_cx + (fractal->max_real - mouse_cx) / zoom;
	fractal->min_imag = mouse_cy - (mouse_cy - fractal->min_imag) / zoom;
	fractal->max_imag = mouse_cy + (fractal->max_imag - mouse_cy) / zoom;
	color_image(fractal->img);
}
// esc key exit, zoom with + and -, change color when SPACE KEY is pressed
void	event_key(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractal->mlx);
	else if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		ft_zoom(fractal, 1.1);
	else if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		ft_zoom(fractal, 0.9);
	// else if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
	// 	ft_change_color(fractal);
	// else
	// 	mlx_terminate(fractal->mlx);
	// 	exit(0);
}
//handling mouse scroll, zooms and zoom out 
void	mouse_scroll(double xd, double yd, void *param)
{
	t_fractal *fractal;

	fractal = (t_fractal *)param;
	if (yd > 0)
		ft_zoom(fractal, 1.1);
	else if (yd < 0)
		ft_zoom(fractal, 0.9);
	// if (xd > 0)
	// 	write(1, "dcha\n", 5);
	// else if (xd < 0)
	// 	write (1, "izq\n", 4);
}


int	window(t_fractal *fractal)
{
	fractal->mlx = mlx_init(1920, 1080, "fract-ol", true);
	fractal->img = mlx_new_image(fractal->mlx, 1920, 1080);
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	mlx_key_hook(fractal->mlx, &event_key, fractal);
	// INTERRUPTS the program at the exact time the key is pressed
	// mlx_loop_hook();	// gets executed ONCE EVERY LOOP. no interrupt.1
	return (0);
}