/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:32:31 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/15 23:13:44 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	cone_vect_2(t_cone *cone, char **res, char **coords, t_data *data)
{
	POINT	p1;
	POINT	p2;

	cone->diameter = atol_wrapper(res[3], data, INT_MIN, INT_MAX);
	cone->radius = cone->diameter / 2.0;
	cone->height = atol_wrapper(res[4], data, INT_MIN, INT_MAX);
	cone_angle(cone);
	top_bottom_cone(&p1, &p2, *cone);
	cone->p1 = p1;
	cone->p2 = p2;
	coords = ft_split(res[5], ',');
	if (mtx_count(coords) != 2)
	{
		free(coords);
		return (false);
	}
	cone->rgb = extract_color(atol_wrapper(coords[0], data, 0, 255),
			atol_wrapper(coords[1], data, 0, 255), atol_wrapper(coords[2], data,
				0, 255));
	free_mtx(coords);
	return (true);
}

bool	cone_vect_init(t_cone *cone, char **res, char **coords, t_data *data)
{
	cone->pos = create_vector(atol_wrapper(coords[0], data, INT_MIN, INT_MAX),
			atol_wrapper(coords[1], data, INT_MIN, INT_MAX),
			atol_wrapper(coords[2], data, INT_MIN, INT_MAX));
	free_mtx(coords);
	coords = ft_split(res[2], ',');
	if (mtx_count(coords) != 2)
	{
		free(coords);
		return (false);
	}
	cone->dir = create_vector(atol_wrapper(coords[0], data, -1, 1),
			atol_wrapper(coords[1], data, -1, 1), atol_wrapper(coords[2], data,
				-1, 1));
	cone->dir = normalize(cone->dir);
	free_mtx(coords);
	if (!cone_vect_2(cone, res, coords, data))
		return (false);
	return (true);
}

void	cone_bonus_init(t_data *data, t_cone *cone, char **res, int count)
{
	cone->tex.data = NULL;
	if (count >= 6 && res[6] && (nb_atoi(data, res[6]) == 0 || nb_atoi(data,
				res[6]) == 1))
	{
		cone->checker = nb_atoi(data, res[6]);
		cone->bonus = nb_atoi(data, res[6]);
	}
	else
	{
		cone->checker = false;
		cone->bonus = false;
	}
	cone->nb_params = count;
}

void	cone_init(t_data *data, char *line, int i)
{
	char	**res;
	char	**coords;
	t_cone	*cone;
	int		count;

	coords = NULL;
	data->obj[i].type_obj = CONE;
	cone = (t_cone *)safe_malloc(sizeof(t_cone));
	data->obj[i].object = cone;
	res = ft_split(line, ' ');
	if (invalid_params(res, 5, data))
		return ;
	count = mtx_count(res);
	if (invalid_parts(&coords, 2, data, res[1]))
	{
		free_all_mtx(res, coords, NULL, NULL);
		return ;
	}
	cone_vect_init(cone, res, coords, data);
	cone_bonus_init(data, cone, res, count);
	free_mtx(res);
}
