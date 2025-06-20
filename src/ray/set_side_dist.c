#include "cub3d.h"

void	set_side_dist(t_x_y *side_dist, t_x_y dir_vec, t_x_y pos_player, \
						t_x_y delta_dist)
{
	t_coor	coor;

	coor = get_values_coor(pos_player.x, pos_player.y);
	if (dir_vec.x < 0)
		side_dist->x = (pos_player.x - coor.x) * delta_dist.x;
	else
		side_dist->x = (coor.x + 1 - pos_player.x) * delta_dist.x;
	if (dir_vec.y < 0)
		side_dist->y = (pos_player.y - coor.y) * delta_dist.y;
	else
		side_dist->y = (coor.y + 1 - pos_player.y) * delta_dist.y;
}
