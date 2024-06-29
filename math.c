/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:06:56 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/29 14:51:01 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

t_cordinate	ft_sqaure_sum(t_cordinate z, t_cordinate c)
{
	t_cordinate	result;
	t_cordinate	s;

	s.x = (z.x * z.x) - (z.y * z.y);
	s.y = 2 * z.x * z.y;
	result.x = s.x + c.x;
	result.y = s.y + c.y;
	return (result);
}

double	ft_scale(double pixel, double min, double max, int big)
{
	return (((max - min) * ((pixel - 0) / (big - 0))) + min);
}
