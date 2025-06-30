
#include "cub3d.h"

void	set_wall_type(t_ray *ray)
{
	int		wall_type;
	char	hit_side;

	hit_side = ray->hit_side;

	if (hit_side == 'y' && ray->vector.y < 0)
		wall_type = SOUTH;
	else if (hit_side == 'y')
		wall_type = NORTH;
	else if (hit_side == 'x' && ray->vector.x < 0)
		wall_type = EAST;
	else
		wall_type = WEST;

	ray->wall_type = wall_type;
}
