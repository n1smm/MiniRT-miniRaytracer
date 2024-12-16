/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:13:12 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/20 11:09:57 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "ft_substr.c"

static void	free_mem(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

static size_t	count_sub(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	return (count);
}

char	**strazio(char const *s, char c, char **split, size_t i)
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
			while (s[i + len] && s[i + len] != c)
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

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;

	i = 0;
	split = (char **)ft_calloc((count_sub(s, c) + 1), (sizeof(char *)));
	if (!split)
		return (NULL);
	return (strazio(s, c, split, i));
}
