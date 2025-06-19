#include "cub3d.h"

bool	create_map_data(t_map *map)
{
	size_t	curr_col;
	size_t	curr_row;

	curr_row = 0;
	map->map_data = malloc((map->map_size_rows + 1) * sizeof(char *));
	if (!map->map_data)
		return (error_message("Malloc error.", 1));
	map->map_data[map->map_size_rows] = NULL;  // null-terminate row array
	while (curr_row < map->map_size_rows)
	{
		map->map_data[curr_row] = malloc((map->map_size_cols + 1) * sizeof(char));  // +1 for '\0'
		if (!map->map_data[curr_row])
			return (error_message("Malloc error.", 1));
		map->map_data[curr_row][map->map_size_cols] = '\0';
		curr_col = 0;
		while (curr_col < map->map_size_cols)
			map->map_data[curr_row][curr_col++] = ' ';
		curr_row++;
	}
	return (0);
}
