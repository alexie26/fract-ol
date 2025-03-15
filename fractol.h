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
	int		widht;
	int		height;
} t_fractal;

double	ft_atodbl(char *s); //converts string into double 0.00etc


unsigned int	create_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void	color_image(mlx_image_t *img);
void	esc_key(mlx_key_data_t keydata, void *param);
int		window(t_fractal *fractal);

int	main(int argc, char **argv);
//render
int	ft_mandelbrot(double real, double imag, int max_iter);
int ft_julia(double real, double imag, double j_real, double j_imag, int max_i);
void fractal_render(t_fractal *fractal);

void	fractal_init(t_fractal *fractal, char **argv);
int	fractal_type(char **argv);


#endif