#include "MLX42/MLX42.h"
#include <stdlib.h>

unsigned int	create_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	color_image(mlx_image_t *img)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	color;

	x = 0;
	y = 0;

	color = create_color(255, 0,5,50);

	while (y < img->height)
	{
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
		x = 0;
	}
}

void	esc_key(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(mlx);
	}
	exit(0);
}

int	window(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(1920, 1080, "fract-ol", true);
	img = mlx_new_image(mlx, 2560, 1440);
	mlx_image_to_window(mlx, img, 0, 0);
	color_image(img);
	mlx_key_hook(mlx, &esc_key, mlx);
	// INTERRUPTS the program at the exact time the key is pressed
	// mlx_loop_hook();	// gets executed ONCE EVERY LOOP. no interrupt.1
	mlx_loop(mlx); // main loop
	return(0);
}