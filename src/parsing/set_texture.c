/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:19 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:07:20 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	set_texture(char *identifier, char *file_texture, t_map *map)
{
	t_wall_type	wall_type;

	wall_type = check_valid_identifier_texture_wall(identifier);
	if (map->wall_tile[wall_type].wall_type != DEFAULT_WALL)
		return (error_msg("Error: duplicated wall/door/floor.", 1));
	map->wall_tile[wall_type].wall_type = wall_type;
	map->wall_tile[wall_type].texture.file = ft_substr(file_texture, 0, \
												ft_strlen(file_texture));
	return (0);
}
