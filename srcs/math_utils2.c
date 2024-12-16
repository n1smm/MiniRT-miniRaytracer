/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:00:13 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 17:00:37 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include <math.h>

inline float	max_nb(float nb1, float nb2)
{
	if (nb1 >= nb2)
		return (nb1);
	return (nb2);
}

inline float	min_nb(float nb1, float nb2)
{
	if (nb1 <= nb2)
		return (nb1);
	return (nb2);
}

inline float	ratio(float nb1, float nb2)
{
	if (nb1 >= nb2)
		return (nb1 / nb2);
	return (nb2 / nb1);
}

inline void	swap(float *a, float *b)
{
	float	c;

	c = *a;
	*a = *b;
	*b = c;
}
