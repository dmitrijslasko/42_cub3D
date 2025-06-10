#include "cub3d.h"

void	set_step(t_x_y *step, t_x_y dir_vec)
{
	if (dir_vec.x < 0)
		step->x = -1;
	else
		step->x = 1;
	if (dir_vec.y < 0)
		step->y = -1;
	else
		step->y = 1;
}

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

void	set_delta_dist(t_x_y *delta_dis, t_x_y direction)
{
	t_x_y	delta;

	delta.x = fabs(1 / direction.x);
	delta.y = fabs(1 / direction.y);
	set_values_x_y(delta_dis, delta.x, delta.y);
}
