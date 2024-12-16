/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:29:51 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/07/27 18:15:28 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)

{
	size_t	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char	c[];

	c[] = "AAAAHHHH!!!!";
	ft_printf("%d", ft_strlen(c));
	return (0);
}*/
