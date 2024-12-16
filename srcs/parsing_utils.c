/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:39:45 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 16:40:03 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

char	*check_line(char *line)
{
	int		i;
	char	*res;

	i = 0;
	while (line[i] && line[i] != '#')
		i++;
	if (i == 0)
	{
		free(line);
		return (NULL);
	}
	if (line[i] == 0 && i > 0)
		return (line);
	res = ft_substr(line, 0, i);
	free(line);
	line = ft_strtrim(res, " ");
	free(res);
	if (line[0] == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
