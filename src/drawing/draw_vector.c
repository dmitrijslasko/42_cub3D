#include "cub3d.h"

void	draw_minimap_ray(t_data *dt, t_coor origin, t_x_y dir, int color)
{
	t_coor	curr;
	t_coor	prev;

	float	step_size = 1.0f;
	int		length;

	length = 0;
	t_x_y pos = {origin.x, origin.y};

	while (length < MINIMAP_GRID_SIZE * MINIMAP_RAY_LENGTH)
	{
		int grid_x = (int)((pos.x - MINIMAP_OFFSET_X) / MINIMAP_GRID_SIZE);
		int grid_y = (int)((pos.y - MINIMAP_OFFSET_Y) / MINIMAP_GRID_SIZE);

		if (dt->map.map_data[grid_y][grid_x] == '1')
			break;

		prev = curr;
		curr.x = (size_t)pos.x;
		curr.y = (size_t)pos.y;

		if (length > 0)
			draw_line(dt, prev, curr, color);

		pos.x += dir.x * step_size;
		pos.y += dir.y * step_size;
		length += step_size;
	}
}

