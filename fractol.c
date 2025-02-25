/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:10:51 by roalexan          #+#    #+#             */
/*   Updated: 2025/02/25 18:54:50 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractal *fractal)
{
	fractal->max_iterations = 100;
	fractal->min_real = -2.0;
	fractal->max_real = 2.0;
	fractal->min_imag = -2.0;
	fractal->max_imag = 2.0;

	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		fractal->center_real = -0.5;
	}
	else if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->center_real = 0.0;
		fractal->center_real = 0.0;
	}
}


int	main(int argc, char **argv)
{
	t_fractal fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		fractal.name = argv[1];
		fractal_init(&fractal);
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		fractal.name = argv[1];
		fractal.julia_x = ft_atodbl(argv[2]);
		fractal.julia_y = ft_atodbl(argv[3]);
		fractal_init(&fractal);
	}
	else
	{
		ft_putstr_fd("Usage:\n", STDERR_FILENO);
		ft_putstr_fd(" ./fractol mandelbrot\n", STDERR_FILENO);
		ft_putstr_fd(" ./fractol julia <real_param> <imag_param>\n", STDERR_FILENO);
		return (EXIT_FAILURE);		
	}
	if (fractal_render(&fractal) != 0)
	{
		ft_putstr_fd("Error: Failed to render fractal\n", STDERR_FILENO);
		return(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// // mlx_mouse_hook;
// // mlx_scroll_hook;


static mlx_image_t* image;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t main(void)
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}