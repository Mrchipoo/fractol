#include "fractol.h"

int ft_close(t_mlx *fractol)
{
    mlx_destroy_image(fractol->mlx, fractol->img.img);
    mlx_destroy_window(fractol->mlx, fractol->win);
    mlx_destroy_display(fractol->mlx);
    free(fractol->mlx);
    exit(EXIT_SUCCESS);
    return(EXIT_SUCCESS);
}

int ft_key_hook(int keycode, t_mlx *fractol)
{
    if (keycode == 65307)
        ft_close(fractol);
    if (keycode == 65362)//up
        fractol->shift_y -= (0.5 * fractol->zoom);
    else if (keycode == 65364)//down
        fractol->shift_y += (0.5 * fractol->zoom);
    else if (keycode == 65361)//left
        fractol->shift_x += (0.5 * fractol->zoom);
    else if (keycode == 65363)//right
        fractol->shift_x -= (0.5 * fractol->zoom);
    else if (keycode == 45)
        fractol->iter -= 10;
    else if (keycode == 61)
        fractol->iter += 10;
    ft_fill(fractol);
    return (0);
}

int ft_mouse_hook(int keycode, int x, int y, t_mlx *fractol)
{
    (void)x;
    (void)y;
    if (keycode == 4)
        fractol->zoom = fractol->zoom * 1.1;
    else if (keycode == 5)
        fractol->zoom = fractol->zoom * 0.9;
    ft_fill(fractol);
    return (0);
}

void ft_hooks(t_mlx *fractol)
{
    mlx_key_hook(fractol->win, ft_key_hook, fractol);
    mlx_hook(fractol->win, ButtonPress , ButtonPressMask, ft_mouse_hook, fractol);
    mlx_hook(fractol->win, DestroyNotify, StructureNotifyMask, ft_close, fractol);
}