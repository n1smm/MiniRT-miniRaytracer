/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_init2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:10:34 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/15 20:53:15 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	top_bottom_cone(POINT *p1, POINT *p2, t_cone cone)
{
	*p1 = sum_vect(cone.pos, scale_vect(cone.dir, cone.height / 2));
	*p2 = sum_vect(cone.pos, scale_vect(cone.dir, -cone.height / 2));
}

void	cone_angle(t_cone *cone)
{
	float	angle;

	angle = atan2((*cone).radius, (*cone).height / 2);
	(*cone).theta_r = angle;
	(*cone).theta_d = angle * (180 / M_PI);
}

void	cylinder_check(t_data *data, char **res)
{
	char	**coords;
	int		i;

	i = 0;
	if (res[3])
	{
		atol_wrapper(res[3], data, INT_MIN, INT_MAX);
		if (res[4])
			atol_wrapper(res[4], data, INT_MIN, INT_MAX);
	}
	coords = ft_split(res[1], ',');
	while (coords[i])
		atol_wrapper(coords[i++], data, INT_MIN, INT_MAX);
	free_mtx(coords);
	i = 0;
	coords = ft_split(res[2], ',');
	while (coords[i])
		atol_wrapper(coords[i++], data, -1, 1);
	free_mtx(coords);
	i = 0;
	coords = ft_split(res[5], ',');
	while (coords[i])
		atol_wrapper(coords[i++], data, 0, 255);
	free_mtx(coords);
}
