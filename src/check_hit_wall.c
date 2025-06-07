#include "cub3d.h"

bool	check_hit_wall(t_coor coord, t_map map)
{
	if (map.map_data[coord.y][coord.x] == '1')
		return (1);
	return (0);
}
