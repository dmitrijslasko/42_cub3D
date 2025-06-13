#include "cub3d.h"

int	draw_minimap_map(t_data *dt)
{
	t_map	*map;
	size_t	curr_row;
	size_t	curr_col;
	int		color;

	draw_square_from_top_left(dt, MINIMAP_OFFSET_X, MINIMAP_OFFSET_Y, (dt->map->map_size_cols) * MINIMAP_GRID_SIZE, MINIMAP_BACKGROUND_COLOR);
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
				color = MINIMAP_PLAYER_SPAWN_CELL_COLOR;
			else if (map->map_data[curr_row][curr_col] == 'D')
				color = MINIMAP_DOOR_COLOR;
			else if (map->map_data[curr_row][curr_col] == '1')
				color = MINIMAP_WALL_CELL_COLOR;

			draw_square_from_top_left(dt,
						MINIMAP_OFFSET_X + curr_col * MINIMAP_GRID_SIZE,
						MINIMAP_OFFSET_Y + curr_row * MINIMAP_GRID_SIZE,
						MINIMAP_GRID_SIZE,
						color);
			curr_col++;
		}
		curr_row++;
	}
	return (EXIT_SUCCESS);
}

int draw_minimap(t_data *dt)
{
	draw_minimap_map(dt);
	if (MINIMAP_GRID_ENABLE)
		draw_minimap_grid(dt);
	draw_minimap_player(dt);
	if (MINIMAP_DIRECTION_RAY_ENABLE)
		draw_minimap_rays(dt, 0);
	if (MINIMAP_RENDER_RAYS_ENABLE)
	draw_minimap_rays(dt, 1);

	return (EXIT_SUCCESS);
}
