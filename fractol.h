/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:07:37 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/29 14:10:56 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_coridinate
{
	double	x;
	double	y;
}			t_cordinate;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	char	*name;
	t_img	img;
	int		iter;
	double	zoom;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
}			t_mlx;

# define HEIGHT 800
# define WIDTH 800
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define TRANS 0xEE46AA
# define BACK 0x29bdc1

void		ft_error(void);
void		ft_hooks(t_mlx *fractol);
void		ft_setup(t_mlx *fractol, char **argv);
void		ft_handle_pixel(int x, int y, t_mlx *fractol, int color);
void		color_screen(t_mlx *fractol);
double		ft_scale(double pixel, double min, double max, int big);
int			ft_strcmp(char *s1, char *s2);
void		ft_argument_error(void);
void		ft_julia_pixel(t_cordinate c, int x, int y, t_mlx *fractol);
void		julia_render(t_mlx *fractol);
void		pixel_put(t_img *img, int x, int y, int color);
void		ft_fill(t_mlx *fractol);
t_cordinate	ft_sqaure_sum(t_cordinate z, t_cordinate c);

#endif
