/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:09:07 by thiew             #+#    #+#             */
/*   Updated: 2024/12/15 14:18:01 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// #include <cstdlib>

void	print_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

t_data	*start_ambient(t_data *data)
{
	data->ambient.ratio = 0.0;
	data->ambient.rgb.r = 0;
	data->ambient.rgb.g = 0;
	data->ambient.rgb.b = 0;
	return (data);
}

void	data_init(t_data *data)
{
	int	i;

	i = 0;
	data->invalid = false;
	data->not_number = false;
	data->img.width = 900;
	data->img.height = 900;
	data->obj = safe_malloc(sizeof(t_objs) * MAX_OBJECTS);
	while (i < MAX_OBJECTS)
	{
		data->obj[i].type_obj = NOTHING;
		i++;
	}
	data->index_objs = 0;
}

void	win_inits(t_data *data)
{
	data_init(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		print_error("Init error");
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->img.width,
			data->img.height, "miniRT");
	if (!data->mlx_win)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		print_error("Init error");
	}
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, data->img.width,
			data->img.height);
	if (!data->img.img_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		print_error("Init error");
	}
	data->img.pix_ptr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	ac = ac;
	if (ac != 2)
		print_error(" Do your job correctly and"
			" pass ONE fucking config file!!!");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_error("invalid config file passed as ARG\n");
	if (!check_extension(av[1]))
		print_error("invalid extension");
	win_inits(&data);
	parsing(fd, &data);
	if (1)
	{
		mlx_hook(data.mlx_win, 2, 1L << 0, keys, &data);
		mlx_hook(data.mlx_win, 17, 1L << 2, esc_x, &data);
		if (check_loop(&data))
			render(&data);
		mlx_loop(data.mlx_ptr);
	}
	clean(&data);
	return (0);
}
