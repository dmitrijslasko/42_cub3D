/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door_hit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:50 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:07:51 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_door_hit(t_data *dt, t_ray *ray, t_coor *map)
{
	int	door_hit;

	door_hit = ray_hits_door(dt, map, ray);
	if (ray->door_hit_coor.y < ray->door->cell_y + ray->door->open_progress)
		return (0);
	return (door_hit);
}
