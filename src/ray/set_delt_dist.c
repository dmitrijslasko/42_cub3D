#include "cub3d.h"

void	set_delta_dist(t_x_y *delta_dis, t_x_y direction)
{
	t_x_y	delta;

	delta.x = fabs(1 / direction.x);
	delta.y = fabs(1 / direction.y);
	set_values_x_y(delta_dis, delta.x, delta.y);
}
