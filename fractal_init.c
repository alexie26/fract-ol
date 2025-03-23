/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:55:42 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/23 21:18:54 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_defaults(t_fractal *f)
{
	if (!f)
		return ;
	f->max_iterations = 100;
	f->zoom_factor = 1.0;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->widht = 1000;
	f->height = 1000;
	f->col = 0;
	f->min_x = -2.0;
	f->max_x = 2.0;
	f->min_y = -2.0;
	f->max_y = 2.0;
	f->x = 0.0;
	f->y = 0.0;
	f->z_x = 0.0;
	f->z_y = 0.0;
	f->julia_x = 0.0;
	f->julia_x = 0.0;
}

void	fractal_init(t_fractal *f, char **argv)
{
	set_defaults(f);
	if (!f)
		return ;
	if (f->type == 1)
		f->x = -0.5;
	else if (f->type == 2)
	{
		if (!argv[2] || !argv[3] || !is_valid_number(argv[2])
			|| !is_valid_number(argv[3]))
		{
			ft_printf("Error: Invalid or missing Julia parameters\n");
			exit(2);
		}
		f->julia_x = ft_atodbl(argv[2]);
		f->julia_y = ft_atodbl(argv[3]);
	}
	else if (f->type == 3)
		f->x = -0.5;
	else
	{
		ft_printf("Error: Unknown fractal type\n");
		printf("%d\n", f->type);
		exit(2);
	}
}
