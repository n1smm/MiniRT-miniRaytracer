/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:48:18 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/15 19:52:27 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	top_bottom_point(POINT *p1, POINT *p2, t_cylinder cylinder)
{
	*p1 = sum_vect(cylinder.pos, scale_vect(cylinder.dir, cylinder.height / 2));
	*p2 = sum_vect(cylinder.pos, scale_vect(cylinder.dir, (-cylinder.height)
				/ 2));
}

void	cylinder_bonus_init(t_data *data, t_cylinder *cylinder, char **res,
		int count)
{
	cylinder->tex.data = NULL;
	cylinder->tex_normal.data = NULL;
	if (count >= 6 && res[6] && (ft_atoi(res[6]) == 0 || ft_atoi(res[6]) == 1))
	{
		cylinder->checker = ft_atoi(res[6]);
		cylinder->bonus = ft_atoi(res[6]);
	}
	else
	{
		cylinder->checker = false;
		cylinder->bonus = false;
	}
	if (count >= 7 && res[7])
		cylinder->tex = data->pics[ft_atoi(res[7])];
	if (count >= 8 && res[8])
		cylinder->tex_normal = data->pics[ft_atoi(res[8])];
	cylinder->nb_params = count;
}

bool	cyl_vect_2(t_cylinder *cylinder, char **res, char **coords, int count)
{
	POINT	p1;
	POINT	p2;

	count = count;
	cylinder->diameter = ft_atol(res[3]);
	cylinder->radius = cylinder->diameter / 2;
	cylinder->height = ft_atol(res[4]);
	coords = ft_split(res[5], ',');
	if (mtx_count(coords) != 2)
	{
		free_mtx(coords);
		return (false);
	}
	cylinder->rgb = extract_color(ft_atol(coords[0]), ft_atol(coords[1]),
			ft_atol(coords[2]));
	top_bottom_point(&p1, &p2, *cylinder);
	cylinder->p1 = p1;
	cylinder->p2 = p2;
	free_mtx(coords);
	return (true);
}

bool	cylinder_vect_init(t_cylinder *cylinder, char **res, char **coords,
		int count)
{
	if (count < 5)
		return (false);
	cylinder->pos = create_vector(ft_atol(coords[0]), ft_atol(coords[1]),
			ft_atol(coords[2]));
	free_mtx(coords);
	coords = ft_split(res[2], ',');
	if (mtx_count(coords) != 2)
	{
		free(coords);
		return (false);
	}
	cylinder->dir = create_vector(ft_atol(coords[0]), ft_atol(coords[1]),
			ft_atol(coords[2]));
	cylinder->dir = normalize(cylinder->dir);
	free_mtx(coords);
	if (!cyl_vect_2(cylinder, res, coords, count))
		return (false);
	return (true);
}

void	cylinder_init(t_data *data, char *line, int i)
{
	char		**res;
	char		**coords;
	t_cylinder	*cylinder;
	int			count;

	coords = NULL;
	data->obj[i].type_obj = CYLINDER;
	cylinder = (t_cylinder *)safe_malloc(sizeof(t_cylinder));
	data->obj[i].object = cylinder;
	res = ft_split(line, ' ');
	if (invalid_params(res, 5, data))
		return ;
	count = mtx_count(res);
	if (invalid_parts(&coords, 2, data, res[1]))
	{
		free_all_mtx(res, coords, NULL, NULL);
		return ;
	}
	if (!cylinder_vect_init(cylinder, res, coords, count))
		data->invalid = true;
	cylinder_bonus_init(data, cylinder, res, count);
	cylinder_check(data, res);
	free_mtx(res);
}
