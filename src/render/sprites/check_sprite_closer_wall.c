#include "cub3d.h"

bool	check_sprite_closer_than_wall(t_data *dt, t_coor *coor, t_sprite *spr)
{
	float	distance_to_wall;

	distance_to_wall = dt->rays[coor->x / (WINDOW_W / CASTED_RAYS_COUNT)] \
													.distance_to_wall;
	if (distance_to_wall * distance_to_wall > spr->distance_to_player)
		return (1);
	return (0);
}
