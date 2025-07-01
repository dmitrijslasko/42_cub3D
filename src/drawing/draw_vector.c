/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:03 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:04 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_ray(t_data *dt, t_coor origin, t_x_y dir, int color)
{
	t_coor	curr;
	t_x_y	pos;
	t_coor	prev;
	float	step_size;
	int		length;

	length = 0;
	step_size = 1.0f;
	set_values_x_y(&pos, origin.x, origin.y);
	while (length < MINIMAP_GRID_SIZE * MINIMAP_RAY_LENGTH)
	{
		prev = curr;
		curr.x = (size_t)pos.x;
		curr.y = (size_t)pos.y;
		if (length > 0)
			draw_line(dt->minimap, prev, curr, color);
		pos.x += dir.x * step_size;
		pos.y += dir.y * step_size;
		length += step_size;
	}
}
