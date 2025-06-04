#include "cub3d.h"

void	draw_square(t_data *data, int x, int y, int size, int clr)
{
	int	curr_x;
	int	curr_y;

	img_pix_put(data->img, x, y, clr);
	curr_x = x - size / 2;
	while (curr_x <= x + size / 2)
	{
		curr_y = y - size / 2;
		while (curr_y <= y + size / 2)
		{
			if (pixel_is_in_window(curr_x, curr_y))
				img_pix_put(data->img, curr_x, curr_y, clr);
			++curr_y;
		}
		++curr_x;
	}
}
