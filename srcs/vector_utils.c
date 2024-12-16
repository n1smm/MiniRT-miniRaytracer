/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:25:00 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 17:15:55 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vect	sum_vect(t_vect pos_1, t_vect pos_2)
{
	t_vect	res;

	res.x = pos_1.x + pos_2.x;
	res.y = pos_1.y + pos_2.y;
	res.z = pos_1.z + pos_2.z;
	return (res);
}

t_vect	sub_vect(t_vect pos_1, t_vect pos_2)
{
	t_vect	res;

	res.x = pos_1.x - pos_2.x;
	res.y = pos_1.y - pos_2.y;
	res.z = pos_1.z - pos_2.z;
	return (res);
}

t_vect	normalize(t_vect v_orig)
{
	float	length;
	t_vect	res;

	length = sqrt(v_orig.x * v_orig.x + v_orig.y * v_orig.y + v_orig.z
			* v_orig.z);
	res.x = v_orig.x / length;
	res.y = v_orig.y / length;
	res.z = v_orig.z / length;
	return (res);
}

float	dot_product(t_vect pos_1, t_vect pos_2)
{
	return ((pos_1.x * pos_2.x) + (pos_1.y * pos_2.y) + (pos_1.z * pos_2.z));
}

t_vect	cross_product(t_vect a, t_vect b)
{
	t_vect	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}
