/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:36:53 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/10 18:36:53 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	clamp_rgb(t_rgb color)
{
	if (color.r < 0)
		color.r = 0;
	else if (color.r > 255)
		color.r = 255;
	if (color.g < 0)
		color.g = 0;
	else if (color.g > 255)
		color.g = 255;
	if (color.b < 0)
		color.b = 0;
	else if (color.b > 255)
		color.b = 255;
	return (color);
}

t_rgb	add_rgb(t_rgb color1, t_rgb color2)
{
	t_rgb	result;

	result.r = min_nb(color1.r + color2.r, 255);
	result.g = min_nb(color1.g + color2.g, 255);
	result.b = min_nb(color1.b + color2.b, 255);
	return (result);
}

t_rgb	bri(t_rgb rgb, float bright)
{
	t_rgb	light_rgb;

	light_rgb.r = min_nb((rgb.r + bright), 255);
	light_rgb.g = min_nb((rgb.g + bright), 255);
	light_rgb.b = min_nb((rgb.b + bright), 255);
	return (light_rgb);
}

t_rgb	dark_rgb(t_rgb rgb, float darkness)
{
	t_rgb	dark_rgb;

	dark_rgb.r = max_nb((rgb.r - darkness), 0);
	dark_rgb.g = max_nb((rgb.g - darkness), 0);
	dark_rgb.b = max_nb((rgb.b - darkness), 0);
	return (dark_rgb);
}

t_rgb	initialize_rgb(t_rgb rgb)
{
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	return (rgb);
}
