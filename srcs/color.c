/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:50:20 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 16:52:18 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	just_color(t_rgb rgb)
{
	int	r;
	int	g;
	int	b;

	r = rgb.r;
	g = rgb.g;
	b = rgb.b;
	return ((r << 16) | (g << 8) | b);
}

t_rgb	extract_color(int r, int g, int b)
{
	t_rgb	color;

	color.b = b;
	color.g = g;
	color.r = r;
	return (color);
}

t_rgb	extract_color_from_int(int color)
{
	t_rgb	rgb;

	rgb.r = get_r(color);
	rgb.g = get_g(color);
	rgb.b = get_b(color);
	return (rgb);
}

t_vect	rgb_to_vect(t_rgb color)
{
	t_vect	v;

	v.x = color.r;
	v.y = color.g;
	v.z = color.b;
	return (v);
}

int	interpolate_color(int color1, int color2, float ratio)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (int)(get_t(color1) * (1 - ratio) + get_t(color2) * ratio);
	r = (int)(get_r(color1) * (1 - ratio) + get_r(color2) * ratio);
	g = (int)(get_g(color1) * (1 - ratio) + get_g(color2) * ratio);
	b = (int)(get_b(color1) * (1 - ratio) + get_b(color2) * ratio);
	return (create_trgb(t, r, g, b));
}
