#include "cub3d.h"

void	print_level_map(t_map *map)
{
	printf(TXT_YELLOW "Printing out the level map...\n" TXT_RESET);
	print_separator(1, DEF_SEPARATOR_CHAR);
	if (!map || !map->map_data[0] || !map->map_data[0][0])
		return ;
	for(size_t y = 0; y < map->map_size_cols; y++)
	{
		for (size_t x = 0; x < map->map_size_rows; x++)
			printf("%c ", map->map_data[y][x]);
		printf("\n");
	}
	print_separator(1, DEF_SEPARATOR_CHAR);
}
