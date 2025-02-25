/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:00:59 by roalexan          #+#    #+#             */
/*   Updated: 2025/02/25 18:49:40 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# define WIDTH 800
# define HEIGHT 600

typedef struct s_mandelbrot
{
    char	*name;

    mlx_t	*mlx;
    mlx_image_t	*img;

    int	max_iterations;
    double min_real;
    double max_real;
    double min_imag;
    double max_imag;

    int	color_scheme;
    int	color_shift;

    double	zoom_factor;
    double	center_real;
    double	center_imag;
} t_mandelbrot;

typedef	struct s_julia
{
    char *name;
    
    double	julia_x;
    double	julia_y;

    mlx_t	*mlx;
    mlx_image_t	*img;

    int		max_iterations;
    double	min_real;
    double	max_real;
    double	min_imag;
    double	max_imag;
    
    int	color_scheme;
    int	color_shift;

    double	zoom_factor;
    double	center_real;
    double	center_imag;
} t_julia;

typedef struct s_fractal_type
{
    t_julia		*julia;
    t_mandelbrot *mandelbrot;
} t_fractal_type;

typedef struct s_fractal
{
    char	*name;
    
    mlx_t	*mlx;
    mlx_image_t *img;

    int		max_iterations;
    double	min_real;
    double	max_real;
    double	min_imag;
    double	max_imag;
    
    int	color_scheme;
    int	color_shift;

    double	zoom_factor;
    double	center_real;
    double	center_imag;

    double	julia_x;
    double	julia_y;
    int		type;
} t_fractal;

double	ft_atodbl(char *s);

void	esc_key(mlx_key_data_t keydata, void *param);

#endif