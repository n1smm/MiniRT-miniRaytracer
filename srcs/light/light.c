/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:37:15 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/10 18:37:16 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static float	shadow(t_hitinfo hit, t_vect dir, float dist, float bright)
{
	float	angle_intensity;
	float	distance_factor;
	float	shadow_intensity;
	float	shadow_distance_factor;
	float	darkness;

	angle_intensity = max_nb(0, dot_product(hit.normal, dir));
	distance_factor = 1 / (1 + 0.1 * square(dist));
	shadow_intensity = (5.0 + angle_intensity) * distance_factor * bright;
	shadow_distance_factor = (50 * dist);
	darkness = shadow_intensity * (1 + shadow_distance_factor) * 0.2;
	return (darkness);
}

static float	lum(t_light light, t_hitinfo *hit, t_vect dir, float dist)
{
	float	angle_intensity;
	float	distance_factor;

	angle_intensity = max_nb(0.0f, dot_product(hit->normal, dir));
	distance_factor = 1 / (1 + 0.1 * square(dist));
	return (angle_intensity * distance_factor * light.bright);
}

static t_rgb	is_light(t_hitinfo *hit, t_data *data, int i, t_ray camera_ray)
{
	t_rgb	diffuse;
	t_rgb	final_color;

	diffuse = initialize_rgb(diffuse);
	final_color = initialize_rgb(final_color);
	if (tonality_is_relevant(data->lights[i].rgb))
		diffuse = bri(mix(hit->rgb, data->lights[i].rgb), lum(data->lights[i], \
			hit, data->light_dir, data->dist_to_light) * 500 * 0.5);
	else
		diffuse = bri(hit->rgb, lum(data->lights[i], hit, \
			data->light_dir, data->dist_to_light) * 500 * 0.5);
	final_color = add_rgb(add_rgb(diffuse, calculate_specular(hit, \
		data->light_dir, camera_ray, 80)), final_color);
	return (final_color);
}

t_rgb	lights_intersect(t_data *data, t_ray camera_ray, t_hitinfo *hit)
{
	int		i;
	t_rgb	final_color;
	t_rgb	diffuse;

	i = 0;
	final_color = initialize_rgb(final_color);
	diffuse = initialize_rgb(diffuse);
	while (i < data->nb_lights)
	{
		data->light_dir = normalize(sub_vect(data->lights[i].pos, hit->p));
		data->dist_to_light = magnitude(data->light_dir);
		if (check_shadow(data, hit->p, *hit))
			final_color = dark_rgb(create_color_rgb(hit->rgb, data->ambient), \
				shadow(*hit, data->light_dir, data->dist_to_light, \
					data->lights[i].bright));
		else
			final_color = is_light(hit, data, i, camera_ray);
		i++;
	}
	return (clamp_rgb(final_color));
}

t_ray	*get_lights_rays(t_data *data, int j)
{
	int		nb_rays;
	int		i;
	t_ray	*rays;
	double	theta;
	double	phi;

	i = 0;
	nb_rays = 100;
	data->light.nb_rays = nb_rays;
	rays = safe_malloc(sizeof(t_ray) * nb_rays);
	while (i < nb_rays)
	{
		rays[i].pos = data->lights[j].pos;
		theta = ((double)rand() / RAND_MAX) * 2.0 * PI;
		phi = ((double)rand() / RAND_MAX) * PI;
		rays[i].dir.x = sin(phi) * cos(theta);
		rays[i].dir.y = sin(phi) * sin(theta);
		rays[i].dir.z = cos(phi);
		rays[i].dir = normalize(rays[i].dir);
		i++;
	}
	return (rays);
}
