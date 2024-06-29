/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabidar <aabidar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:57:45 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/29 13:35:06 by aabidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_init(t_mlx *fractol, char **argv)
{
	fractol->iter = 60;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
	if (!ft_strcmp("Julia", fractol->name))
	{
		fractol->julia_x = atof(argv[2]);
		fractol->julia_y = atof(argv[3]);
	}
}

void	ft_fill(t_mlx *fractol)
{
	if (!ft_strcmp("Mandelbrot", fractol->name))
		color_screen(fractol);
	else if (!ft_strcmp("Julia", fractol->name))
		julia_render(fractol);
}

void	ft_setup(t_mlx *data, char **argv)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit(-1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img.img == NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	ft_hooks(data);
	ft_init(data, argv);
}

int	main(int argc, char **argv)
{
	t_mlx	fractal;

	if ((!ft_strcmp("Mandelbrot", argv[1]) && argc == 2) || (!ft_strcmp("Julia",
				argv[1]) && argc == 4))
	{
		fractal.name = argv[1];
		ft_setup(&fractal, argv);
		ft_fill(&fractal);
		mlx_loop(fractal.mlx);
	}
	ft_argument_error();
	return (0);
}
