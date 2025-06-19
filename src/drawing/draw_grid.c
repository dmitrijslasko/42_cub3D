#include "cub3d.h"

void	draw_minimap_grid(t_data *dt)
{
	size_t	col;
	size_t	row;

	row = 0;
	while (row <= dt->map->map_size_rows * MINIMAP_GRID_SIZE)
	{
		col = 0;
		while (col <= dt->map->map_size_cols * MINIMAP_GRID_SIZE)
		{
			if (col % MINIMAP_GRID_SIZE == 0 || row % MINIMAP_GRID_SIZE == 0)
				img_pix_put(dt->img, MINIMAP_OFFSET_X + col, MINIMAP_OFFSET_Y + row, MINIMAP_GRID_COLOR);
			++col;
		}
		++row;
	}
}

