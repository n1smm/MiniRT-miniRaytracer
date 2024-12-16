/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:28:28 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/11 17:01:51 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (s[i])
	{
		while (s[i])
		{
			if (s[i] == (unsigned char)c)
			{
				return ((char *)s + i);
			}
			i++;
		}
	}
	if (s[i] == (unsigned char)c)
	{
		return ((char *)s + i);
	}
	if (!c)
		return (NULL);
	return (0);
}
