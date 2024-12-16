/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:37:40 by pgiorgi           #+#    #+#             */
/*   Updated: 2024/11/29 14:45:34 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strchrint(const char c, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	if (!s1 || s1[0] == 0)
		return (0);
	while (s1[i] && ft_strchrint(s1[i], set))
		i++;
	x = ft_strlen(s1) - 1;
	while (x > i && ft_strchrint(s1[x], set))
		x--;
	s2 = (char *)malloc(sizeof(char) * (x - i) + 2);
	if (!s2)
		return (0);
	while (i < (x + 1))
	{
		s2[j] = s1[i];
		j++;
		i++;
	}
	s2[j] = '\0';
	return (s2);
}
