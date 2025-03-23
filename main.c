/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:18:05 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/23 20:10:43 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_type(char **argv)
{
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		return (1);
	else if (!ft_strncmp(argv[1], "julia", 5))
		return (2);
	else if (!ft_strncmp(argv[1], "tricorn", 8))
		return (3);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*f;

	f = malloc(sizeof(t_fractal));
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 5)) || (argc == 2
			&& !ft_strncmp(argv[1], "tricorn", 8)))
	{
		f->name = argv[1];
		f->type = fractal_type(argv);
		if (f->type == 0)
			return (0);
		fractal_init(f, argv);
	}
	else
	{
		info_message();
	}
	window(f);
	fractal_render(f);
	mlx_loop(f->mlx);
	return (EXIT_SUCCESS);
}
