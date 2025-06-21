#include "cub3d.h"

void	set_step(t_x_y *step, t_x_y *dir_vec)
{
	if (dir_vec->x < 0)
		step->x = -1;
	else
		step->x = 1;
	if (dir_vec->y < 0)
		step->y = -1;
	else
		step->y = 1;
}
