/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:15:45 by roalexan          #+#    #+#             */
/*   Updated: 2025/03/22 20:40:46 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int fractal_render(t_fractal *f)
{
    int x;
    int y;
    int i;
    unsigned int color;
    
    y = 0;
    while (y < f->height)
    {
        x = 0;
        while (x < f->widht)
        {
            f->x = f->min_x + x * (f->max_x - f->min_x) / f->widht + f->shift_x;
            f->y = f->min_y + y * (f->max_y - f->min_y) / f->height + f->shift_y;
            if (f->type == 1)
            {
                i = ft_mandelbrot(f);
            }
            else if (f->type == 2)
            {
                // For Julia, initialize z with the current pixel coordinates.
                f->z_x = f->x;
                f->z_y = f->y;
                i = ft_julia(f);
            }
            color = create_color((((i * 9) + f->col)) % 256, (((i * 24) + f->col)) % 256,
                                 (((i * 244) + f->col)) % 256, 255);
            mlx_put_pixel(f->img, x, y, color);
            x++;
        }
        y++;
    }
    return (0);
}

