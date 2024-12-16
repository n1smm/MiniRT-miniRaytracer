/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:54:01 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 16:54:37 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	print_vect(t_vect vectr)
{
	printf("vect: x: [%f], y: [%f], z: [%f] \n", vectr.x, vectr.y, vectr.z);
}

void	print_rgb(t_rgb color)
{
	printf("rgb: r: %d, g: %d, b: %d\n", color.r, color.g, color.b);
}

void	print_ray(t_ray ray)
{
	printf("RAY\n");
	printf("ray.pos: ");
	print_vect(ray.pos);
	printf("ray.dir: ");
	print_vect(ray.dir);
	printf("\n");
}

void	print_camera(t_camera camera)
{
	printf("CAMERA \n");
	printf("camera.pos: ");
	print_vect(camera.pos);
	printf("camera.dir: ");
	print_vect(camera.dir);
	printf("camera.forward: ");
	print_vect(camera.forward);
	printf("camera.right: ");
	print_vect(camera.right);
	printf("camera.up: ");
	print_vect(camera.up);
	printf("camera.fov: %f\n", camera.fov);
	printf("\n");
}

void	print_sphere(t_sphere *sphere)
{
	printf("SPHERE\n");
	printf("sphere.pos: ");
	print_vect((*sphere).pos);
	printf("diameter: %f, radius: %f, color: ", (*sphere).diameter,
		(*sphere).radius);
	print_rgb((*sphere).rgb);
	printf("nb_params: %d\n", sphere->nb_params);
	printf("\n");
}
