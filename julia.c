#include "fractol.h"

void julia_render(t_mlx *fractol)
{
    int x;
    int y;
    t_cordinate c;

    c.x = fractol->julia_x;
    c.y = fractol->julia_y;
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            ft_julia_pixel(c, x, y, fractol);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}

void    ft_julia_pixel(t_cordinate c, int x, int y, t_mlx *fractol)
{
    t_cordinate z;
    t_cordinate s;
    int i;
    int color;

    i = 0;
    z.x = (ft_scale(x, -2, +2, WIDTH) * fractol->zoom) + fractol->shift_x;
    z.y = (ft_scale(y, +2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
    while (i < fractol->iter)
    {
        s.x = (z.x * z.x) - (z.y * z.y);;
        s.y = 2 * z.x * z.y;
        z.x = s.x + c.x;
        z.y = s.y + c.y;
        if (((z.x * z.x) + (z.y * z.y)) > 4)
        {
            color = ft_scale(i,BLACK, WHITE, fractol->iter);
            pixel_put(&fractol->img, x, y, color);
            return ;
        }
        i++;
    }
    pixel_put(&fractol->img, x, y, WHITE);
}