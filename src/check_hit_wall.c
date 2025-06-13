#include "cub3d.h"

// NOTE DL: should we remove the first if?
bool	check_hit_wall(t_coor coord, t_map map, t_ray *ray)
{
	if (map.map_data[coord.y][coord.x] == '1')
	{
		ray->wall_type = NORTH;
		return (1);
	}
	if (map.map_data[coord.y][coord.x] == 'D')
	{
		ray->wall_type = DOOR;
		return (1);
	}
	return (0);
}

