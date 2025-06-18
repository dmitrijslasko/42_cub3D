#include "cub3d.h"

size_t	count_elements_in_the_map(t_map map, char *element)
{
	size_t	row;
	size_t	col;
	size_t	element_count;

	element_count = 0;
	row = 0;
	while (row < map.map_size_rows)
	{
		col = 0;
		while (col < map.map_size_cols)
		{
			if (ft_strchr(element, map.map_data[row][col]))
				element_count++;
			col++;
		}
		row++;
	}
	return (element_count);
}
