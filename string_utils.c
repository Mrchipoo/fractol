#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s2 == NULL || *s2 == '\0')
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

void	ft_argument_error(void)
{
	ft_putendl_fd("arguments enterd are wrong\n", 2);
	ft_putendl_fd("Example : ./fractol Mandelbrot\n\n./fractol Julia 0.0 0.8\n",
		2);
	ft_putendl_fd("U can use + to increase iteration or - to decrease\n", 2);
	ft_putendl_fd("U can use arow keys to navigate the Set\n", 2);
	ft_putendl_fd("U can use mouse Wheel to zoom in or out", 2);
	exit(-1);
}