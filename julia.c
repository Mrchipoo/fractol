/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:05:32 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/29 14:08:12 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	julia_render(t_mlx *fractol)
{
	int			x;
	int			y;
	t_cordinate	c;

	c.x = fractol->julia_x;
	c.y = fractol->julia_y;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			ft_julia_pixel(c, x, y, fractol);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}

void	ft_julia_pixel(t_cordinate c, int x, int y, t_mlx *fractol)
{
	t_cordinate	z;
	t_cordinate	s;
	int			i;
	int			color;

	i = 0;
	z.y = (ft_scale(x, -2, +2, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.x = (ft_scale(y, +2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
	while (i < fractol->iter)
	{
		s.x = (z.x * z.x) - (z.y * z.y);
		s.y = 2 * z.x * z.y;
		z.x = s.x + c.x;
		z.y = s.y + c.y;
		if (((z.x * z.x) + (z.y * z.y)) > 4)
		{
			color = ft_scale(i, BACK, WHITE, fractol->iter);
			pixel_put(&fractol->img, x, y, color);
			return ;
		}
		i++;
	}
	pixel_put(&fractol->img, x, y, WHITE);
}
