/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_percentage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:22:10 by fvargas           #+#    #+#             */
/*   Updated: 2025/06/09 13:25:12 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_perc_wall(t_x_y pos_player, t_x_y direction, float dist_ray, \
							t_type_wall type_wall)
{
	float	wall_perc;

	if (type_wall == WEST || type_wall == EAST)
		wall_perc = pos_player.y + dist_ray * direction.y;
	else
		wall_perc = pos_player.x + dist_ray * direction.x;
	wall_perc -= (int) wall_perc;
	return (wall_perc);
}
