#include "cub3d.h"

char	get_cell_type(t_map *map, t_coor *coord)
{
	return (map->map_data[coord->y][coord->x]);
}

char	get_cell_type_by_coordinates(t_map *map, size_t y, size_t x)
{
	return (map->map_data[y][x]);
}

// NOTE DL: should we remove the first if?
bool	check_hit_wall(t_coor *coord, t_map *map, t_ray *ray, char side)
{
	char	tile;
	char	neighbour_right;

	tile = get_cell_type(map, coord);
	neighbour_right = get_cell_type_by_coordinates(map, coord->y, coord->x + 1);

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
	if (tile == '1' || tile == '|')
		return (1);

	return (0);
}

