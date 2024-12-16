/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:25:06 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 16:49:49 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	clean_geometry(t_objs *obj)
{
	int	i;

	i = 0;
	while (obj[i].type_obj != END)
	{
		free(obj[i++].object);
	}
	free(obj);
}

void	clean_pics(t_picture pics[], int pic_idx, t_data *data)
{
	int	i;

	i = 0;
	if (pic_idx < 0)
		return ;
	while (i <= pic_idx && pics[i].data != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, pics[i].pic);
		free(pics[i].path);
		i++;
	}
}

void	clean_window(t_data *data)
{
	if (data->mlx_win)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	}
	if (data->img.img_ptr)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

void	clean(t_data *data)
{
	clean_geometry(data->obj);
	clean_pics(data->pics, data->pic_idx, data);
	clean_window(data);
}
