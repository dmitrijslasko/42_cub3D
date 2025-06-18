#include "cub3d.h"

float	get_dist_wall(char c, t_x_y direction, t_coor map_coor, t_x_y player_pos, t_x_y step)
{
	if (c == 'x')
		return ((map_coor.x - player_pos.x + (1 - step.x) / 2) / direction.x) ;
	return ((map_coor.y - player_pos.y + (1 - step.y) / 2) / direction.y);
}
