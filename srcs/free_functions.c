/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:46:58 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/15 19:23:48 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	free_mtx(char **mtx)
{
	int	i;

	i = 0;
	if (mtx == NULL)
		return ;
	while (mtx[i])
		free(mtx[i++]);
	if (i != 0)
		free(mtx);
}

void	free_all_mtx(char **mtx1, char **mtx2, char **mtx3, char **mtx4)
{
	if (mtx4 != NULL)
	{
		free_mtx(mtx4);
		mtx4 = NULL;
	}
	if (mtx3 != NULL)
	{
		free_mtx(mtx3);
		mtx3 = NULL;
	}
	if (mtx2 != NULL)
	{
		free_mtx(mtx2);
		mtx2 = NULL;
	}
	if (mtx1 != NULL)
	{
		free_mtx(mtx1);
		mtx1 = NULL;
	}
}

/* void free_ptr_mtx(char ***mtx) */
/* { */
/*     int i; */

/*     if (mtx == NULL || *mtx == NULL) */
/*     { */
/*         printf("Pointer is NULL, skipping free\n"); */
/*         return ; */
/*     } */

/*     printf("Attempting to free matrix at %p\n", (void*)*mtx); */

/*     i = 0; */
/*     while ((*mtx)[i]) */
/*     { */
/*         printf("Freeing row %d at %p\n", i, (void*)(*mtx)[i]); */
/*         free((*mtx)[i]); */
/*         i++; */
/*     } */

/*     printf("Freeing matrix\n"); */
/*     free(*mtx); */
/*     *mtx = NULL; */
/* } */

/* void free_all_mtx(char ***mtx1, char ***mtx2, char ***mtx3, char ***mtx4) */
/* { */
/*     printf("Entering free_all_mtx\n"); */

/*     if (mtx4 && *mtx4 && (*mtx4)[0]) */
/*     { */
/*         printf("Freeing mtx4\n"); */
/*         free_ptr_mtx(mtx4); */
/*     } */
/*     if (mtx3 && *mtx3 && (*mtx3)[0]) */
/*     { */
/*         printf("Freeing mtx3\n"); */
/*         free_ptr_mtx(mtx3); */
/*     } */
/*     if (mtx2 && *mtx2 && (*mtx2)[0]) */
/*     { */
/*         printf("Freeing mtx2\n"); */
/*         free_ptr_mtx(mtx2); */
/*     } */
/*     if (mtx1 && *mtx1 && (*mtx1)[0]) */
/*     { */
/*         printf("Freeing mtx1\n"); */
/*         free_ptr_mtx(mtx1); */
/*     } */
/* } */

/* void	free_ptr_mtx(char ***mtx) */
/* { */
/* 	int	i; */

/* 	if (mtx == NULL || *mtx == NULL) */
/* 		return ; */
/* 	i = 0; */
/* 	while ((*mtx)[i]) */
/* 		free((*mtx)[i++]); */
/* 	free(*mtx); */
/* 	mtx = NULL; */
/* } */

/* void	free_all_mtx(char ***mtx1, char ***mtx2, char ***mtx3, char ***mtx4) */
/* { */
/* 	if (*mtx4 && (*mtx4)[0]) */
/* 		free_ptr_mtx(mtx4); */
/* 	if (*mtx3 && (*mtx3)[0]) */
/* 		free_ptr_mtx(mtx3); */
/* 	if (*mtx2 && (*mtx2)[0]) */
/* 		free_ptr_mtx(mtx2); */
/* 	if (*mtx1 && (*mtx1)[0]) */
/* 		free_ptr_mtx(mtx1); */
/* } */
