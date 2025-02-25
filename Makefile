NAME = fractol

SRCS_DIR = srcs/
USER = $(shell whoami)
OS = $(shell uname)

SRCS =	fractol.c

COMPILER = cc
OBJS_DIR = objs/

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

all: MLX42 $(NAME)

$(NAME): $(OBJS)
	@$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS) ./MLX42/build/libmlx42.a $(MLX_FLAGS)

MLX42:
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && cmake -B build && cmake --build build -j4

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -rf MLX42
	@rm -f $(NAME)

mlxclean:
	@rm -rf MLX42

re: fclean all

.PHONY: all clean fclean re