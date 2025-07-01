/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:39 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:08:40 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_all_sprites(t_data *dt)
{
	size_t	i;

	i = 0;
	sort_sprites_by_distance(dt);
	set_texture_sprites(dt);
	while (i < dt->sprite_count)
	{
		get_position_and_render_sprite(dt, &dt->sprites[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
