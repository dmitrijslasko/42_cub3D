#include "cub3d.h"

void	draw_minimap_grid(t_data *dt)
{
	int	col_px;
	int	row_px;

	row_px = 0;
	while (row_px <= dt->map.map_size_rows * MINIMAP_GRID_SIZE + 1)
	{
		col_px = 0;
		while (col_px <= dt->map.map_size_cols * MINIMAP_GRID_SIZE + 1)
		{
			if (col_px % MINIMAP_GRID_SIZE == 0 || \
						row_px % MINIMAP_GRID_SIZE == 0)
				img_pix_put(dt->minimap_base_img, col_px,
					row_px, MINIMAP_GRID_COLOR);
			col_px++;
		}
		row_px++;
	}
}
