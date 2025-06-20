#include "cub3d.h"

void	set_delta_dist(t_x_y *delta_dis, t_x_y direction)
{
	delta_dis->x = fabs(1 / direction.x);
	delta_dis->y = fabs(1 / direction.y);
}
