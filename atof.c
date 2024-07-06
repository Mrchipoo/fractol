/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:09:40 by echoubby          #+#    #+#             */
/*   Updated: 2024/07/06 20:16:13 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_check(char *av, int i)
{
	while (av[i])
	{
		if (av[i] == '.' && ft_isdigit(av[i + 1]) && ft_isdigit(av[i - 1]))
			i++;
		else if (!ft_isdigit(av[i]))
		{
			ft_argument_error();
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	ft_isdigit(char n)
{
	if (n < 48 || n > 57)
		return (0);
	return (1);
}

double	ft_help_atof(char *av, int i)
{
	double	res;
	int		flag;
	int		j;

	j = 0;
	flag = 0;
	res = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]))
		{
			res = res * 10 +(av[i] - 48);
			if (flag == 1)
				--j;
		}
		else if (av[i] == '.' && ft_isdigit(av[i + 1]))
			flag = 1;
		i++;
	}
	res = res * pow(10, j);
	return (res);
}

double	ft_atof(char *av)
{
	double	res;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	while (av[i] && (av[i] == 32 || (av[i] >= 9 && av[i] <= 13)))
		i++;
	if (av[i] == '-' || av[i] == '+')
	{
		ft_check(av, i + 1);
		if (av[i] == '-')
			sign *= -1;
		i++;
	}
	ft_check(av, i);
	res = ft_help_atof(av, i);
	return (res * sign);
}
