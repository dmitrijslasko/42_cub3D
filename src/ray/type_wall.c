
#include "cub3d.h"

t_type_wall	get_type_wall(char c, t_x_y direction)
{
	if (c == 'y' && direction.y < 0)
		return (SOUTH);
	if (c == 'y')
		return (NORTH);
	if (c == 'x' && direction.x < 0)
		return (EAST);
	return (WEST);
}
