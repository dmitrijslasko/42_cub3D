/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:01 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:10:02 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_value_map_data(char *file, t_data *dt)
{
	if (init_default_map(&dt->map))
		return (1);
	if (set_size_map_data(&dt->map, file))
		return (1);
	if (create_map_data(&dt->map, dt))
		return (1);
	if (get_value_file(&dt->map, file))
		return (1);
	if (!check_valid_player(&dt->map))
		return (1);
	return (!check_all_wall_tile(&dt->map));
}
