#include "cub3d.h"

int test_render_sprite(t_data *dt, int spriteScreenX)
{
	if (!dt->sprites || !dt->sprites[0].sprite_data)
	{
		// printf("Sprite data not loaded!\n");
		return (EXIT_FAILURE);
	}

	int offset_x = spriteScreenX - dt->sprites[0].width / 2;
	int offset_y = WINDOW_H / 2 - dt->sprites[0].height / 2;

	for (int row = 0; row < dt->sprites[0].height; row++)
	{
		for (int col = 0; col < dt->sprites[0].width; col++)
		{
			unsigned int color = dt->sprites[0].sprite_data[row * dt->sprites[0].width + col];

			// Skip transparent pixels (commonly 0)

			int draw_x = offset_x + col;
			int draw_y = offset_y + row;

			if (draw_x >= 0 && draw_x < WINDOW_W && draw_y >= 0 && draw_y < WINDOW_H && color != TRANSPARENT_COLOR)
				img_pix_put(dt->scene_img, draw_x, draw_y, color);
		}
	}
	return (EXIT_SUCCESS);
}
