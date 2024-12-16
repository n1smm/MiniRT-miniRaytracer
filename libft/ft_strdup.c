/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:36:22 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/12 17:10:25 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*i;
	size_t	j;
	size_t	z;

	j = 0;
	z = 0;
	while (s[z])
	{
		z++;
	}
	i = (char *) malloc(sizeof(char) * z + 1);
	if (!i)
		return (NULL);
	while (s[j])
	{
		i[j] = s[j];
		j++;
	}
	i[j] = '\0';
	return ((char *)i);
}
