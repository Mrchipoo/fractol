#include "fractol.h"

void ft_init(t_mlx *fractol)
{
    fractol->iter = 60;
    fractol->shift_x = 0.0;
    fractol->shift_y = 0.0;
    fractol->zoom = 1.0;
}

void ft_fill(t_mlx *fractol, char **argv)
{
    if (!ft_strncmp("mandelbort", argv[1], 10))
        color_screen(fractol);
    else if (!ft_strncmp("julia", argv[1], 5))
        julia_render(fractol, argv);
}

void    ft_setup(t_mlx *fractol)
{
    fractol->mlx = mlx_init();
    if (fractol->mlx == NULL)
        exit(-1);
    fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, fractol->name);
    if (fractol->win == NULL)
    {
        mlx_destroy_display(fractol->mlx);
        free(fractol->mlx);
    }
    fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
    if (fractol->img.img == NULL)
    {
        mlx_destroy_window(fractol->mlx, fractol->win);
        mlx_destroy_display(fractol->mlx);
        free(fractol->mlx);
    }
    fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bpp, &fractol->img.line_len, &fractol->img.endian);
    ft_hooks(fractol);
    ft_init(fractol);
}

int main(int argc, char **argv)
{
    t_mlx     fractal;

    if ((!ft_strncmp("mandelbort", argv[1], 10) && argc == 2)
        || (!ft_strncmp("julia", argv[1], 5) && argc == 4))
    {
        fractal.name = argv[1];
        ft_setup(&fractal);
        ft_fill(&fractal, argv);
        mlx_loop(fractal.mlx);
    }
    ft_argument_error();
    return (0);
}
