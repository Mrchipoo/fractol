CC = cc
CFLAGS= -Wall -Werror -Wextra -g3
SRC = main.c string_utils.c math.c render.c hooks.c julia.c
Header = fractol.h minilibx-linux/mlx.h
MLX = minilibx-linux/libmlx.a -Iminilibx-linux -lX11 -lXext
OBJECT = $(SRC:.c=.o)
NAME = fractol


all:$(NAME)

$(NAME): $(OBJECT) $(fractol)
	$(CC) $(CFLAGS) $(OBJECT) $(MLX) -g3 -o $(NAME)
clean:
	rm -f $(OBJECT)
fclean:clean
	rm -f $(NAME)
re: fclean all