/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:18:05 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/14 17:25:23 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// mlx_t	*mlx;
// mlx_image_t *img;

int	fractal_type(char **argv)
{
	if (ft_strncmp(argv[1], "Mandelbrot", 11))
		return (1);
	if (ft_strncmp(argv[1], "Julia", 6))
		return (2);
	if (ft_strncmp(argv[1], "fractal", 8))
		return (3);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) ||
		(argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
		{
			fractal.name = argv[1];
			fractal.type = fractal_type(argv);
			if (fractal.type == 0)
			return (0);
			fractal_init(&fractal, argv);
		}
		else
		{
			ft_putstr_fd("Usage:\n ./fractol mandelbrot\n ./fractol julia <real_param> <imag_param>\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		fractal.mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
		if (!fractal.mlx)
			return (0);
		fractal.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
		mlx_image_to_window(fractal.mlx, fractal.img, 0, 0);
		fractal_render(&fractal);
		mlx_key_hook(fractal.mlx, &esc_key, fractal.mlx);
		mlx_loop(fractal.mlx);
		return (EXIT_SUCCESS);
}
