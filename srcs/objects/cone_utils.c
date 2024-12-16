/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:31:07 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/10 18:31:36 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	caps_hit(t_cone *cone, t_hitinfo *hit, POINT p, float t)
{
	hit->p = p;
	hit->t = t;
	hit->rgb = cone->rgb;
}

bool	caps_choose_cone(t_cone *cone, t_caps *c)
{
	if (c->t2 > 0 && (c->t <= 0 || c->t > c->t2))
	{
		c->chosen_t = c->t2;
		c->normal = scale_vect(cone->dir, -1);
		c->pcenter = cone->p2;
	}
	else if (c->t > 0 && (c->t2 <= 0 || c->t2 > c->t))
	{
		c->chosen_t = c->t;
		c->pcenter = cone->p1;
		c->normal = cone->dir;
	}
	else
		return (false);
	return (true);
}

bool	caps_cone(t_ray ray, t_cone *cone, t_hitinfo *hit)
{
	t_caps	c;

	c.visibility = dot_product(cone->dir, ray.dir);
	c.visibility2 = dot_product(scale_vect(cone->dir, -1), ray.dir);
	if (c.visibility <= 0 && c.visibility2 <= 0)
		return (false);
	c.t = dot_product(cone->dir, sub_vect(cone->p1, ray.pos)) / c.visibility;
	c.t2 = dot_product(scale_vect(cone->dir, -1), sub_vect(cone->p2, ray.pos))
		/ c.visibility2;
	if (!caps_choose_cone(cone, &c))
		return (false);
	c.p = sum_vect(ray.pos, scale_vect(ray.dir, c.chosen_t));
	c.pdelt = sub_vect(c.p, c.pcenter);
	if (magnitude(c.pdelt) <= cone->radius && c.chosen_t < hit->t)
	{
		hit->normal = c.normal;
		caps_hit(cone, hit, c.p, c.chosen_t);
		return (true);
	}
	return (false);
}
