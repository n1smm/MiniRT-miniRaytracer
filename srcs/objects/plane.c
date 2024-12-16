/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:47:37 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/15 18:12:44 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	render_plane(t_ray camera_ray, t_plane *plane, t_hitinfo *hit)
{
	float	t;
	float	d;

	if ((dot_product(plane->vect, camera_ray.dir)) == 0)
		return (false);
	d = -(dot_product(plane->vect, plane->pos));
	t = -(d + dot_product(plane->vect, camera_ray.pos)) / \
		(dot_product(plane->vect, camera_ray.dir));
	if (t > 0 && t < hit->t)
	{
		hit->t = t;
		hit->p = sum_vect(camera_ray.pos, scale_vect(camera_ray.dir, t));
		hit->normal = plane->vect;
		hit->is_outside = true;
		hit->rgb = plane->rgb;
		plane_checker(hit, plane);
		plane_texture(hit, plane, plane->tex);
		plane_bump(hit, plane);
	}
	return (true);
}
