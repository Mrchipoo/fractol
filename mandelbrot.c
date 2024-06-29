/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:07:12 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/29 14:51:32 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	int	pixel;

	pixel = ((y * img->line_len) + (x * (img->bpp / 8)));
	*((unsigned int *)(pixel + img->addr)) = color;
}

void	color_screen(t_mlx *fractol)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			color = ft_scale(x - y, GREEN, BLUE, fractol->iter);
			ft_handle_pixel(x, y, fractol, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}

void	ft_handle_pixel(int x, int y, t_mlx *fractol, int color)
{
	t_cordinate	z;
	t_cordinate	c;
	int			i;

	z.x = 0.0;
	i = 0;
	z.y = 0.0;
	c.x = (ft_scale(x, -2, +2, WIDTH) * fractol->zoom) + fractol->shift_x;
	c.y = (ft_scale(y, +2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
	while (i < fractol->iter)
	{
		z = ft_sqaure_sum(z, c);
		if (((z.x * z.x) + (z.y * z.y)) > 4)
		{
			color = ft_scale(i, TRANS, BLUE, fractol->iter);
			pixel_put(&fractol->img, x, y, color);
			return ;
		}
		i++;
	}
	pixel_put(&fractol->img, x, y, color);
}
