/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:14:52 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/17 16:08:54 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l_len;

	l_len = ft_strlen(little);
	i = 0;
	if (l_len == 0 || little == NULL)
		return ((char *)big);
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (j < l_len && (i + j) < len && big[i + j] == little[j])
				j++;
			if (j == l_len)
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
