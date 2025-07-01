/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:00 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:06:01 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_minimap(t_data *dt)
{
	int	dx;
	int	dy;

	draw_background(dt->minimap, MINIMAP_WALL_CELL_COLOR);
	dx = MINIMAP_SIZE / 2 - dt->player.pos.x * MINIMAP_GRID_SIZE;
	dy = MINIMAP_SIZE / 2 - dt->player.pos.y * MINIMAP_GRID_SIZE;
	put_img_to_img(dt->minimap, dt->minimap_base_img, dx, dy);
	draw_minimap_player(dt);
	if (MINIMAP_RENDER_RAYS_ENABLE)
		draw_minimap_rays(dt, 0);
	if (MINIMAP_DIRECTION_RAY_ENABLE)
		draw_minimap_rays(dt, 1);
	return (EXIT_SUCCESS);
}
