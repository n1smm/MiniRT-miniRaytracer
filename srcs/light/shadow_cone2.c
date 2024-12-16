/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_cone2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:55:49 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/10 18:57:44 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	cone_end_shadow(t_hitinfo *hit, t_ray ray, t_cone *cone, POINT *res)
{
	t_vect	hypotenuse;
	t_vect	proj;
	t_vect	p_to_res;
	float	proj_len;

	ray = ray;
	hypotenuse = sub_vect(hit->p, cone->pos);
	proj = scale_vect(cone->dir, dot_product(hypotenuse, cone->dir));
	*res = sum_vect(cone->pos, proj);
	p_to_res = sub_vect(*res, cone->p2);
	proj_len = dot_product(p_to_res, cone->dir);
	if (proj_len >= 0 && proj_len <= cone->height)
		return (true);
	else
		return (false);
}

t_vect	cone_normal_shadow(t_hitinfo *hit, t_cone *cone)
{
	t_vect	normal;
	t_vect	pdelta;
	POINT	axisp;
	float	adjacent;
	float	scalar;

	pdelta = sub_vect(cone->pos, hit->p);
	adjacent = magnitude(pdelta);
	scalar = adjacent / cos(cone->theta_r);
	if (dot_product(cone->dir, pdelta) >= 0)
		pdelta = scale_vect(cone->dir, scalar);
	else
	{
		pdelta = scale_vect(cone->dir, scalar);
		pdelta = scale_vect(pdelta, -1);
	}
	axisp = sum_vect(cone->pos, pdelta);
	normal = normalize(sub_vect(hit->p, axisp));
	return (normal);
}
