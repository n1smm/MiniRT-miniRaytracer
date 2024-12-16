/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:36:12 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/10 18:46:29 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	checker_cone2(t_hitinfo *hit, t_cone *cone, float theta, float height)
{
	if (dot_product(cone->dir, create_vector(1, 0, 0)) >= dot_product(cone->dir,
			create_vector(0, 0, 1)))
	{
		theta = atan2(hit->p.z, hit->p.x);
		height = hit->p.y - cone->pos.y;
	}
	else
	{
		theta = atan2(hit->p.x, hit->p.y);
		height = hit->p.z - cone->pos.z;
	}
	theta = theta;
	height = height;
}

void	checker_cone(t_hitinfo *hit, t_cone *cone)
{
	float	theta;
	float	height;
	int		square_theta;
	int		square_height;

	if (cone->checker == false)
	{
		hit->rgb = cone->rgb;
		return ;
	}
	theta = 0;
	height = 0;
	checker_cone2(hit, cone, theta, height);
	square_theta = floor(theta / ANGLE_SIZE);
	square_height = floor(height * cone->height * 2 / SQUARE);
	if ((square_theta + square_height) % 2 == 0)
		hit->rgb = cone->rgb;
	else
		hit->rgb = extract_color(0, 0, 0);
}
