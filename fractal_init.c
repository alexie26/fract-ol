/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:55:42 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/15 19:11:48 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h" 

void	fractal_init(t_fractal *fractal, char **argv)
{
	fractal->max_iterations = 100;
	fractal->min_real = -2.0;
	fractal->max_real = 2.0;
	fractal->min_imag = -2.0;
	fractal->max_imag = 2.0;
	fractal->widht = 1920;
	fractal->height = 1080;
	
	// if (!ft_strncmp(fractal->name, "mandelbrot", 11))
	// {
	// 	fractal->center_real = -0.5;
	// }
	// else if (!ft_strncmp(fractal->name, "julia", 6))
	// {
	// 	printf("%s\n", argv[3]);
	// 	fractal->center_real = ft_atodbl(argv[2]);
	// 	fractal->center_real = ft_atodbl(argv[3]);
	// }
	if (fractal->type == 1)
		fractal->center_real = -0.5;
	else if (fractal->type == 2)
	{
		printf("%s\n", argv[3]);
		fractal->center_real = ft_atodbl(argv[2]);
		fractal->center_real = ft_atodbl(argv[3]);
	}
	else if (fractal->type == 3)
		exit (1);
	else
		exit (2);
}

