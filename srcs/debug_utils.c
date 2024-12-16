/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:01:30 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 16:58:17 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	print_object(t_objs *object, t_type_obj type)
{
	if (type == SPHERE)
		print_sphere(object->object);
	else if (type == PLANE)
		print_plane(object->object);
	else if (type == CYLINDER)
		print_cylinder(object->object);
	else if (type == CONE)
		print_cone(object->object);
}

void	print_pic(t_picture pic)
{
	printf("PICTURE nr:%d \n", pic.index);
	printf(" path:%s \t line_len: %d \t w:%d, h:%d \t bpp:%d \t endian:%d \n",
		pic.path, pic.line_len, pic.w, pic.h, pic.bpp, pic.endian);
	printf("data:%s \n\n", pic.data);
}

void	print_pictures(t_data *data)
{
	int	i;

	i = 0;
	if (data->pic_idx == 0)
	{
		print_pic(data->pics[i]);
		return ;
	}
	while (i <= data->pic_idx)
		print_pic(data->pics[i++]);
}

void	print_all_obj(t_data *data)
{
	int	i;

	i = -1;
	while (data->obj[++i].type_obj != END)
	{
		printf("object index: %d \t", i);
		print_object(&data->obj[i], data->obj[i].type_obj);
	}
	print_pictures(data);
}
