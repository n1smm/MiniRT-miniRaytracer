/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:15:08 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 17:15:54 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vect	scale_vect(t_vect v, float scalar)
{
	t_vect	scaled;

	scaled.x = v.x * scalar;
	scaled.y = v.y * scalar;
	scaled.z = v.z * scalar;
	return (scaled);
}

t_vect	scale_down(t_vect v, float scalar)
{
	t_vect	scaled;

	scaled.x = v.x / scalar;
	scaled.y = v.y / scalar;
	scaled.z = v.z / scalar;
	return (scaled);
}

inline t_vect	create_vector(float x, float y, float z)
{
	t_vect	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_vect	reflect(t_vect in, t_vect normal)
{
	float	dot;
	t_vect	result;

	dot = dot_product(in, normal);
	result.x = in.x - 2.0f * dot * normal.x;
	result.y = in.y - 2.0f * dot * normal.y;
	result.z = in.z - 2.0f * dot * normal.z;
	return (result);
}

inline float	magnitude(t_vect v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
