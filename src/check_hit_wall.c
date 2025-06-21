#include "cub3d.h"

char	get_cell_type(t_map *map, t_coor *coord)
{
	return (map->map_data[coord->y][coord->x]);
}

// NOTE DL: should we remove the first if?
bool	check_hit_wall(t_coor *coord, t_map *map, t_ray *ray)
{
	char	tile;

	tile = get_cell_type(map, coord);
	if (tile == '1')
		return (1);
	if (ray->vector.x > 0)
	{
		if (tile == 'v')
			return (1);
	}
	return (0);
}

