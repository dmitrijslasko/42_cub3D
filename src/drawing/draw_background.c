#include "cub3d.h"

void	draw_background(t_img *img, int clr)
{
	int	current_x;
	int	current_y;

	current_y = 0;
	while (current_y < WINDOW_H)
	{
		current_x = 0;
		while (current_x < WINDOW_W)
		{
			img_pix_put(img, current_x, current_y, clr);
			++current_x;
		}
		++current_y;
	}
	//printf("Background rendered...\n");
}
