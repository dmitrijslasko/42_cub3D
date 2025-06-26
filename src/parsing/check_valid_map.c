#include "cub3d.h"

bool	is_open_map(char **map, char **visited, int row, int col)
{
	if (row < 0 || col < 0 || map[row] == NULL || map[row][col] == '\0')
		return (1);
	if (map[row][col] == '1' || visited[row][col] == 'V')
		return (0);
	visited[row][col] = 'V';
	if (is_open_map(map, visited, row + 1, col))
		return (1);
	if (is_open_map(map, visited, row - 1, col))
		return (1);
	if (is_open_map(map, visited, row, col + 1))
		return (1);
	if (is_open_map(map, visited, row, col - 1))
		return (1);
	return (0);
}

bool	check_valid_map(t_map *map, t_player *player)
{
	char	**visited;

	create_double_array(&visited, map->map_size_rows, map->map_size_cols);
	if (is_open_map(map->map_data, visited, (int)player->pos.y, \
											(int)player->pos.x))
		return (error_message_free("Error: Invalid map.", visited, 0));
	return (free_array_return(visited, 1));
}
