/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:53 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:07:54 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycasting(t_coor *step, t_coor *map_coor,
			t_data *dt, t_ray *ray)
{
	set_step(step, &ray->vector);
	map_coor->x = (int)dt->player.pos.x;
	map_coor->y = (int)dt->player.pos.y;
}
