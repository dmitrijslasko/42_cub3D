#include "cub3d.h"

int	draw_minimap_map(t_data *dt)
{
	t_map	*map;
	size_t	curr_row;
	size_t	curr_col;
	int		color;

	t_coor top_left;
	t_coor bottom_right;

	set_coor_values(&top_left, MINIMAP_OFFSET_X, MINIMAP_OFFSET_Y);
	set_coor_values(&bottom_right, 	MINIMAP_OFFSET_X + dt->map->map_size_cols * MINIMAP_GRID_SIZE,
									MINIMAP_OFFSET_Y + dt->map->map_size_rows * MINIMAP_GRID_SIZE);
	draw_rectangle(dt, top_left, bottom_right, MINIMAP_BACKGROUND_COLOR);

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
			if (ft_strchr("NSWE", dt->map->map_data[curr_row][curr_col]))
				color = MINIMAP_PLAYER_SPAWN_CELL_COLOR;
			else if (ft_strchr("v", dt->map->map_data[curr_row][curr_col]))
				color = MINIMAP_DOOR_COLOR;
			else if (ft_strchr("1", dt->map->map_data[curr_row][curr_col]))
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
	if (MINIMAP_RENDER_RAYS_ENABLE)
		draw_minimap_rays(dt, 0);
	if (MINIMAP_DIRECTION_RAY_ENABLE)
		draw_minimap_rays(dt, 1);
	return (EXIT_SUCCESS);
}
