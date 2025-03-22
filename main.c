/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:18:05 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/22 20:28:06 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



int	fractal_type(char **argv)
{
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		return (1);
	else if (!ft_strncmp(argv[1], "julia", 6))
		return (2);
	else if (!ft_strncmp(argv[1], "tricorn", 8))
		return (3);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 5)) || (argc == 2
			&& !ft_strncmp(argv[1], "tricorn", 8)))
	{
		fractal->name = argv[1];
		fractal->type = fractal_type(argv);
		if (fractal->type == 0)
			return (0);
		fractal_init(fractal, argv);
	}
	else
	{
		ft_putstr_fd("Usage:\n ./fractol mandelbrot\n ./fractol julia <real_param> <imag_param>\n",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	window(fractal);
	fractal_render(fractal);
	mlx_loop(fractal->mlx); // main loop
	return (EXIT_SUCCESS);
}
