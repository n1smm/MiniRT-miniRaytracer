/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_tex_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:34:44 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 17:22:55 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	cap_texture(t_hitinfo *hit, t_cylinder *cyl)
{
	if (cyl->nb_params < 7 || cyl->checker == false)
	{
		hit->rgb = cyl->rgb;
		return ;
	}
	hit->rgb = tex_color(hit, cyl->tex);
}

void	cap_bump(t_hitinfo *hit, t_cylinder *cyl)
{
	t_rgb	normal_color;
	t_vect	color_vect;
	t_vect	delta;

	if (cyl->nb_params != 8 || cyl->checker == false)
	{
		return ;
	}
	normal_color = tex_color(hit, cyl->tex_normal);
	color_vect = rgb_to_vect(normal_color);
	delta = sub_vect(scale_down(color_vect, 127.5f), create_vector(1.0, 1.0,
				1.0));
	hit->normal = normalize(delta);
}

void	tex_cyl_color_2(t_hitinfo *hit, t_picture pic, t_cylinder *cyl)
{
	hit->calc.square_theta = fmod(hit->calc.theta / ANGLE_SIZE * 0.1, 1.0);
	hit->calc.square_height = fmod(hit->calc.height * cyl->height * 0.1
			/ SQUARE, 1.0);
	if (hit->calc.square_theta < 0)
		hit->calc.square_theta += 1.0;
	if (hit->calc.square_height < 0)
		hit->calc.square_height += 1.0;
	hit->calc.tex_theta = (int)(hit->calc.square_theta * pic.w);
	hit->calc.tex_height = (int)(hit->calc.square_height * pic.h);
}
