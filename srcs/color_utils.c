/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:50:40 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 16:52:21 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_rgb	create_color_rgb(t_rgb rgb, t_ambient ambient)
{
	t_rgb	res;

	res.r = (rgb.r + ambient.rgb.r) * ambient.ratio;
	res.g = (rgb.g + ambient.rgb.g) * ambient.ratio;
	res.b = (rgb.b + ambient.rgb.b) * ambient.ratio;
	return (res);
}

int	create_color_int(t_rgb rgb)
{
	int	r;
	int	g;
	int	b;

	r = (rgb.r);
	g = (rgb.g);
	b = (rgb.b);
	return ((r << 16) | (g << 8) | b);
}

t_ambient	darker_ambient(t_ambient ambient, float i)
{
	t_ambient	res;

	res.rgb.r = ambient.rgb.r / i;
	res.rgb.g = ambient.rgb.g / i;
	res.rgb.b = ambient.rgb.b / i;
	if (res.rgb.r < 0)
		res.rgb.r = 0;
	if (res.rgb.g < 0)
		res.rgb.g = 0;
	if (res.rgb.b < 0)
		res.rgb.b = 0;
	return (res);
}

int	create_color(t_rgb rgb, t_ambient ambient)
{
	int	r;
	int	g;
	int	b;

	r = (rgb.r + ambient.rgb.r) * ambient.ratio;
	g = (rgb.g + ambient.rgb.g) * ambient.ratio;
	b = (rgb.b + ambient.rgb.b) * ambient.ratio;
	return ((r << 16) | (g << 8) | b);
}
