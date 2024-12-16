/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:04:12 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/10 19:07:35 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	hit_cone_shadow(t_hitinfo *hit, float t, t_ray ray, t_cone *cone)
{
	float	prev_hit;
	POINT	prev;
	POINT	res;

	prev_hit = hit->t;
	prev = hit->p;
	if (t >= hit->t)
		return (false);
	hit->t = t;
	hit->p = sum_vect(ray.pos, scale_vect(ray.dir, t));
	if (!cone_end_shadow(hit, ray, cone, &res))
	{
		hit->t = prev_hit;
		hit->p = prev;
		return (true);
	}
	hit->rgb = cone->rgb;
	hit->normal = normalize(cone->pos);
	return (false);
}

void	cone_comps_shadow(t_ray ray, t_data *data, t_cone *cone, t_quad *g)
{
	g->pdelt = sub_vect(ray.pos, cone->pos);
	g->cos_square = cos(cone->theta_r) * cos(cone->theta_r);
	g->sin_square = sin(cone->theta_r) * sin(cone->theta_r);
	g->acomp = sub_vect(ray.dir, scale_vect(cone->dir, dot_product(ray.dir,
					cone->dir)));
	g->acomp2 = g->sin_square * dot_product(ray.dir, cone->dir)
		* dot_product(ray.dir, cone->dir);
	data->a = g->cos_square * dot_product(g->acomp, g->acomp) - g->acomp2;
	g->bcomp = dot_product(sub_vect(ray.dir, scale_vect(cone->dir,
					dot_product(ray.dir, cone->dir))), sub_vect(g->pdelt,
				scale_vect(cone->dir, dot_product(g->pdelt, cone->dir))));
	g->bcomp2 = dot_product(ray.dir, cone->dir) * dot_product(g->pdelt,
			cone->dir);
	data->b = (2 * g->cos_square * g->bcomp) - (2 * g->sin_square * g->bcomp2);
	g->ccomp = dot_product(sub_vect(g->pdelt, scale_vect(cone->dir,
					dot_product(g->pdelt, cone->dir))), sub_vect(g->pdelt,
				scale_vect(cone->dir, dot_product(g->pdelt, cone->dir))));
	g->ccomp2 = g->sin_square * dot_product(g->pdelt, cone->dir)
		* dot_product(g->pdelt, cone->dir);
	data->c = g->cos_square * g->ccomp - g->ccomp2;
}

bool	check_caps_shad(t_hitinfo *hit, t_cone *cone, t_ray ray, float t1)
{
	if (caps_cone(ray, cone, hit))
	{
		t1 = FLT_MAX;
		hit_cone_shadow(hit, t1, ray, cone);
		hit_cone_shadow(hit, t1, ray, cone);
		return (true);
	}
	return (false);
}

bool	render_cone_shadow(t_ray ray, t_data *data, t_cone *cone,
		t_hitinfo *hit)
{
	float	t1;
	float	t2;
	t_quad	g;

	cone_comps_shadow(ray, data, cone, &g);
	if (solve_quadratic(data, &t1, &t2))
	{
		if (t1 > 0.0003 && t1 < hit->t && (!hit_cone_shadow(hit, t1, ray,
					cone)))
			return (true);
		else if (t2 > 0.0003 && t2 < hit->t && (!hit_cone_shadow(hit, t2, ray,
					cone)))
			return (true);
	}
	if (check_caps_shad(hit, cone, ray, t1))
		return (true);
	return (false);
}
