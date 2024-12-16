/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:54:51 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/10 18:16:12 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	cone_end(t_hitinfo *hit, t_ray ray, t_cone *cone, POINT *res)
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

t_vect	cone_normal(t_hitinfo *hit, t_cone *cone)
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
		pdelta = scale_vect(pdelta, 1);
	}
	axisp = sum_vect(cone->pos, pdelta);
	normal = normalize(sub_vect(hit->p, axisp));
	return (normal);
}

void	hit_cone(t_hitinfo *hit, float t, t_ray ray, t_cone *cone)
{
	float	prev_hit;
	POINT	prev;
	POINT	res;

	prev_hit = hit->t;
	prev = hit->p;
	if (t >= hit->t)
		return ;
	hit->t = t;
	hit->p = sum_vect(ray.pos, scale_vect(ray.dir, t));
	if (!cone_end(hit, ray, cone, &res))
	{
		hit->t = prev_hit;
		hit->p = prev;
		return ;
	}
	hit->rgb = cone->rgb;
	hit->normal = normalize(cone->pos);
	hit->normal = cone_normal(hit, cone);
}

void	cone_comps(t_ray ray, t_data *data, t_cone *cone, t_quad *g)
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

bool	render_cone(t_ray ray, t_data *data, t_cone *cone, t_hitinfo *hit)
{
	float	t1;
	float	t2;
	t_quad	g;

	cone_comps(ray, data, cone, &g);
	if (solve_quadratic(data, &t1, &t2))
	{
		if (t1 > 0.0001 && t1 < hit->t)
		{
			hit_cone(hit, t1, ray, cone);
		}
	}
	if (!caps_cone(ray, cone, hit))
	{
		t1 = FLT_MAX;
		hit_cone(hit, t1, ray, cone);
	}
	return (false);
}
