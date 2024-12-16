/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:09:17 by thiew             #+#    #+#             */
/*   Updated: 2024/12/15 23:24:17 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

bool	obj_pars(char *line, t_data *data, int i, int *nb_pics)
{
	if (cmp_wrapper("sp", line, i, data) == true)
	{
		sphere_init(data, line, data->nb_objs);
		data->nb_objs++;
	}
	else if (cmp_wrapper("pl", line, i, data) == true)
	{
		plane_init(data, line, data->nb_objs);
		data->nb_objs++;
	}
	else if (cmp_wrapper("cy", line, i, data) == true)
	{
		cylinder_init(data, line, data->nb_objs);
		data->nb_objs++;
	}
	else if (cmp_wrapper("cn", line, i, data) == true)
	{
		cone_init(data, line, data->nb_objs);
		data->nb_objs++;
	}
	else
		return (false);
	return (true);
}

bool	amb_camera(char *line, t_data *data, int i, int *nb_pics)
{
	if (cmp_wrapper("A", line, i, data) == true)
	{
		data->nb_amb++;
		ambient_init(data, line);
	}
	else if (cmp_wrapper("C", line, i, data) == true)
	{
		data->nb_camera++;
		camera_init(data, line);
	}
	else if (cmp_wrapper("pic", line, i, data) == true)
	{
		(*nb_pics)++;
		pic_init(data, line, nb_pics);
	}
	else
		return (false);
	return (true);
}

int	prefix(char *line, t_data *data, int *nb_pics)
{
	int			i;
	static int	args;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	if (amb_camera(line, data, i, nb_pics))
		;
	else if (cmp_wrapper("L", line, i, data) == true)
	{
		lights_init(data, line, data->nb_lights);
		data->nb_lights++;
		args++;
	}
	else if (cmp_wrapper("l", line, i, data) == true)
	{
		lights_init(data, line, data->nb_lights);
		data->nb_lights++;
	}
	else if (obj_pars(line, data, i, nb_pics))
		;
	else
		printf("\nempty or non-functional line will not be used: %s\n", line);
	return (args);
}

int	line_parsing(int fd, t_data *data, int *nb_pics)
{
	int		i;
	char	*line;
	bool	first;

	i = 0;
	first = true;
	while (1)
	{
		if (first == false)
			free(line);
		first = false;
		line = get_next_line(fd);
		if (line == NULL)
			return (i);
		line = check_line(line);
		if (line && line[0] != 0)
		{
			i = prefix(line, data, nb_pics);
		}
	}
	free(line);
	return (i);
}

void	parsing(int fd, t_data *data)
{
	int	i;
	int	nb_pics;

	i = 0;
	nb_pics = -1;
	data->nb_objs = 0;
	data->nb_lights = 0;
	data->pic_idx = 0;
	data->nb_amb = 0;
	data->nb_camera = 0;
	i = line_parsing(fd, data, &nb_pics);
	data->obj[data->nb_objs].type_obj = END;
	data->pic_idx = nb_pics;
	close(fd);
	if (data->invalid == true || data->not_number == true || i > 1
		|| !check_more_params(data))
	{
		write(2, "error\n", 6);
		mlx_loop_end(data->mlx_ptr);
		clean(data);
		exit(1);
	}
	print_all_obj(data);
}
