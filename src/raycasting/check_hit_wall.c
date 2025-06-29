#include "cub3d.h"

char	get_cell_type(t_map *map, t_coor *map_coor)
{
	return (map->map_data[map_coor->y][map_coor->x]);
}

char	get_cell_type_by_coordinates(t_map *map, size_t y, size_t x)
{
	return (map->map_data[y][x]);
}

// NOTE DL: should we remove the first if?
bool	check_hit_wall(t_coor *map_coor, t_map *map, t_ray *ray, char side)
{
	char	tile;
	char	neighbour_right;

	tile = get_cell_type(map, map_coor);
	neighbour_right = get_cell_type_by_coordinates(map, map_coor->y, map_coor->x + 1);

	if (side == 'x' && ray->vector.x > 0)
	{
		if (tile == 'v')
			return (1);
	}
	else if (side == 'x' && ray->vector.x < 0)
	{
		if (neighbour_right == 'v')
			return (1);
	}
	if (tile == '1')
		return (1);

	return (0);
}

