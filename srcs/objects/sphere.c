/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:42:48 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 18:07:54 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	calc_hit_sphere(t_hitinfo *hit, float intersect, t_ray ray,
		t_sphere *sphere)
{
	if (intersect >= hit->t)
		return ;
	hit->t = intersect;
	hit->p = sum_vect(ray.pos, scale_vect(ray.dir, intersect));
	hit->normal = normalize(sub_vect(hit->p, sphere->pos));
	if (dot_product(ray.dir, hit->normal) < 0)
		hit->is_outside = true;
	else
	{
		hit->normal = scale_vect(hit->normal, -1);
		hit->is_outside = false;
	}
	checker_sphere(hit, sphere);
	sphere_texture(hit, sphere);
	sphere_bump(hit, sphere);
}

bool	render_sphere(t_ray camera_ray, t_data *data, t_sphere *sphere,
		t_hitinfo *hit)
{
	t_vect	offset_vect;
	float	intersect1;
	float	intersect2;

	offset_vect = sub_vect(camera_ray.pos, sphere->pos);
	data->a = dot_product(camera_ray.dir, camera_ray.dir);
	data->b = 2.0 * dot_product(camera_ray.dir, offset_vect);
	data->c = dot_product(offset_vect, offset_vect) - square((*sphere).radius);
	if (solve_quadratic(data, &intersect1, &intersect2))
	{
		if (intersect1 > 0)
		{
			calc_hit_sphere(hit, intersect1, camera_ray, sphere);
			return (true);
		}
	}
	intersect1 = FLT_MAX;
	calc_hit_sphere(hit, intersect1, camera_ray, sphere);
	return (false);
}
