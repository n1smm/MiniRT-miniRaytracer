/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:44:22 by tjuvan            #+#    #+#             */
/*   Updated: 2024/11/28 17:00:49 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

t_storage	*fft_lstlast(t_storage *root)
{
	if (!root)
		return (NULL);
	while (root->next != NULL)
		root = root->next;
	return (root);
}

void	deallocate(t_storage **root)
{
	t_storage	*tmp;
	t_storage	*curr;

	curr = *root;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		if (tmp->content != NULL)
			free(tmp->content);
		free(tmp);
	}
	*root = NULL;
}

void	fft_lstadd_back(char *content, t_storage **root)
{
	t_storage	*curr;
	t_storage	*new;

	new = malloc(sizeof(t_storage));
	if (!new || !content)
		return ;
	new->content = content;
	new->next = NULL;
	if (*root == NULL)
	{
		*root = new;
		return ;
	}
	curr = fft_lstlast(*root);
	curr->next = new;
}

int	count_line(t_storage *root)
{
	t_storage	*curr;
	int			count;
	int			count_len;

	curr = root;
	count_len = 0;
	while (curr != NULL)
	{
		count = 0;
		while (curr->content[count] != 0)
		{
			if (curr->content[count] == '\n')
				return (count_len + 1);
			count++;
			count_len++;
		}
		curr = curr->next;
	}
	return (count_len);
}

int	check_list(t_storage *root)
{
	t_storage	*curr;
	int			count;

	curr = fft_lstlast(root);
	if (curr == NULL)
		return (-1);
	while (curr != NULL)
	{
		count = 0;
		while (curr->content[count] != 0)
		{
			if (curr->content[count] == '\n')
				return (0);
			count++;
		}
		curr = curr->next;
	}
	return (1);
}
