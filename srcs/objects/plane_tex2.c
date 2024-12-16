/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_tex2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:47:52 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 18:05:20 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <stdbool.h>

void	choose_dir2(t_hitinfo *hit, t_pltex *tx)
{
	if (!((tx->dot1 > tx->dot3) && !(tx->dot1 > tx->dot2))
		&& (tx->dot2 < tx->dot3))
	{
		tx->u = fmod(hit->p.y / SQUARE, 1.0);
		tx->v = fmod(hit->p.x / SQUARE, 1.0);
		tx->orientation = false;
	}
	else
	{
		tx->u = fmod(hit->p.y / SQUARE, 1.0);
		tx->v = fmod(hit->p.z / SQUARE, 1.0);
		tx->orientation = false;
	}
}

void	choose_dir(t_hitinfo *hit, t_pltex *tx)
{
	if (!((tx->dot1 > tx->dot3) && !(tx->dot1 > tx->dot2))
		&& (tx->dot2 > tx->dot3))
	{
		tx->u = fmod(hit->p.x / SQUARE, 1.0);
		tx->v = fmod(hit->p.z / SQUARE, 1.0);
		tx->orientation = true;
	}
	else if ((tx->dot1 > tx->dot3) && !(tx->dot1 > tx->dot2))
	{
		tx->u = fmod(hit->p.z / SQUARE, 1.0);
		tx->v = fmod(hit->p.x / SQUARE, 1.0);
		tx->orientation = true;
	}
	else
		choose_dir2(hit, tx);
}

void	choose_sqr(t_picture pic, t_pltex *tx)
{
	if (tx->u < 0)
		tx->u += 1.0;
	if (tx->v < 0)
		tx->v += 1.0;
	if (tx->orientation)
	{
		tx->tex_x = (int)(tx->u * pic.w);
		tx->tex_y = (int)(tx->v * pic.h);
	}
	else
	{
		tx->tex_y = (int)(tx->u * pic.w);
		tx->tex_x = (int)(tx->v * pic.h);
	}
}

t_rgb	tex_color_plane(t_plane *plane, t_hitinfo *hit, t_picture pic)
{
	t_pltex	tx;

	tx.orientation = false;
	tx.dot1 = fabs(dot_product(plane->vect, create_vector(1, 0, 0)));
	tx.dot2 = fabs(dot_product(plane->vect, create_vector(0, 1, 0)));
	tx.dot3 = fabs(dot_product(plane->vect, create_vector(0, 0, 1)));
	choose_dir(hit, &tx);
	choose_sqr(pic, &tx);
	tx.color_offset = tx.tex_y * pic.line_len + tx.tex_x * (pic.bpp / 8);
	tx.color = *(int *)(pic.data + tx.color_offset);
	tx.color_v = extract_color_from_int(tx.color);
	return (tx.color_v);
}
