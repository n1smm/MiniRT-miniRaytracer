/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:49:29 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 16:49:40 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float	scale(float point, float max_dimension)
{
	if (point < max_dimension / 2)
		return (point + (max_dimension / 2));
	else if (point > max_dimension / 2)
		return (point - (max_dimension / 2));
	else
		return (point);
}

t_vect	camera_to_world(t_vect dir, t_camera camera)
{
	t_vect	world_dir;

	world_dir.x = dir.x * (camera.right.x) + dir.y * (camera.up.x) + dir.z
		* (camera.forward.x);
	world_dir.y = dir.x * (camera.right.y) + dir.y * (camera.up.y) + dir.z
		* (camera.forward.y);
	world_dir.z = dir.x * (camera.right.z) + dir.y * (camera.up.z) + dir.z
		* (camera.forward.z);
	return (world_dir);
}

t_ray	camera_rays(int x, int y, t_data *data)
{
	t_ray	ray;

	if (max_nb(data->img.width, data->img.height) == data->img.width)
	{
		ray.dir.x = (2 * ((x + 0.5) / data->img.width) - 1)
			* tan(data->camera.fov / 2 * M_PI / 180) * data->img_ratio;
		ray.dir.y = (1 - 2 * ((y + 0.5) / data->img.height))
			* tan(data->camera.fov / 2 * M_PI / 180);
	}
	else
	{
		ray.dir.x = (2 * ((x + 0.5) / data->img.width) - 1)
			* tan(data->camera.fov / 2 * M_PI / 180);
		ray.dir.y = (1 - 2 * ((y + 0.5) / data->img.height))
			* tan(data->camera.fov / 2 * M_PI / 180) * data->img_ratio;
	}
	ray.dir.z = 1;
	ray.dir = (camera_to_world(ray.dir, data->camera));
	ray.pos = data->camera.pos;
	return (ray);
}
