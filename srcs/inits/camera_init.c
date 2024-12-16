/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:01:34 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/15 23:16:22 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	world_position(t_data *data, t_vect world_up)
{
	if (data->camera.dir.x == 0 && data->camera.dir.z == 0)
	{
		data->camera.right = create_vector(1.0, 0, 0);
		data->camera.up = create_vector(0, 0, 1.0);
	}
	else
	{
		data->camera.right = normalize(cross_product(world_up,
					data->camera.forward));
		data->camera.up = cross_product(data->camera.forward,
				data->camera.right);
	}
}

void	camera_init(t_data *data, char *line)
{
	char	**res;
	char	**coords;
	char	**vector;
	t_vect	world_up;

	world_up = create_vector(0, 1, 0);
	coords = NULL;
	vector = NULL;
	res = ft_split(line, ' ');
	if (invalid_parts(&coords, 2, data, res[1]) || invalid_parts(&vector, 2,
			data, res[2]))
	{
		free_all_mtx(res, coords, vector, NULL);
		return ;
	}
	data->camera.pos = create_vector(atol_wrapper(coords[0], data, INT_MIN,
				INT_MAX), atol_wrapper(coords[1], data, INT_MIN, INT_MAX),
			atol_wrapper(coords[2], data, INT_MIN, INT_MAX));
	data->camera.dir = create_vector(atol_wrapper(vector[0], data, -1, 1),
			atol_wrapper(vector[1], data, -1, 1), atol_wrapper(vector[2], data,
				-1, 1));
	data->camera.fov = atoi_wrapper(res[3], data, 0, 180);
	data->camera.forward = normalize(data->camera.dir);
	world_position(data, world_up);
	free_all_mtx(res, coords, vector, NULL);
}
