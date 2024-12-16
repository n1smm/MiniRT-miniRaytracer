/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:09:03 by thiew             #+#    #+#             */
/*   Updated: 2024/12/09 17:14:37 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	free_mem(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

static size_t	count_sub_rt(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != c && s[i] != ' ')
		{
			count++;
			while (s[i] && s[i] != c && s[i] != ' ')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**split_rt(char const *s, char c, char **split, size_t i)
{
	size_t	len;
	size_t	j;

	len = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = 0;
			while (s[i + len] && (s[i + len] != c && s[i + len] != ' ') && s)
				len++;
			split[j++] = ft_substr(s, i, len);
			if (split[j - 1] == NULL)
			{
				free_mem(split, j);
				return (NULL);
			}
			i += len;
		}
		else
			i++;
	}
	return (split);
}

char	**ft_split_rt(char const *s, char c)
{
	char	**split;
	size_t	i;

	i = 0;
	split = (char **)ft_calloc((count_sub_rt(s, c) + 1), (sizeof(char *)));
	if (!split)
		return (NULL);
	return (split_rt(s, c, split, i));
}

int	mtx_count(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
		i++;
	return (i - 1);
}
