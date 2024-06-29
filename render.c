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

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_handle_pixel(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}

void	ft_handle_pixel(int x, int y, t_mlx *fractol)
{
	t_cordinate z;
	t_cordinate s;
	t_cordinate c;
	int i;
	int color;

	z.x = 0.0;
	i = 0;
	z.y = 0.0;
	c.x = (ft_scale(x, -2, +2, WIDTH) * fractol->zoom) + fractol->shift_x;
	c.y = (ft_scale(y, +2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
	while (i < fractol->iter)
	{
		s.x = (z.x * z.x) - (z.y * z.y);
		;
		s.y = 2 * z.x * z.y;
		z.x = s.x + c.x;
		z.y = s.y + c.y;
		if (((z.x * z.x) + (z.y * z.y)) > 4)
		{
			color = ft_scale(i, BLACK, WHITE, fractol->iter);
			pixel_put(&fractol->img, x, y, color);
			return ;
		}
		i++;
	}
	pixel_put(&fractol->img, x, y, WHITE);
}