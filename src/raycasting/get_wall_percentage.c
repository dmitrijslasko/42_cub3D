/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_percentage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:48 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:07:49 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_perc_wall(t_x_y *pos_player, t_ray *ray)
{
	float	wall_perc;

	if (ray->wall_type == WEST || ray->wall_type == EAST)
		wall_perc = pos_player->y + ray->distance_to_wall * ray->vector.y;
	else
		wall_perc = pos_player->x + ray->distance_to_wall * ray->vector.x;
	wall_perc -= (int) wall_perc;
	if (ray->wall_type == NORTH || ray->wall_type == EAST)
		wall_perc = 1.0f - wall_perc;
	ray->percentage_of_image = wall_perc;
}
