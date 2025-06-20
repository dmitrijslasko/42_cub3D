#include "cub3d.h"

bool	create_double_array(char ***array, size_t size_row, size_t size_col)
{
	size_t	curr_col;
	size_t	curr_row;
	char	**new;

	curr_row = 0;
	new = malloc((size_row + 1) * sizeof(char *));
	if (!new)
		return (error_message("Malloc error.", 1));
	new[size_row] = NULL;
	while (curr_row < size_row)
	{
		new[curr_row] = malloc((size_col + 1) * sizeof(char));
		if (!new[curr_row])
			return (error_message("Malloc error.", 1));
		new[curr_row][size_col] = '\0';
		curr_col = 0;
		while (curr_col < size_col)
			new[curr_row][curr_col++] = ' ';
		curr_row++;
	}
	*array = new;
	return (0);
}

bool	create_map_data(t_map *map)
{
	return (create_double_array(&map->map_data, map->map_size_rows, \
								map->map_size_cols));
}
