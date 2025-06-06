#include "cub3d.h"

void	draw_grid(t_img *img, int grid_size, int grid_color)
{
	int	current_x;
	int	current_y;

	current_y = 0;
	while (current_y < WINDOW_H)
	{
		current_x = 0;
		while (current_x < WINDOW_W)
		{
			if (current_x % grid_size == 0 || current_y % grid_size == 0)
				img_pix_put(img, current_x, current_y, grid_color);
			++current_x;
		}
		++current_y;
	}
}

