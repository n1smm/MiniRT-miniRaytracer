/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brightness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:37:24 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/10 18:37:25 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

inline float	luminance(t_rgb color)
{
	return (0.299 * color.r + 0.587 * color.g + 0.114 * color.b);
}

t_rgb	mix(t_rgb color1, t_rgb color2)
{
	float	luminance1;
	float	luminance2;
	t_rgb	mixed_color;
	float	mixed_luminance;
	float	adjustment;

	luminance1 = luminance(color1);
	luminance2 = luminance(color2);
	mixed_color.r = (color1.r + color2.r) / 2;
	mixed_color.g = (color1.g + color2.g) / 2;
	mixed_color.b = (color1.b + color2.b) / 2;
	mixed_luminance = luminance(mixed_color);
	adjustment = (luminance1 + luminance2) / 2;
	mixed_color.r = min_nb((int)(mixed_color.r * (adjustment / \
		mixed_luminance)), 255);
	mixed_color.g = min_nb((int)(mixed_color.g * (adjustment / \
		mixed_luminance)), 255);
	mixed_color.b = min_nb((int)(mixed_color.b * (adjustment / \
		mixed_luminance)), 255);
	return (mixed_color);
}

bool	tonality_is_relevant(t_rgb color1)
{
	if ((color1.r == color1.g) && (color1.r == color1.b))
		return (false);
	else if (color1.r > 240 && color1.g > 240 && color1.b)
		return (false);
	else
		return (true);
}
