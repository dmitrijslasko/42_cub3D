#include "cub3d.h"

bool	check_valid_map_start_line(t_map *map, t_coor pos, int step)
{
	while ((size_t)pos.y < map->map_size_rows && pos.y >= 0)
	{
		while ((size_t)pos.x < map->map_size_cols && pos.x >= 0)
		{
			if (map->map_data[pos.y][pos.x] == 0)
				return (error_message("Error: Line is not correct", 0));
			else if (map->map_data[pos.y][pos.x] == 1)
				continue ;
			pos.x += step;
		}
		pos.y += step;
	}
	return (1);
}

bool	check_valid_map_start_col(t_map *map, t_coor pos, int step)
{
	while ((size_t)pos.x < map->map_size_rows && pos.x >= 0)
	{
		while ((size_t)pos.y < map->map_size_cols && pos.y >= 0)
		{
			if (map->map_data[pos.y][pos.x] == 0)
				return (error_message("Error: Column is not correct", 0));
			else if (map->map_data[pos.y][pos.x] == 1)
				continue ;
			pos.y += step;
		}
		pos.x += step;
	}
	return (1);
}
