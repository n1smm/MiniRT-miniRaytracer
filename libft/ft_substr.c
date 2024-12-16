/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:09:21 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/12 18:49:12 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	z;
	char	*j;

	i = ft_strlen(s);
	z = 0;
	if (len > (i - start))
		len = (i - start);
	if (start > i)
		start = i;
	if (start == i)
		j = (char *)malloc(sizeof(char));
	else
		j = (char *)malloc((sizeof(char) * len + 1));
	if (!j || !s)
		return (NULL);
	while (z < len && s[start] && start < i)
	{
		j[z++] = s[start++];
	}
	j[z] = '\0';
	return (j);
}
