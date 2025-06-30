#include "cub3d.h"

void	print_level_map(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	printf(TXT_YELLOW "Printing out the level map->..\n" TXT_RESET);
	print_separator(1, DEF_SEPARATOR_CHAR);
	if (!map->map_data[0] || !map->map_data[0][0])
		return ;
	while (row < map->map_size_rows)
	{
		col = 0;
		while (col < map->map_size_cols)
		{
			printf("%c ", map->map_data[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
	print_separator_default();
}
