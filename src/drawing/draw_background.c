#include "cub3d.h"

void	draw_background(t_img *img, int color)
{
	int	current_x;
	int	current_y;
	int width;
	int height;

	current_y = 0;
	width = img->width;
	height = img->height;

	while (current_y < width)
	{
		current_x = 0;
		while (current_x < height)
		{
			img_pix_put(img, current_x, current_y, color);
			++current_x;
		}
		++current_y;
	}
}
