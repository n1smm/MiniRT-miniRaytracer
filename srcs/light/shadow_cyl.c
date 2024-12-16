/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_cyl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:37:40 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/10 18:37:41 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <stdbool.h>

static bool	caps_intersect(t_data *data, t_cylinder *cylinder, \
	t_vect *normal, t_hitinfo *hit)
{
	if (data->t2 > 0 && (data->t1 <= 0 || data->t1 > data->t2))
	{
		data->chosen_t = data->t2;
		*normal = scale_vect(cylinder->dir, -1);
		data->pcenter = cylinder->p2;
	}
	else if (data->t1 > 0 && (data->t2 <= 0 || data->t2 > data->t1))
	{
		data->chosen_t = data->t1;
		data->pcenter = cylinder->p1;
		*normal = cylinder->dir;
	}
	else
		return (false);
	if (data->chosen_t > hit->t)
		return (false);
	return (true);
}

static bool	caps_2(t_ray ray, t_data *data, t_cylinder *cyl, t_hitinfo *hit)
{
	POINT	p;
	t_vect	pdelt;
	t_vect	normal;

	data->vis1 = dot_product(cyl->dir, ray.dir);
	data->vis2 = dot_product(scale_vect(cyl->dir, -1), ray.dir);
	if (data->vis1 <= 0 && data->vis2 <= 0)
		return (false);
	data->t1 = dot_product(cyl->dir, sub_vect(cyl->p1, ray.pos)) / data->vis1;
	data->t2 = dot_product(scale_vect(cyl->dir, -1), \
		sub_vect(cyl->p2, ray.pos)) / data->vis2;
	if (!caps_intersect(data, cyl, &normal, hit))
		return (false);
	p = sum_vect(ray.pos, scale_vect(ray.dir, data->chosen_t));
	pdelt = sub_vect(p, data->pcenter);
	if (magnitude(pdelt) <= cyl->radius && data->chosen_t < hit->t)
	{
		hit->normal = normal;
		cap_hit(cyl, hit, p, data->chosen_t);
		cap_texture(hit, cyl);
		cap_bump(hit, cyl);
		return (true);
	}
	return (false);
}

static bool	cyl_end_2(t_hitinfo *hit, t_ray camera_ray, \
	t_cylinder *cylinder, POINT *res)
{
	t_vect	hypotenuse;
	t_vect	proj;
	t_vect	p_to_res;
	float	proj_len;

	camera_ray = camera_ray;
	hypotenuse = sub_vect(hit->p, cylinder->pos);
	proj = scale_vect(cylinder->dir, dot_product(hypotenuse, cylinder->dir));
	*res = sum_vect(cylinder->pos, proj);
	p_to_res = sub_vect(*res, cylinder->p2);
	proj_len = dot_product(p_to_res, cylinder->dir);
	if (proj_len >= 0 && proj_len <= cylinder->height)
		return (true);
	else
		return (false);
}

static bool	calc_hit_cyl_2(t_hitinfo *hit, float intersect, \
	t_ray camera_ray, t_cylinder *cylinder)
{
	float	prev_hit;
	POINT	prev;
	POINT	res;

	prev_hit = hit->t;
	prev = hit->p;
	if (intersect >= hit->t + 0.0003)
		return (false);
	hit->t = intersect;
	hit->p = sum_vect(camera_ray.pos, scale_vect(camera_ray.dir, intersect));
	if (!cyl_end_2(hit, camera_ray, cylinder, &res))
	{
		hit->t = prev_hit;
		hit->p = prev;
		return (false);
	}
	hit->normal = normalize(sub_vect(hit->p, res));
	checker_cyl(hit, cylinder);
	tex_cyl(hit, cylinder);
	cyl_bump(hit, cylinder);
	return (true);
}

bool	render_cylinder_shadow(t_ray shadow_ray, t_data *data, \
	t_cylinder *cylinder, t_hitinfo *hit)
{
	t_vect	comp;
	t_vect	pdelt;
	t_vect	b1;
	t_vect	c1;

	pdelt = sub_vect(shadow_ray.pos, cylinder->pos);
	comp = sub_vect(shadow_ray.dir, scale_vect(cylinder->dir, \
		dot_product(shadow_ray.dir, cylinder->dir)));
	data->a = dot_product(comp, comp);
	b1 = sub_vect(pdelt, scale_vect(cylinder->dir, \
		dot_product(pdelt, cylinder->dir)));
	data->b = 2 * dot_product(comp, b1);
	c1 = sub_vect(pdelt, scale_vect(cylinder->dir, \
		dot_product(pdelt, cylinder->dir)));
	data->c = dot_product(c1, c1) - cylinder->radius * cylinder->radius;
	if (solve_quadratic(data, &data->t1, &data->t2) && \
		(data->t1 > 0.0001 && data->t1 < hit->t))
	{
		if (calc_hit_cyl_2(hit, data->t1, shadow_ray, cylinder))
			return (true);
	}
	if (caps_2(shadow_ray, data, cylinder, hit))
		return (true);
	return (false);
}
