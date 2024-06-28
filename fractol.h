#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_coridinate
{
    double x;
    double y;
} t_cordinate;


typedef struct s_img
{
    void	*img;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
}	t_img;

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    char    *name;
    t_img   img;
    int iter;
    double zoom;
    double shift_x;
    double shift_y;
}   t_mlx;

# define HEIGHT 800
# define WIDTH 800
# define RED   0xFF0000
# define GREEN 0x00FF00
# define BLUE  0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define escape 4



void        ft_hooks(t_mlx *fractol);
void        ft_setup(t_mlx *fractol);
void        ft_handle_pixel(int x, int y, t_mlx *fractol);
void        color_screen(t_mlx *fractol);
double      ft_scale(double pixel, double min, double max, int big);
int         ft_strncmp(char *s1, char *s2, int n);
void        ft_argument_error(void);
t_cordinate     ft_sum(t_cordinate z, t_cordinate c);
t_cordinate     ft_square(t_cordinate z);

#endif