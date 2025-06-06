/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_coor_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:38:17 by fvargas           #+#    #+#             */
/*   Updated: 2025/06/06 13:38:54 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_coor_pos(int pos, double dir)
{
	if (dir > 0)
		return (pos + 1);
	return (pos);
}

t_coor	get_updated_coor_player(t_x_y pos, t_x_y dir)
{
	int	x;
	int	y;

	x = update_coor_pos((int)pos.x, dir.x);
	y = update_coor_pos((int)pos.y, dir.y);
	return (get_values_coor(x, y));
}
