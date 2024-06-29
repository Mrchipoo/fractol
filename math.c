#include "fractol.h"

t_cordinate	ft_sum(t_cordinate z, t_cordinate c)
{
	t_cordinate	result;

	result.x = z.x + c.x;
	result.y = z.y + c.y;
	return (result);
}

t_cordinate	ft_square(t_cordinate z)
{
	t_cordinate	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

double	ft_scale(double pixel, double min, double max, int big)
{
	return (((max - min) * ((pixel - 0) / (big - 0))) + min);
}