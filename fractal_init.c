/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:55:42 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/22 20:37:16 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	fractal_init(t_fractal *fractal, char **argv)
{
	fractal->max_iterations = 100;
	fractal->min_x = -2.0;
	fractal->max_x = 2.0;
	fractal->min_y = -2.0;
	fractal->max_y = 2.0;
	fractal->widht = 1000;
	fractal->height = 1000;
	if (fractal->type == 1)
		fractal->x = -0.5;
	else if (fractal->type == 2) //TODO add check for argv 2 and 3, not number, not valid etc.
	{
		fractal->julia_x = ft_atodbl(argv[2]);
		fractal->julia_y = ft_atodbl(argv[3]);
	}
	else if (fractal->type == 3)
		exit(1);
	else
		exit(2);
}

// Updated fractal_init: Set fractal parameters only.
// void fractal_init(t_fractal *fractal, char **argv)
// {
//     fractal->max_iterations = 100;
//     fractal->min_x = -2.0;
//     fractal->max_x = 2.0;
//     fractal->min_y = -2.0;
//     fractal->max_y = 2.0;
//     fractal->widht = 1000;  // (Consider renaming to "width" for clarity)
//     fractal->height = 1000;
//     fractal->shift_x = 0.0;
//     fractal->shift_y = 0.0;
//     fractal->col = 0;  // default color offset

//     if (fractal->type == 1)  // Mandelbrot
//     {
//         // Mandelbrot specific initialization if needed
//     }
//     else if (fractal->type == 2)  // Julia
//     {
//         fractal->julia_x = ft_atodbl(argv[2]);
//         fractal->julia_y = ft_atodbl(argv[3]);
//     }
//     else
//     {
//         ft_putstr_fd("Invalid fractal type\n", STDERR_FILENO);
//         exit(EXIT_FAILURE);
//     }
// }

