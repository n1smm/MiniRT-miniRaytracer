/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:26:50 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 17:42:55 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	cap_hit(t_cylinder *cylinder, t_hitinfo *hit, POINT p, float t)
{
	hit->p = p;
	hit->t = t;
	hit->rgb = cylinder->rgb;
}

bool	caps_choose(t_cylinder *cylinder, t_caps *cp)
{
	if (cp->t2 > 0 && (cp->t <= 0 || cp->t > cp->t2))
	{
		cp->chosen_t = cp->t2;
		cp->normal = scale_vect(cylinder->dir, -1);
		cp->pcenter = cylinder->p2;
	}
	else if (cp->t > 0 && (cp->t2 <= 0 || cp->t2 > cp->t))
	{
		cp->chosen_t = cp->t;
		cp->pcenter = cylinder->p1;
		cp->normal = cylinder->dir;
	}
	else
		return (false);
	return (true);
}

bool	caps(t_ray camera_ray, t_cylinder *cylinder, t_hitinfo *hit)
{
	t_caps	cp;

	cp.visibility = dot_product(cylinder->dir, camera_ray.dir);
	cp.visibility2 = dot_product(scale_vect(cylinder->dir, -1), camera_ray.dir);
	if (cp.visibility <= 0 && cp.visibility2 <= 0)
		return (false);
	cp.t = dot_product(cylinder->dir, sub_vect(cylinder->p1, camera_ray.pos))
		/ cp.visibility;
	cp.t2 = dot_product(scale_vect(cylinder->dir, -1), sub_vect(cylinder->p2,
				camera_ray.pos)) / cp.visibility2;
	if (!caps_choose(cylinder, &cp))
		return (false);
	cp.p = sum_vect(camera_ray.pos, scale_vect(camera_ray.dir, cp.chosen_t));
	cp.pdelt = sub_vect(cp.p, cp.pcenter);
	if (magnitude(cp.pdelt) <= cylinder->radius && cp.chosen_t < hit->t)
	{
		hit->normal = cp.normal;
		cap_hit(cylinder, hit, cp.p, cp.chosen_t);
		cap_texture(hit, cylinder);
		cap_bump(hit, cylinder);
		return (true);
	}
	return (false);
}
