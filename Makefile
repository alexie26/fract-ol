NAME = fractol

USER = $(shell whoami)
OS = $(shell uname)

SRCS =	utils.c	\
			main.c		\
			fractal_init.c		\
			fractal_render.c	\
			shapes_and_colors.c	\
			fractals.c 			\
			keyboard_mouse.c 	\

COMPILER = cc
OBJS_DIR = objs/

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

all: MLX42 $(NAME)

$(NAME): $(OBJS)
	@make -C libft --silent
	@make -C ft_printf --silent
	@$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS) ./MLX42/build/libmlx42.a libft/libft.a ft_printf/libftprintf.a $(MLX_FLAGS)

MLX42:
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && cmake -B build -DDEBUG=1 && cmake --build build -j4

clean:
	@rm -f $(OBJS)
	@cd ft_printf && make fclean && cd ..
	@cd libft && make fclean && cd ..

fclean: clean
	@rm -rf MLX42
	@rm -f $(NAME)

mlxclean:
	@rm -rf MLX42

re: fclean all

.PHONY: all clean fclean re