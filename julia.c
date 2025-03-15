/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:58:17 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/15 18:37:55 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_julia(double real, double imag, double j_real, double j_imag, int max_i)
{
	double z_real;
	double z_imag;
	double z_real_sqr;
	double z_imag_sqr;
	double temp_real;
	int	i;

	z_real = real;
	z_imag = imag;
	z_real_sqr = z_real * z_real;
	z_imag_sqr = z_imag * z_imag;
	i = 0;
	
	while (z_real_sqr + z_imag_sqr <= 4.0 && i <= max_i)
	{
		temp_real = z_real_sqr - z_imag_sqr + j_real;
		z_imag = 2 * z_real + j_imag;
		z_real = z_real_sqr - z_imag_sqr + j_real;

		z_real_sqr = z_real * z_real;
		z_imag_sqr = z_imag * z_imag;
		// z_real_sqr = pow(z_real, 2);
		// z_imag_sqr = pow(z_imag, 2);

		i++;
	}
	return (i);
}
