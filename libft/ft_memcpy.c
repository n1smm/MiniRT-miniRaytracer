/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:17:30 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/09 13:21:54 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (src == NULL && dest == NULL)
		return (0);
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}
