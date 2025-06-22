#include "cub3d.h"

int test_render_sprite(t_data *dt)
{
	if (!dt->sprites || !dt->sprites[0].sprite_data)
	{
		// printf("Sprite data not loaded!\n");
		return (EXIT_FAILURE);
	}

	int offset_x = WINDOW_W / 2;
	int offset_y = WINDOW_H / 2;

	for (int row = 0; row < dt->sprites[0].height; row++)
	{
		for (int col = 0; col < dt->sprites[0].width; col++)
		{
			unsigned int color = dt->sprites[0].sprite_data[row * dt->sprites[0].width + col];

			// Skip transparent pixels (commonly 0)
			if (color != TRANSPARENT_COLOR)
				img_pix_put(dt->scene_img, offset_x + col, offset_y + row, color);
		}
	}
	return (EXIT_SUCCESS);
}
