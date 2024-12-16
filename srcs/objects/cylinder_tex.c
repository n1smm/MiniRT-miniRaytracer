/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_tex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:19:49 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 19:11:16 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <math.h>

void	checker_cyl2(t_hitinfo *hit, t_cylinder *cyl)
{
	if (fabs(dot_product(cyl->dir, create_vector(1, 0,
					0))) >= fabs(dot_product(cyl->dir, create_vector(0, 0, 1)))
		&& fabs(dot_product(cyl->dir, create_vector(1, 0,
					0))) <= fabs(dot_product(cyl->dir, create_vector(0, 1, 0))))
	{
		hit->calc.theta = atan2(hit->p.z, hit->p.x);
		hit->calc.height = hit->p.y - cyl->p2.y;
	}
	else if (fabs(dot_product(cyl->dir, create_vector(1, 0,
					0))) >= fabs(dot_product(cyl->dir, create_vector(0, 0, 1)))
		&& fabs(dot_product(cyl->dir, create_vector(1, 0,
					0))) >= fabs(dot_product(cyl->dir, create_vector(0, 1, 0))))
	{
		hit->calc.theta = atan2(hit->p.z, hit->p.y);
		hit->calc.height = hit->p.x - cyl->p2.x;
	}
	else
	{
		hit->calc.theta = atan2(hit->p.x, hit->p.y);
		hit->calc.height = hit->p.z - cyl->p2.z;
	}
}

void	checker_cyl(t_hitinfo *hit, t_cylinder *cyl)
{
	int	square_theta;
	int	square_height;

	if (cyl->checker == false)
	{
		hit->rgb = cyl->rgb;
		return ;
	}
	checker_cyl2(hit, cyl);
	square_theta = floor(hit->calc.theta / ANGLE_SIZE);
	square_height = floor(hit->calc.height * cyl->height * 2 / SQUARE);
	if ((square_theta + square_height) % 2 == 0)
		hit->rgb = cyl->rgb;
	else
		hit->rgb = extract_color(0, 0, 0);
}

t_rgb	tex_cyl_color(t_hitinfo *hit, t_picture pic, t_cylinder *cyl)
{
	t_rgb	final;
	int		color_offset;
	int		color;

	if (fabs(dot_product(cyl->dir, create_vector(1, 0,
					0))) >= fabs(dot_product(cyl->dir, create_vector(0, 0, 1))))
	{
		hit->calc.theta = atan2(hit->p.z, hit->p.x);
		hit->calc.height = hit->p.y - cyl->p2.y;
	}
	else
	{
		hit->calc.theta = atan2(hit->p.x, hit->p.y);
		hit->calc.height = hit->p.z - cyl->p2.z;
	}
	tex_cyl_color_2(hit, pic, cyl);
	color_offset = hit->calc.tex_height * pic.line_len + hit->calc.tex_theta
		* (pic.bpp / 8);
	color = *(int *)(pic.data + color_offset);
	final = extract_color_from_int(color);
	return (final);
}

void	tex_cyl(t_hitinfo *hit, t_cylinder *cyl)
{
	if (cyl->checker == false || cyl->nb_params < 7)
	{
		return ;
	}
	hit->rgb = tex_cyl_color(hit, cyl->tex, cyl);
}

void	cyl_bump(t_hitinfo *hit, t_cylinder *cyl)
{
	t_rgb	normal_color;
	t_vect	color_vect;
	t_vect	delta;

	if (cyl->checker == false || cyl->nb_params != 8)
	{
		return ;
	}
	normal_color = tex_cyl_color(hit, cyl->tex_normal, cyl);
	color_vect = rgb_to_vect(normal_color);
	delta = sub_vect(scale_down(color_vect, 127.5f), create_vector(1.0, 1.0,
				1.0));
	hit->normal = normalize(delta);
}
