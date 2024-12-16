/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:07:14 by tjuvan            #+#    #+#             */
/*   Updated: 2024/11/28 16:52:58 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
/* for tests */
/* # include <stdio.h> */
/* # include <string.h> */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list_a
{
	char			*content;
	struct s_list_a	*next;
}					t_storage;

/* main file */
char				*copy_to_result(t_storage *root);
int					read_to_storage(int fd, t_storage **root);
void				re_start_list(t_storage **root, char *line, int count,
						int file_read);
char				*get_next_line(int fd);
void				*ft_calloc(unsigned long nmemb, unsigned long size);
int					final_free(t_storage **root, char *rest, char *line,
						int file_read);
/* utils file */
t_storage			*fft_lstlast(t_storage *root);
int					count_line(t_storage *root);
void				fft_lstadd_back(char *content, t_storage **root);
void				deallocate(t_storage **root);
int					check_list(t_storage *root);

#endif
