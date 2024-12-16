/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:45:14 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 16:49:06 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	bonus_sphere(t_sphere *sphere, bool light_finished)
{
	if (sphere->bonus == true && light_finished == false)
		sphere->checker = false;
	else if (sphere->bonus == true && light_finished == true)
		sphere->checker = true;
	else if (sphere->bonus == false)
		sphere->checker = false;
}

void	bonus_plane(t_plane *plane, bool light_finished)
{
	if (plane->bonus == true && light_finished == false)
		plane->checker = false;
	else if (plane->bonus == true && light_finished == true)
		plane->checker = true;
	else if (plane->bonus == false)
		plane->checker = false;
}

void	bonus_cylinder(t_cylinder *cylinder, bool light_finished)
{
	if (cylinder->bonus == true && light_finished == false)
		cylinder->checker = false;
	else if (cylinder->bonus == true && light_finished == true)
		cylinder->checker = true;
	else if (cylinder->bonus == false)
		cylinder->checker = false;
}

void	bonus_cone(t_cone *cone, bool light_finished)
{
	if (cone->bonus == true && light_finished == false)
		cone->checker = false;
	else if (cone->bonus == true && light_finished == true)
		cone->checker = true;
	else if (cone->bonus == false)
		cone->checker = false;
}
