/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:09:22 by thiew             #+#    #+#             */
/*   Updated: 2024/12/09 17:13:34 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	int		offset;
	char	*dest;

	offset = (y * data->img.line_len + x * (data->img.bpp / 8));
	dest = data->img.pix_ptr + offset;
	*(unsigned int *)dest = color;
}

void	render_objs(t_data *data, t_ray camera_ray, t_hitinfo *hit)
{
	int			i;
	t_type_obj	type;

	i = 0;
	while (data->obj[i].type_obj != END)
	{
		type = data->obj[i].type_obj;
		if (type == SPHERE)
		{
			render_sphere(camera_ray, data, data->obj[i].object, hit);
		}
		else if (type == PLANE)
		{
			render_plane(camera_ray, data->obj[i].object, hit);
		}
		else if (type == CYLINDER)
		{
			render_cylinder(camera_ray, data, data->obj[i].object, hit);
		}
		else if (type == CONE)
			render_cone(camera_ray, data, data->obj[i].object, hit);
		i++;
	}
}

void	bonus_objects(t_data *data, bool light_finished)
{
	int			i;
	t_type_obj	type;

	i = 0;
	while (data->obj[i].type_obj != END)
	{
		type = data->obj[i].type_obj;
		if (type == SPHERE)
			bonus_sphere(data->obj[i].object, light_finished);
		else if (type == PLANE)
			bonus_plane(data->obj[i].object, light_finished);
		else if (type == CYLINDER)
			bonus_cylinder(data->obj[i].object, light_finished);
		else if (type == CONE)
			bonus_cone(data->obj[i].object, light_finished);
		i++;
	}
}

void	render_cycle(t_data *data, t_ray *camera_ray,
		t_hitinfo *hit, t_rgb *res)
{
	*hit = init_hit(data);
	data->hit = *hit;
	render_objs(data, *camera_ray, &data->hit);
	bonus_objects(data, false);
	*res = lights_intersect(data, *camera_ray, &data->hit);
}

int	render(t_data *data)
{
	int			x;
	int			y;
	t_ray		camera_ray;
	t_hitinfo	hit;
	t_rgb		res;

	data->img_ratio = ratio(data->img.width, data->img.height);
	y = 0;
	while (y < data->img.height)
	{
		x = 0;
		while (x < data->img.width)
		{
			camera_ray = camera_rays(x, y, data);
			render_cycle(data, &camera_ray, &hit, &res);
			my_pixel_put(data, x, y, just_color(res));
			bonus_objects(data, true);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0,
		0);
	return (0);
}
