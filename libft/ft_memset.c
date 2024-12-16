/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:33:18 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/09 14:46:00 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char) c;
		i++;
	}
	return (s);
}

/*int	main(void)
{
	char str[] = "jsadiojsdascmokma";
	ft_memset(str, 'o', 7);
	ft_printf("%s", str);

}*/
