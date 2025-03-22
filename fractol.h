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


typedef struct s_fractal
{
	char		*name;
	//grapichs
	mlx_t		*mlx;
	mlx_image_t *img;

	//fractal prop
	int		max_iterations;
	double	zoom_factor;
	int		type;

	//coordinates
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;	
	double shift_y;
	double shift_x;

	//complex stufz
	double 	x;
	double	y;
	double 	z_x;
	double 	z_y;
	double	julia_x;
	double	julia_y;

	//display settings
	int		col;
	int		widht;
	int		height;
} t_fractal;

int	main(int argc, char **argv);
int		fractal_type(char **argv);

//shapes and colors and window 
	//colors
unsigned int	create_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void			color_image(mlx_image_t *img);

	//key handling
void			ft_zoom(t_fractal *f, double	zoom);
void			function(void *param);
void			event_key(void *param);
	//mouse handling
void			mouse_scroll(double xd, double yd, void *param);
	// window initialization
int				window(t_fractal *fractal);

//utils
double	ft_atodbl(char *s); //converts string into double 0.00etc

//fractals
int	ft_mandelbrot(t_fractal *f);
int ft_julia(t_fractal *f);
int	ft_tricorn(t_fractal *f);

//render & draw
int		 fractal_render(t_fractal *fractal);
//init
void	fractal_init(t_fractal *fractal, char **argv);



#endif