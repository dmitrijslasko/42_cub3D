#include "cub3d.h"

void	copy_line(t_map *map, int row, char *line)
{
	size_t	col;

	col = 0;
	while (line && line[col] && col < map->map_size_cols)
	{
		map->map_data[row][col] = line[col];
		col++;
	}
}

void	get_value_map(char *line, int fd, t_map *map)
{
	size_t	count_row;

	count_row = 0;
	while (line && !is_empty_line(line))
	{
		copy_line(map, count_row, line);
		line = free_line_get_next(line, fd);
		count_row++;
	}
}
