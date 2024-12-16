/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:50:10 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/09 17:43:26 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	swap_objs(t_objs *a, t_objs *b)
{
	t_objs	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

bool	solve_quadratic(t_data *data, float *x0, float *x1)
{
	float	discr;
	float	q;

	discr = data->b * data->b - 4 * data->a * data->c;
	if (discr < 0)
		return (false);
	else if (discr == 0)
	{
		*x0 = -0.5 * data->b / data->a;
		*x1 = *x0;
	}
	else
	{
		if (data->b > 0)
			q = -0.5 * (data->b + sqrt(discr));
		else
			q = -0.5 * (data->b - sqrt(discr));
		*x0 = q / data->a;
		*x1 = data->c / q;
	}
	if (*x0 > *x1)
		swap(x0, x1);
	return (true);
}
