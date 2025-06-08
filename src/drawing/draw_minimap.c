#include "cub3d.h"

int	draw_map(t_data *dt)
{
	t_map	*map;
	size_t	curr_row;
	size_t	curr_col;
	int		color;

	map = dt->map;
	curr_row = 0;
	while (curr_row < map->map_size_rows)
	{
		curr_col = 0;
		while (curr_col < map->map_size_cols)
		{
			if (map->map_data[curr_row][curr_col] == '0')
			{
				curr_col++;
				continue ;
			}
			if (map->map_data[curr_row][curr_col] == 'N')
				color = LIME;
			else if (map->map_data[curr_row][curr_col] == '1')
				color = ORANGE;
			draw_square(dt,
						20 + curr_col * DEF_GRID_SIZE,
						20 + curr_row * DEF_GRID_SIZE,
						DEF_GRID_SIZE,
						color);
			curr_col++;
		}
		curr_row++;
	}
	return (0);
}

int draw_minimap(t_data *dt)
{
	draw_map(dt);
	draw_player(dt);
	return (EXIT_SUCCESS);
}
