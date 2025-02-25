/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:10:51 by roalexan          #+#    #+#             */
/*   Updated: 2025/02/25 20:15:19 by roalexan         ###   ########.fr       */
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
        fractal.type = 1; // Mandelbrot
    }
    else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
    {
        fractal.name = argv[1];
        fractal.julia_x = ft_atodbl(argv[2]);
        fractal.julia_y = ft_atodbl(argv[3]);
        fractal_init(&fractal);
        fractal.type = 2; // Julia
    }
    else
    {
        ft_putstr_fd("Usage:\n", STDERR_FILENO);
        ft_putstr_fd(" ./fractol mandelbrot\n", STDERR_FILENO);
        ft_putstr_fd(" ./fractol julia <real_param> <imag_param>\n", STDERR_FILENO);
        return (EXIT_FAILURE);		
    }
    fractal_render(&fractal);
    mlx_key_hook(fractal.mlx, &esc_key, fractal.mlx);
    mlx_loop(fractal.mlx); // main loop
    return (EXIT_SUCCESS);
}

// int	main(int argc, char **argv)
// {
// 	t_fractal fractal;

// 	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
// 	{
// 		fractal.name = argv[1];
// 		fractal_init(&fractal);
// 	}
// 	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
// 	{
// 		fractal.name = argv[1];
// 		fractal.julia_x = ft_atodbl(argv[2]);
// 		fractal.julia_y = ft_atodbl(argv[3]);
// 		fractal_init(&fractal);
// 	}
// 	else
// 	{
// 		ft_putstr_fd("Usage:\n", STDERR_FILENO);
// 		ft_putstr_fd(" ./fractol mandelbrot\n", STDERR_FILENO);
// 		ft_putstr_fd(" ./fractol julia <real_param> <imag_param>\n", STDERR_FILENO);
// 		return (EXIT_FAILURE);		
// 	}
// 	if (fractal_render(&fractal) != 0)
// 		ft_putstr_fd("Error: Failed to render fractal\n", STDERR_FILENO);
// 		return(EXIT_FAILURE);
// 	return (EXIT_SUCCESS);
// }

