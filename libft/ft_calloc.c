/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:06:41 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/12 17:27:46 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	z;
	void	*j;

	i = (nmemb * size);
	z = 0;
	j = malloc(i);
	if (!j)
		return (0);
	if (nmemb > 4294967295)
		return (0);
	while (z < i)
	{
		((char *)j)[z] = '\0';
		z++;
	}
	return (j);
}
