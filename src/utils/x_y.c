/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_y.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:18:05 by fvargas           #+#    #+#             */
/*   Updated: 2025/06/13 22:50:59 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	max_float(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

// TODO FV: rename this function in the future
t_x_y	get_values_x_y(float x, float y)
{
	t_x_y	new;

	new.x = x;
	new.y = y;
	return (new);
}

void	set_values_x_y(t_x_y *new, float x, float y)
{
	new->x = x;
	new->y = y;
}

// TODO FV: rename this function in the future
t_coor	get_values_coor(int x, int y)
{
	t_coor	new;

	new.x = x;
	new.y = y;
	return (new);
}

void	set_value_coor(t_coor *new, int x, int y)
{
	new->x = x;
	new->y = y;
}
