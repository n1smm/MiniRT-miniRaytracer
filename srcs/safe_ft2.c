/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_ft2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:31:42 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/16 10:38:56 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

bool	check_extension(char *file_name)
{
	char	**check;
	bool	is_extension;
	int		i;

	i = 0;
	is_extension = false;
	check = ft_split(file_name, '.');
	while (check[i])
		i++;
	if (i != 2)
		is_extension = false;
	else if (ft_strncmp(check[1], "rt", 3) == 0)
		is_extension = true;
	free_mtx(check);
	return (is_extension);
}

int	atoi_wrapper(char *input, t_data *data, int min, int max)
{
	int	res;
	int	i;

	res = 0;
	i = res;
	res = ft_atoi(input);
	while (input[i])
	{
		if (!ft_isdigit(input[i++]))
		{
			if (!(input[i - 1] == '-' || input[i - 1] == '+'))
			{
				printf("wrong dig: %c at %s\n  ", input[i], input);
				data->not_number = true;
			}
		}
	}
	if (res > max || res < min)
		data->not_number = true;
	return (res);
}

int	atol_parsers(char *input, t_data *data)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
		{
			if (!(input[i] == '.' || input[i] == '-' || input[i] == '+'))
			{
				printf("wrong dig: %c in input: %s ", input[i], input);
				data->not_number = true;
			}
		}
		if (input[i++] == '.')
			point++;
	}
	return (point);
}

double	atol_wrapper(char *input, t_data *data, double min, double max)
{
	double	res;
	int		point;

	res = 0;
	point = 0;
	res = ft_atol(input);
	point = atol_parsers(input, data);
	if (res > max || res < min || point > 1)
		data->not_number = true;
	return (res);
}

bool	cmp_wrapper(char *cmp, char *input, int i, t_data *data)
{
	bool	match;
	int		len;

	match = false;
	len = ft_strlen(cmp);
	if (ft_strncmp(cmp, input, len) == 0)
		match = true;
	if (match == true)
	{
		if (input[len] != ' ')
		{
			write(2, "invalid line\n", 13);
			data->invalid = true;
		}
	}
	data = data;
	return (match);
}
