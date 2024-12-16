/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:22:31 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/09 13:34:05 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_c;
	const unsigned char	*src_c;

	dest_c = (unsigned char *) dest;
	src_c = (const unsigned char *) src;
	if (src == NULL && dest == NULL)
		return (0);
	if (src_c < dest_c && dest_c < src_c + n)
	{
		src_c += n;
		dest_c += n;
		while (n--)
		{
			*(--dest_c) = *(--src_c);
		}
	}
	else
	{
		while (n--)
		{
			*dest_c++ = *src_c++;
		}
	}
	return (dest);
}
