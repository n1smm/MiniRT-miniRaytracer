/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:25:24 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/13 09:50:00 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	j;
	size_t	x;
	size_t	y;

	j = ft_strlen(s2);
	x = 0;
	y = 0;
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + j + 1));
	if (!s3)
		return (NULL);
	while (x < ft_strlen(s1))
	{
		s3[y] = s1[y];
		y++;
		x++;
	}
	while (y < (ft_strlen(s1) + j))
	{
		s3[y] = s2[y - ft_strlen(s1)];
		y++;
	}
	s3[y] = '\0';
	return ((char *)s3);
}
