#include "cub3d.h"

void	draw_vector(t_data *dt, t_coor origin, t_x_y dir, int stop_at_wall)
{
	t_coor curr;
	t_coor prev;
	float step_size = 1.0; // 1 px per step
	float length = 0.0;
	float max_length = MINIMAP_GRID_SIZE * 100;
	t_x_y pos = { origin.x, origin.y };

	while (length < max_length)
	{
		int grid_x = (int)(pos.x / MINIMAP_GRID_SIZE);
		int grid_y = (int)(pos.y / MINIMAP_GRID_SIZE);

		if (dt->map->map_data[grid_y][grid_x] == '1')
			break;

		prev = curr;
		curr.x = (int)pos.x;
		curr.y = (int)pos.y;

		if (length > 0)
			draw_line(dt, prev, curr, stop_at_wall);

		pos.x += dir.x * step_size;
		pos.y += dir.y * step_size;
		length += step_size;
	}
}

