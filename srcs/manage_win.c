/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:09:13 by thiew             #+#    #+#             */
/*   Updated: 2024/12/15 20:30:05 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	raycasting(int x, int y, t_data *data)
{
	x = x;
	y = y;
	data = data;
}

int	keys(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		write(1, "Hai chiuso il programma.\n", 25);
		mlx_loop_end(data->mlx_ptr);
	}
	return (0);
}

int	esc_x(t_data *data)
{
	write(1, "Hai chiuso il programma.\n", 25);
	mlx_loop_end(data->mlx_ptr);
	return (0);
}

bool	check_loop(t_data *data)
{
	if (data->nb_camera != 1)
		return (false);
	if (data->nb_amb != 1)
		return (false);
	if (data->nb_lights < 1)
		return (false);
	if (data->nb_objs < 1)
		return (false);
	return (true);
}

bool	check_more_params(t_data *data)
{
	if (data->nb_camera > 1)
		return (false);
	if (data->nb_amb > 1)
		return (false);
	return (true);
}
