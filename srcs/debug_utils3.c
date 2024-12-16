/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:55:47 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 16:58:15 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	print_cylinder(t_cylinder *cylinder)
{
	printf("CYLINDER\n");
	printf("cylinder.pos: ");
	print_vect((*cylinder).pos);
	printf("cylinder.p1: ");
	print_vect((*cylinder).p1);
	printf("cylinder.p2: ");
	print_vect((*cylinder).p2);
	printf("diameter: %f, radius: %f, height: %f color: ", (*cylinder).diameter,
		(*cylinder).radius, (*cylinder).height);
	print_rgb((*cylinder).rgb);
	printf("nb_params: %d\n", cylinder->nb_params);
	printf("\n");
}

void	print_cone(t_cone *cone)
{
	printf("CONE\n");
	printf("cone.pos: ");
	print_vect((*cone).pos);
	printf("cone.p1: ");
	print_vect((*cone).p1);
	printf("cone.p2: ");
	print_vect((*cone).p2);
	printf(" theta radians: %f, theta degrees: %f \n", (*cone).theta_r,
		(*cone).theta_d);
	printf("diameter: %f, radius: %f, height: %f color: ", (*cone).diameter,
		(*cone).radius, (*cone).height);
	print_rgb((*cone).rgb);
	printf("nb_params: %d\n", cone->nb_params);
	printf("\n");
}

void	print_plane(t_plane *plane)
{
	printf("PLANE\n");
	printf("plane.pos: ");
	print_vect((*plane).pos);
	printf("plane.vect: ");
	print_vect((*plane).vect);
	print_rgb((*plane).rgb);
	printf("nb_params: %d\n", plane->nb_params);
	printf("\n");
}
