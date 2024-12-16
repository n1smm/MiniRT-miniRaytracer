/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:37:01 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/10 18:37:02 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	inters_obj(t_data *data, t_objs obj, t_ray ray, t_hitinfo *hit)
{
	if (obj.type_obj == SPHERE)
		return (render_sphere(ray, data, obj.object, hit));
	else if (obj.type_obj == PLANE)
		return (render_plane_shadow(ray, obj.object, hit));
	else if (obj.type_obj == CONE)
		return (render_cone_shadow(ray, data, obj.object, hit));
	else if (obj.type_obj == CYLINDER)
		return (render_cylinder_shadow(ray, data, obj.object, hit));
	return (0);
}

static bool	shadow_obj(t_data *data, t_ray ray, \
	t_hitinfo hit, float dist_to_light)
{
	int	i;

	i = 0;
	while (data->obj[i].type_obj != END)
	{
		if (inters_obj(data, data->obj[i], ray, &hit))
		{
			if (hit.t < dist_to_light)
				return (true);
		}
		i++;
	}
	return (false);
}

bool	check_shadow(t_data *data, t_vect point, t_hitinfo hit)
{
	bool		in_shadow;
	t_ray		shadow_ray;
	t_hitinfo	shadow_hit;
	int			j;

	j = 0;
	shadow_hit.t = INFINITY;
	while (j < data->nb_lights)
	{
		data->light_dir = sub_vect(data->lights[j].pos, hit.p);
		data->dist_to_light = sqrt(dot_product(data->light_dir, \
			data->light_dir));
		shadow_ray.pos = sum_vect(point, scale_vect(hit.normal, 0.0003));
		shadow_ray.dir = normalize(sub_vect(data->lights[j].pos, point));
		in_shadow = false;
		in_shadow = shadow_obj(data, shadow_ray, shadow_hit, \
			data->dist_to_light);
		if (!in_shadow)
			break ;
		j++;
	}
	return (in_shadow);
}
