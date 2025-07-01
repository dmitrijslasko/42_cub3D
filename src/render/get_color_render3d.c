/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_render3d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:12 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:09:13 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color_render3d(t_data *dt, t_ray *ray, t_coor *tex_coor)
{
	int			color;
	int			tex_index;
	t_texture	texture;

	texture = dt->map.wall_tile[ray->wall_type].texture;
	tex_coor->x = (texture.width * ray->percentage_of_image);
	tex_index = texture.width * tex_coor->y + tex_coor->x;
	if (ray->cell_type == DOOR_VERTICAL)
	{
		texture = dt->map.door.texture;
		if (ray->vector.x > 0)
			tex_index = texture.width * (tex_coor->y + \
						(ray->percentage_of_image - ray->door->open_progress));
		else
			tex_index = texture.width * (tex_coor->y + \
				(1.0f - ray->percentage_of_image - ray->door->open_progress));
	}
	color = texture.texture_data[tex_index];
	if (ENABLE_SHADERS)
		apply_distance_shadow(ray, &color);
	return (color);
}
