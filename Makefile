CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = main.c string_utils.c math.c mandelbrot.c hooks.c julia.c atof.c
Header = fractol.h minilibx-linux/mlx.h
MLX= -lX11 -lXext -lm
OBJECT = $(SRC:.c=.o)
NAME = fractol


all:$(NAME)

$(NAME): $(OBJECT) $(fractol)
	$(CC) $(CFLAGS) $(OBJECT) $(MLX) -o $(NAME)
clean:
	rm -f $(OBJECT)
fclean:clean
	rm -f $(NAME)
re: fclean all