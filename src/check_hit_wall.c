#include "cub3d.h"

bool	check_hit_wall(t_coor coord, t_map map, t_ray *ray)
{
	if (map.map_data[coord.y][coord.x] == '1')
	{
		ray->wall_type = -1;
		return (1);
	}
	if (map.map_data[coord.y][coord.x] == 'D')
	{
		ray->wall_type = 7;
		return (1);
	}
	return (0);
}
