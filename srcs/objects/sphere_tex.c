/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:28:47 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/07 15:41:41 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	tex_sphere_color(t_hitinfo *hit, t_picture pic, t_sphere *sphere)
{
	t_rgb	final;
	int		color_offset;
	int		color;
	t_calc	calc;

	calc = hit->calc;
	calc.theta = atan2(hit->normal.z, hit->normal.x);
	calc.phi = acos(hit->normal.y / sphere->radius);
	calc.scale_theta = sphere->radius / 1.5;
	calc.square_theta = fmod(calc.theta / (ANGLE_SIZE * calc.scale_theta), 1.0);
	calc.square_phi = fmod(calc.phi / (ANGLE_SIZE), 1.0);
	if (calc.square_theta < 0)
		calc.square_theta += 1.0;
	if (calc.square_phi < 0)
		calc.square_phi += 1.0;
	calc.tex_theta = (int)(calc.square_theta * pic.w);
	calc.tex_phi = (int)(calc.square_phi * pic.h);
	color_offset = calc.tex_phi * pic.line_len + calc.tex_theta * (pic.bpp / 8);
	color = *(int *)(pic.data + color_offset);
	final = extract_color_from_int(color);
	return (final);
}

void	sphere_texture(t_hitinfo *hit, t_sphere *sphere)
{
	if ((sphere->nb_params < 5 || sphere->checker == false)
		|| sphere->tex.data == NULL)
	{
		return ;
	}
	hit->rgb = tex_sphere_color(hit, sphere->tex, sphere);
}

void	sphere_bump(t_hitinfo *hit, t_sphere *sphere)
{
	t_rgb	normal_color;
	t_vect	color_vect;
	t_vect	delta;

	if ((sphere->nb_params != 6 || sphere->checker == false)
		|| sphere->tex_normal.data == NULL)
	{
		return ;
	}
	normal_color = tex_sphere_color(hit, sphere->tex_normal, sphere);
	color_vect = rgb_to_vect(normal_color);
	delta = sub_vect(scale_down(color_vect, 127.5f), create_vector(1.0, 1.0,
				1.0));
	hit->normal = normalize(delta);
}

void	checker_sphere(t_hitinfo *hit, t_sphere *sphere)
{
	float	theta;
	float	phi;
	float	scale_theta;
	int		square_theta;
	int		square_phi;

	if (sphere->checker == false)
	{
		hit->rgb = sphere->rgb;
		return ;
	}
	theta = atan2(hit->normal.z, hit->normal.x);
	phi = acos(hit->normal.y / sphere->radius);
	scale_theta = sphere->radius / 1.5;
	square_theta = floor(theta / (ANGLE_SIZE * scale_theta));
	square_phi = floor(phi / (ANGLE_SIZE));
	if ((square_theta + square_phi) % 2 == 0)
		hit->rgb = sphere->rgb;
	else
		hit->rgb = extract_color(0, 0, 0);
}
