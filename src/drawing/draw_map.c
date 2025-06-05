#include "cub3d.h"

int	draw_map(t_data *dt)
{
	t_map	*map;
	size_t	curr_row;
	size_t	curr_col;

	map = dt->map;
	curr_row = 0;
	while (curr_row < map->map_size_rows)
	{
		curr_col = 0;
		while (curr_col < map->map_size_cols)
		{
			printf("Cell value: %c\n", map->map_data[curr_row][curr_col]);
			curr_col++;
		}
		curr_row++;
	}
	return (0);
}
