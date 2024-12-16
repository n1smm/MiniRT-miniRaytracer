/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:24:31 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/11 18:20:49 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1s;
	unsigned char	*s2s;
	size_t			i;

	s1s = (unsigned char *)s1;
	s2s = (unsigned char *)s2;
	i = 0;
	if (n <= 0)
		return (0);
	while (i < n && s1s[i] == s2s[i])
	{
		i++;
	}
	if (i == n)
	{
		i--;
	}
	return (s1s[i] - s2s[i]);
}
