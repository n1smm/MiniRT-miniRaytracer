/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:02:45 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/25 12:10:10 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*new_node;

	current = *lst;
	new_node = *lst;
	if (!lst || !del)
		return ;
	while (current)
	{
		new_node = new_node->next;
		del(current->content);
		free(current);
		current = new_node;
	}
	*lst = NULL;
}
