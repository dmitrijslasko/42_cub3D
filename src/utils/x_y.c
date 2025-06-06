/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_y.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:18:05 by fvargas           #+#    #+#             */
/*   Updated: 2025/06/06 10:37:08 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	max_double(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

void	set_values_x_y(t_x_y *new, double x, double y)
{
	new->x = x;
	new->y = y;
}

void	set_value_coor(t_coor *new, double x, double y)
{
	new->x = x;
	new->y = y;
}
