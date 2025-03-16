#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# define WIDTH 1920
# define HEIGHT 1080
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define GOLD 0xFFD700FF

typedef struct s_complex
{
	double x; //real
	double y; // 
}	t_complex;

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

	double 	x;
	double	y;
	
    double	zoom_factor;
    double	center_real;
    double	center_imag;

    double	julia_x;
    double	julia_y;
    int		type;
	int		widht;
	int		height;
} t_fractal;

//shapes and colors and window etc
int				ft_max_iterations(t_fractal *fractal);
void			ft_zoom(t_fractal *fractal, double	zoom);
int				ft_max_iterations(t_fractal *fractal);
unsigned int	create_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void			color_image(mlx_image_t *img);
void			event_key(mlx_key_data_t keydata, void *param);
int				window(t_fractal *fractal);
void			mouse_scroll(double xd, double yd, void *param);

double	ft_atodbl(char *s); //converts string into double 0.00etc



int	main(int argc, char **argv);


int	ft_mandelbrot(double real, double imag, int max_iter);
int ft_julia(double real, double imag, double j_real, double j_imag, int max_i);
void fractal_render(t_fractal *fractal);

void	fractal_init(t_fractal *fractal, char **argv);
int	fractal_type(char **argv);


#endif