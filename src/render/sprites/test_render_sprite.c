#include "cub3d.h"

bool	valid_sprites(t_data *dt)
{
	int	id_texture;

	if (!dt->sprites)
		return (EXIT_FAILURE);
	id_texture = dt->sprites[0].sprite_texture_id;
	if (id_texture < -1 || !dt->sprites_txt[id_texture].sprite_data)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	test_render_sprite(t_data *dt, int spriteScreenX)
{
	if (valid_sprites(dt))
		return (EXIT_FAILURE);

	int id_texture = dt->sprites[0].sprite_texture_id;
	int offset_x = spriteScreenX - dt->sprites_txt[id_texture].width / 2;
	int offset_y = WINDOW_H / 2 - dt->sprites_txt[id_texture].height / 2;

	for (int row = 0; row < dt->sprites_txt[id_texture].height; row++)
	{
		for (int col = 0; col < dt->sprites_txt[id_texture].width; col++)
		{
			unsigned int color = dt->sprites_txt[id_texture].sprite_data[row * dt->sprites_txt[id_texture].width + col];

			// Skip transparent pixels (commonly 0)

			int draw_x = offset_x + col;
			int draw_y = offset_y + row;

			if (draw_x >= 0 && draw_x < WINDOW_W && draw_y >= 0 && draw_y < WINDOW_H && color != TRANSPARENT_COLOR)
				img_pix_put(dt->scene_img, draw_x, draw_y, color);
		}
	}
	return (EXIT_SUCCESS);
}
