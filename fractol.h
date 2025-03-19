#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define WIDTH 1920
# define HEIGHT 1080
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define GOLD 0xFFD700FF

typedef	struct s_pattern
{
	char *name;
	double	c_x;
	double	c_y;
}	t_pattern;

typedef struct s_fractal
{
	char		*name;

	mlx_t		*mlx;
	mlx_image_t *img;

	int		max_iterations;
	
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;

	double 	x;
	double	y;

	double 	i_x;
	double 	i_r;

	double	zoom_factor;
	
	int		col;
	double	julia_x;
	double	julia_y;
	int		type;
	int		widht;
	int		height;
} t_fractal;

//shapes and colors and window etc
int				ft_max_iterations(t_fractal *f);
void			ft_zoom(t_fractal *f, double	zoom);
int				ft_max_iterations(t_fractal *f);
unsigned int	create_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void			color_image(mlx_image_t *img);
void			event_key(void *param);
int				window(t_fractal *fractal);
void			mouse_scroll(double xd, double yd, void *param);
void 			boundries(t_fractal *fractal);
void			arrow_keys(mlx_key_data_t keydata, void *param);

double	ft_atodbl(char *s); //converts string into double 0.00etc



int	main(int argc, char **argv);


int	ft_mandelbrot(double real, double imag, int max_iter);
// void	ft_mandelbrot(t_fractal *fractal);
int ft_julia(double real, double imag, double j_real, double j_imag, int max_i);
int		 fractal_render(t_fractal *fractal);

void	fractal_init(t_fractal *fractal, char **argv);
int	fractal_type(char **argv);


#endif