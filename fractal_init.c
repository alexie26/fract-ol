/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:55:42 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/19 19:55:51 by roalexan         ###   ########.fr       */
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
	fractal->widht = 1920;
	fractal->height = 1080;
	if (fractal->type == 1)
		fractal->x = -0.5;
	else if (fractal->type == 2)
	{
		fractal->x = ft_atodbl(argv[2]);
		fractal->x = ft_atodbl(argv[3]);
	}
	else if (fractal->type == 3)
		exit(1);
	else
		exit(2);
}
