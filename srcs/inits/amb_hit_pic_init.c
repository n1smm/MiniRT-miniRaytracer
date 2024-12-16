/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb_hit_pic_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:57:53 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/15 23:13:58 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_calc	calc_init(void)
{
	t_calc	calc;

	calc.u = 0;
	calc.v = 0;
	calc.tex_x = 0;
	calc.tex_y = 0;
	calc.tex_theta = 0;
	calc.tex_height = 0;
	calc.theta = 0;
	calc.phi = 0;
	calc.square_phi = 0;
	calc.square_theta = 0;
	calc.scale_theta = 0;
	calc.square_height = 0;
	calc.height = 0;
	calc.tex_phi = 0;
	return (calc);
}

t_hitinfo	init_hit(t_data *data)
{
	t_hitinfo	hit;

	hit.p = create_vector(0, 0, 0);
	hit.t = FLT_MAX;
	hit.normal = create_vector(0, 0, 0);
	hit.rgb = data->ambient.rgb;
	hit.calc = calc_init();
	return (hit);
}

void	ambient_init(t_data *data, char *line)
{
	int		i;
	int		j;
	char	**res;
	char	**rgb;

	i = 0;
	i = i;
	j = 0;
	j = j;
	rgb = NULL;
	res = ft_split(line, ' ');
	if (invalid_params(res, 2, data))
		return ;
	data->ambient.ratio = atol_wrapper(res[1], data, 0, 1);
	if (invalid_parts(&rgb, 2, data, res[2]))
	{
		free_mtx(res);
		return ;
	}
	data->ambient.rgb = extract_color(atol_wrapper(rgb[0], data, 0, 255),
			atol_wrapper(rgb[1], data, 0, 255), atol_wrapper(rgb[2], data, 0,
				255));
	free_mtx(rgb);
	free_mtx(res);
}

void	pic_init(t_data *data, char *line, int *nb_pics)
{
	char		**res;
	char		**part;
	t_picture	pic;

	res = ft_split(line, ' ');
	pic.data = NULL;
	if (invalid_params(res, 1, data))
	{
		(*nb_pics)--;
		return ;
	}
	part = ft_split(res[1], ':');
	pic.path = ft_strdup(part[1]);
	pic.pic = mlx_xpm_file_to_image(data->mlx_ptr, pic.path, &pic.w, &pic.h);
	if (pic.pic)
	{
		pic.data = mlx_get_data_addr(pic.pic, &pic.bpp, &pic.line_len,
				&pic.endian);
		pic.index = *nb_pics;
		data->pics[*nb_pics] = pic;
	}
	data->pic_idx = *nb_pics;
	free_mtx(res);
	free_mtx(part);
	return ;
}
