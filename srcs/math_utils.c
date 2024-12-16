/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:38:36 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/15 17:09:29 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include <math.h>

int	nb_atoi(t_data *data, const char *nptr)
{
	int	i;
	int	s;
	int	num;

	i = 0;
	s = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			data->not_number = true;
		num *= 10;
		num += (nptr[i] - 48);
		i++;
	}
	return (num * s);
}

inline int	square(float i)
{
	return (i * i);
}

double	ft_atol_sign(const char *nptr, int i, double s)
{
	double	num;
	double	num2;
	double	pos;

	num = 0;
	num2 = 0;
	pos = 1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num += (nptr[i] - 48);
		i++;
	}
	if (nptr[i] == '.')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num2 *= 10;
		num2 += (nptr[i] - 48);
		pos *= 10;
		i++;
	}
	return ((num + (num2 / pos)) * s);
}

double	ft_atol(const char *nptr)
{
	int		i;
	double	s;
	double	res;

	i = 0;
	s = 1;
	if (!(*nptr) || !nptr)
		return (0);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	res = ft_atol_sign(nptr, i, s);
	return (res);
}
