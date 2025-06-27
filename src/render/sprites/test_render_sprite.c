#include "cub3d.h"

bool	valid_sprites(t_data *dt, char type_sprite, t_sprite_txt *sprite_txt)
{
	size_t	i;

	if (!dt->sprites || !dt->sprites_txt)
		return (0);

	i = 0;
	while (i < dt->sprite_txt_count)
	{
		if (dt->sprites_txt[i].type == type_sprite)
		{
			*sprite_txt = dt->sprites_txt[i];
			return (1);
		}
		i++;
	}
	return (0);
}

int	test_render_sprite(t_data *dt, int spriteScreenX, char type_sprite, float tranformY, t_sprite *sprite)
{
	t_sprite_txt	sprite_txt;

	if (tranformY <= 0.2f)
		return (0);
	if (!valid_sprites(dt, type_sprite, &sprite_txt))
		return (EXIT_FAILURE);
	int sprite_height = fmin(WINDOW_H, WINDOW_H / tranformY);
	int sprite_width = fmin(WINDOW_W, sprite_height * ((float)sprite_txt.width / sprite_txt.height));

	int offset_x = spriteScreenX - sprite_width  / 2;
	int offset_y = WINDOW_H / 2 - sprite_height / 2;

	for (int row = 0; row < sprite_height; row++) 
	{
		int draw_y = offset_y + row;
		if (draw_y < 0 || draw_y >= WINDOW_H)
			continue;

		int tex_y = row * sprite_txt.height / sprite_height;

		for (int col = 0; col < sprite_width; col++) 
		{
			int draw_x = offset_x + col;
			if (draw_x < 0 || draw_x >= WINDOW_W)
				continue;

			int tex_x = col * sprite_txt.width / sprite_width;

			unsigned int color = sprite_txt.sprite_data[tex_y * sprite_txt.width + tex_x];
			if (color == TRANSPARENT_COLOR)
				continue;

			float dist_wall = dt->rays[draw_x].corrected_distance_to_wall;
			if (dist_wall * dist_wall > sprite->dist_to_player)
				img_pix_put(dt->scene_img, draw_x, draw_y, color);
		}
	}
	return (EXIT_SUCCESS);
}

// int	test_render_sprite(t_data *dt, int spriteScreenX, char type_sprite, float tranformY, t_sprite *sprite)
// {
// 	t_sprite_txt	sprite_txt;

// 	if (tranformY <= 0.2f)
// 		return (0);
// 	if (!valid_sprites(dt, type_sprite, &sprite_txt))
// 		return (EXIT_FAILURE);

// 	int sprite_height = (WINDOW_H / tranformY);
// 	int sprite_width = sprite_height * ((float)sprite_txt.width / sprite_txt.height); // mantém proporção

// 	int offset_x = spriteScreenX - sprite_width  / 2;
// 	int offset_y = WINDOW_H / 2 - sprite_height / 2;

// 	for (int row = 0; row < sprite_height; row++)
// 	{
// 		int tex_y = row * sprite_txt.height / sprite_height;
		
// 		for (int col = 0; col < sprite_width; col++)
// 		{
// 			int tex_x = col * sprite_txt.width / sprite_width;

// 			unsigned int color = sprite_txt.sprite_data[tex_y * sprite_txt.width + tex_x];

// 			int draw_x = offset_x + col;
// 			int draw_y = offset_y + row;

// 			if (draw_x >= 0 && draw_x < WINDOW_W && draw_y >= 0 && draw_y < WINDOW_H && color != TRANSPARENT_COLOR)
// 			{
// 				t_ray	ray = dt->rays[draw_x];
// 				float	dist_wall = ray.corrected_distance_to_wall * ray.corrected_distance_to_wall;
// 				if (dist_wall > sprite->dist_to_player)
// 					img_pix_put(dt->scene_img, draw_x, draw_y, color);
// 			}
// 		}
// 	}
// 	return (EXIT_SUCCESS);
// }

// int	test_render_sprite(t_data *dt, int spriteScreenX, char type_sprite, float tranformY, t_sprite *sprite)
// {
// 	t_sprite_txt	sprite_txt;

// 	if (tranformY < 0)
// 		return (0);
// 	if (!valid_sprites(dt, type_sprite, &sprite_txt))
// 		return (EXIT_FAILURE);

// 	int offset_x = spriteScreenX - sprite_txt.width / 2;
// 	int offset_y = WINDOW_H / 2 - sprite_txt.height / 2;

// 	for (int row = 0; row < sprite_txt.height; row++)
// 	{
// 		for (int col = 0; col < sprite_txt.width; col++)
// 		{
// 			unsigned int color = sprite_txt.sprite_data[row * sprite_txt.width + col];

// 			int draw_x = offset_x + col;
// 			int draw_y = offset_y + row;

// 			if (draw_x >= 0 && draw_x < WINDOW_W && draw_y >= 0 && draw_y < WINDOW_H && color != TRANSPARENT_COLOR)
// 				img_pix_put(dt->scene_img, draw_x, draw_y, color);
// 		}
// 	}
// 	return (EXIT_SUCCESS);
// }
