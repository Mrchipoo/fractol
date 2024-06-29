#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

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

void ft_argument_error(void)
{
	ft_putendl_fd("arguments enterd are wrong", 2);
	exit(-1);
}