/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:42:03 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/15 21:09:16 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	sphere_bonus_init(t_data *data, t_sphere *sphere, char **res)
{
	int	count;

	sphere->tex.data = NULL;
	sphere->tex_normal.data = NULL;
	count = mtx_count(res);
	if (count >= 4 && res[4] && (nb_atoi(data, res[4]) == 0 || nb_atoi(data,
				res[4]) == 1))
	{
		sphere->checker = nb_atoi(data, res[4]);
		printf("cheker sphere: %s\n", res[4]);
		sphere->bonus = nb_atoi(data, res[4]);
	}
	else
	{
		sphere->checker = false;
		sphere->bonus = false;
	}
	if (count >= 5 && res[5])
		sphere->tex = data->pics[nb_atoi(data, res[5])];
	if (count >= 6 && res[6])
		sphere->tex_normal = data->pics[nb_atoi(data, res[6])];
	sphere->nb_params = count;
	return (count);
}

void	sphere_info(t_sphere *sphere, char **res, char **coords, char **rgb)
{
	sphere->pos = create_vector(ft_atol(coords[0]), ft_atol(coords[1]),
			ft_atol(coords[2]));
	sphere->diameter = ft_atol(res[2]);
	sphere->radius = sphere->diameter / 2;
	sphere->rgb = extract_color(ft_atol(rgb[0]), ft_atol(rgb[1]),
			ft_atol(rgb[2]));
}

void	sphere_check(t_data *data, char **coords, char **rgb, char **res)
{
	int	i;

	i = 0;
	while (coords[i])
		atol_wrapper(coords[i++], data, INT_MIN, INT_MAX);
	i = 0;
	while (rgb[i])
		atol_wrapper(rgb[i++], data, 0, 255);
	if (res[2])
		atol_wrapper(res[2], data, 0, INT_MAX);
}

void	sphere_init(t_data *data, char *line, int i)
{
	char		**res;
	char		**coords;
	char		**rgb;
	t_sphere	*sphere;

	rgb = NULL;
	coords = NULL;
	data->obj[i].type_obj = SPHERE;
	sphere = (t_sphere *)safe_malloc(sizeof(t_sphere));
	data->obj[i].object = sphere;
	res = ft_split(line, ' ');
	if (invalid_params(res, 3, data))
		return ;
	if (invalid_parts(&coords, 2, data, res[1]) || invalid_parts(&rgb, 2, data,
			res[3]))
	{
		free_all_mtx(res, coords, rgb, NULL);
		return ;
	}
	sphere_info(sphere, res, coords, rgb);
	sphere_bonus_init(data, sphere, res);
	sphere_check(data, coords, rgb, res);
	free_all_mtx(res, coords, rgb, NULL);
}
