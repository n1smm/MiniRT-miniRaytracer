/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:06:24 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/10 19:06:26 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include <math.h>

t_vect	abs_vect(t_vect vect)
{
	vect.x = fabs(vect.x);
	vect.y = fabs(vect.y);
	vect.z = fabs(vect.z);
	return (vect);
}
