#include "cub3d.h"

void	draw_circle(t_img *img, int x, int y, int radius, int clr)
{
	int	curr_x;
	int	curr_y;
	int	dx;
	int	dy;

	curr_x = x - radius;
	while (curr_x <= x + radius)
	{
		curr_y = y - radius;
		while (curr_y <= y + radius)
		{
			dx = curr_x - x;
			dy = curr_y - y;
			if (dx * dx + dy * dy <= radius * radius)
			{
				if (pixel_is_in_window(curr_x, curr_y))
					img_pix_put(img, curr_x, curr_y, clr);
			}
			++curr_y;
		}
		++curr_x;
	}
}

