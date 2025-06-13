#include "cub3d.h"

float	get_perc_wall(t_x_y pos_player, t_x_y direction, float dist_ray, \
							t_type_wall type_wall)
{
	float	wall_perc;

	if (type_wall == WEST || type_wall == EAST)
		wall_perc = pos_player.y + dist_ray * direction.y;
	else
		wall_perc = pos_player.x + dist_ray * direction.x;

	wall_perc -= (int) wall_perc;

	if (type_wall == NORTH || type_wall == EAST)
		wall_perc = 1.0f - wall_perc;

	return (wall_perc);
}
