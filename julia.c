/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:58:17 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/21 19:19:34 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_julia(t_fractal *f)
{
	t_complex c;

	int	i;

	i = 0;
	// f->z_x = 0.0;
	// f->z_y = 0.0;
	c.c_x = f->julia_x;
	c.c_y = f->julia_y;
	
	while (i <= f->max_iterations)
	{
		// f->z_y = 2 * f->z_x * f->z_y + zx_sqr; 
		// f->z_x = zx_sqr - zy_sqr + zy_sqr;
		f->z_x = ((f->z_x * f->z_x) - (f->z_y * f->z_y)) + ((f->z_x * f->z_x) - (f->z_y * f->z_y));
		f->z_y = ((2 * f->z_x * f->z_y) + (2 * f->z_x * f->z_y));
		if ((f->z_y * f->z_y) + (f->z_y * f->z_y) > 4)
			return (i);
		i++;
	}
	return (i);
}

// formula is Zn+1 = Z (2/n) + c  recursive formula
// real (Zn +1) = Real(Zn)ˆ2 - Imag(Zn)ˆ2 + Real(c)
// imag(Zn + 1) = 2 * Real(Zn) * Imag(Zn) + Imag(c)

