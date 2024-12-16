/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:13:20 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/15 21:07:51 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	plane_vect_init(char **coords, char **vect, char **rgb, t_plane *plane)
{
	plane->pos = create_vector(ft_atol(coords[0]), ft_atol(coords[1]),
			ft_atol(coords[2]));
	plane->posn.x = plane->pos.x;
	plane->posn.y = plane->pos.y + 10;
	plane->posn.z = plane->pos.z;
	plane->vect = create_vector((ft_atol(vect[0])), (ft_atol(vect[1])),
			(ft_atol(vect[2])));
	plane->vect = normalize(plane->vect);
	plane->rgb = extract_color(ft_atol(rgb[0]), ft_atol(rgb[1]),
			ft_atol(rgb[2]));
}

void	plane_bonus_init(char **res, t_plane *plane, t_data *data)
{
	int	count;

	count = mtx_count(res);
	plane->tex.data = NULL;
	plane->tex_norm.data = NULL;
	if (count >= 4 && res[4] && (nb_atoi(data, res[4]) == 0 || nb_atoi(data,
				res[4]) == 1))
	{
		plane->checker = nb_atoi(data, res[4]);
		plane->bonus = nb_atoi(data, res[4]);
	}
	else
	{
		plane->checker = false;
		plane->bonus = false;
	}
	if (count >= 5 && res[5] && nb_atoi(data, res[5]) <= data->pic_idx)
		plane->tex = data->pics[nb_atoi(data, res[5])];
	if (count >= 6 && res[6] && nb_atoi(data, res[6]) <= data->pic_idx)
		plane->tex_norm = data->pics[nb_atoi(data, res[6])];
	plane->nb_params = count;
	printf("plane->nb params: %d \n", plane->nb_params);
}

void	plane_check(t_data *data, char **res, char **coords, char **rgb)
{
	int	i;

	i = 0;
	while (coords[i])
		atol_wrapper(coords[i++], data, INT_MIN, INT_MAX);
	i = 0;
	while (rgb[i])
		atol_wrapper(rgb[i++], data, 0, 255);
	if (res[4])
	{
		atol_wrapper(res[4], data, 0, 1);
		if (res[5])
		{
			atol_wrapper(res[5], data, 0, 20);
			if (res[6])
				atol_wrapper(res[6], data, 0, 20);
		}
	}
}

void	plane_init(t_data *data, char *line, int i)
{
	char	**res;
	char	**coords;
	char	**vect;
	char	**rgb;
	t_plane	*plane;

	coords = NULL;
	vect = NULL;
	rgb = NULL;
	data->obj[i].type_obj = PLANE;
	plane = (t_plane *)safe_malloc(sizeof(t_plane));
	data->obj[i].object = plane;
	res = ft_split(line, ' ');
	if (invalid_params(res, 3, data))
		return ;
	if (invalid_parts(&coords, 2, data, res[1]) || invalid_parts(&vect, 2, data,
			res[2]) || invalid_parts(&rgb, 2, data, res[3]))
	{
		free_all_mtx(res, coords, vect, rgb);
		return ;
	}
	plane_vect_init(coords, vect, rgb, plane);
	plane_bonus_init(res, plane, data);
	plane_check(data, res, coords, rgb);
	free_all_mtx(res, coords, vect, rgb);
}
