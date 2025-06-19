#include "cub3d.h"

void	draw_minimap_grid(t_data *dt)
{
	size_t	current_x;
	size_t	current_y;

	current_y = 0;
	while (current_y <= dt->map->map_size_rows * MINIMAP_GRID_SIZE)
	{
		current_x = 0;
		while (current_x <= dt->map->map_size_cols * MINIMAP_GRID_SIZE)
		{
			if (current_x % MINIMAP_GRID_SIZE == 0 || current_y % MINIMAP_GRID_SIZE == 0)
				img_pix_put(dt->minimap, MINIMAP_OFFSET_X + current_x, MINIMAP_OFFSET_Y + current_y, MINIMAP_GRID_COLOR);
			++current_x;
		}
		++current_y;
	}
}

