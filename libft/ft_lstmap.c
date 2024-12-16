/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:07:58 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/25 13:32:03 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*temp;
	void	*result;

	if (!lst || !f || !del)
		return (NULL);
	temp = lst;
	new_node = NULL;
	new_list = NULL;
	while (temp)
	{
		result = f(temp->content);
		new_node = ft_lstnew(result);
		if (!new_node)
		{
			del(result);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		temp = temp->next;
	}
	return (new_list);
}
