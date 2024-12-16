/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:02:59 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/12 16:04:44 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size > 0)
	{
		while (dst[j] && j < size)
		{
			j++;
		}
		while (src[i] && j + i < size - 1)
		{
			dst[j + i] = src[i];
			i++;
		}
		if (j < size)
			dst[j + i] = '\0';
	}
	while (src[i])
		i++;
	return (j + i);
}
