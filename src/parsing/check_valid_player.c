#include "cub3d.h"

bool	is_valid_position(t_map *map, size_t x, size_t y)
{
	if (x == 0 || x == map->map_size_cols)
		return (0);
	if (y == 0 || y == map->map_size_rows)
		return (0);
	if (map->map_data[y][x - 1] == ' ' || map->map_data[y][x + 1] == ' ')
		return (0);
	if (map->map_data[y - 1][x] == ' ' || map->map_data[y + 1][x] == ' ')
		return (0);
	return (1);
}

bool	check_valid_player(t_map *map)
{
	int		count;

	count = count_elements_in_the_map(map, "NSWE");
	if (count == 0)
		return (error_message("Error: Player not found.", 0));
	else if (count > 1)
		return (error_message("Error: Multi player->", 0));
	// if (!is_valid_position(*dt->map, x, y))
	// 	return (error_message("Error: Not valid player position,", 0));
	return (1);
}
