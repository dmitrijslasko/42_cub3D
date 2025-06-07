/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:32:35 by fvargas           #+#    #+#             */
/*   Updated: 2025/06/07 13:52:03 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_step(t_x_y *step, t_x_y dir_vec)
{
	step->x = 1;
	step->y = 1;
	if (dir_vec.x < 0)
		step->x = -1;
	if (dir_vec.y < 0)
		step->y = -1;
}

void	set_side_dist(t_x_y *side_dist, t_x_y dir_vec, t_x_y pos_player, \
						t_x_y delta_dist)
{
	t_coor	coor;
	double	x;
	double	y;

	coor = get_updated_coor_player(pos_player, dir_vec, 1);
	y = 1000000000;
	x = 1000000000;
	if (delta_dist.y != 1000000000)
		y = fabs(coor.y - pos_player.y) * delta_dist.y;
	if (delta_dist.x != 1000000000)
		x = fabs(coor.x - pos_player.x) * delta_dist.x;
	set_values_x_y(side_dist, x, y);
}

void	set_delta_dist(t_x_y *delta_dis, t_x_y direction)
{
	t_x_y	delta;

	delta.x = 1e10;
	if (direction.x != 0)
		delta.x = fabs(1 / direction.x);
	delta.y = 1e10;
	if (direction.y != 0)
		delta.y = fabs(1 / direction.y);
	set_values_x_y(delta_dis, delta.x, delta.y);
}
