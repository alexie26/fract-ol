/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:54:48 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/22 21:13:57 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	  function(void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
	{
		f->shift_y -= 0.1;
		fractal_render(f);
	}
	else if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
	{
		f->shift_y += 0.1;
		fractal_render(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
	{
		f->shift_x -= 0.1;
		fractal_render(f);
	}
	else if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
	{
		f->shift_x += 0.1;
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
		f->col += 10;
		fractal_render(f);
	}
}
//mouse scroll 
void	mouse_scroll(double xd, double yd, void *param)
{
	t_fractal *f;
	double	zoom;
	(void)xd;
	f = (t_fractal *)param;
	if (yd > 0)
		zoom =  1.1;
	else if (yd < 0)
		zoom = 0.9;
	else
		return;
	ft_zoom(f, zoom);
	fractal_render(f);
}
