#include "cub3d.h"

bool	valid_sprites(t_data *dt, char type_sprite, t_sprite_textures *sprite_textures)
{
	size_t	i;

	if (!dt->sprites || !dt->sprite_textures)
		return (0);

	i = 0;
	while (i < dt->sprite_textures_count)
	{
		if (dt->sprite_textures[i].type == type_sprite)
		{
			*sprite_textures = dt->sprite_textures[i];
			return (1);
		}
		i++;
	}
	return (0);
}

int	test_render_sprite(t_data *dt, t_sprite *sprite, int sprite_screen_x, char type_sprite, float transform_y)
{
	t_sprite_textures	sprite_textures;
	unsigned int	color;
	size_t			row;
	size_t			col;

	if (transform_y <= 0.2f)
		return (0);
	if (!valid_sprites(dt, type_sprite, &sprite_textures))
		return (EXIT_FAILURE);

	int sprite_height = fmin(WINDOW_H * 4, WINDOW_H / transform_y);
	int sprite_width = fmin(WINDOW_W * 4, sprite_height * ((float)sprite_textures.width / sprite_textures.height));

	int offset_x = sprite_screen_x - sprite_width  / 2;
	int offset_y = dt->view->screen_center - sprite_height / 2;

	row = 0;
	while (row < sprite_height)
	{
		int draw_y = offset_y + row;
		if (draw_y < 0 || draw_y >= WINDOW_H)
		{
			row++;
			continue;
		}

		int tex_y = row * sprite_textures.height / sprite_height;

		col = 0;
		while (col < sprite_width)
		{
			int draw_x = offset_x + col;
			if (draw_x < 0 || draw_x >= WINDOW_W)
			{
				col++;
				continue;
			}

			int tex_x = col * sprite_textures.width / sprite_width;

			color = sprite_textures.sprite_data[tex_y * sprite_textures.width + tex_x];
			if (color == TRANSPARENT_COLOR)
			{
				col++;
				continue;
			}
			//apply_wall_shading_1(dt, draw_x, &color, 0.02f);
			float distance_to_wall = dt->rays[draw_x].corrected_distance_to_wall;
			if (distance_to_wall * distance_to_wall > sprite->distance_to_player)
				img_pix_put(dt->scene_img, draw_x, draw_y, color);
			col++;
		}
		row++;
	}
	return (EXIT_SUCCESS);
}

// int	test_render_sprite(t_data *dt, int sprite_screen_x, char type_sprite, float transform_y, t_sprite *sprite)
// {
// 	t_sprite_textures	sprite_textures;

// 	if (transform_y <= 0.2f)
// 		return (0);
// 	if (!valid_sprites(dt, type_sprite, &sprite_textures))
// 		return (EXIT_FAILURE);

// 	int sprite_height = (WINDOW_H / transform_y);
// 	int sprite_width = sprite_height * ((float)sprite_textures.width / sprite_textures.height); // mantém proporção

// 	int offset_x = sprite_screen_x - sprite_width  / 2;
// 	int offset_y = WINDOW_H / 2 - sprite_height / 2;

// 	for (int row = 0; row < sprite_height; row++)
// 	{
// 		int tex_y = row * sprite_textures.height / sprite_height;

// 		for (int col = 0; col < sprite_width; col++)
// 		{
// 			int tex_x = col * sprite_textures.width / sprite_width;

// 			unsigned int color = sprite_textures.sprite_data[tex_y * sprite_textures.width + tex_x];

// 			int draw_x = offset_x + col;
// 			int draw_y = offset_y + row;

// 			if (draw_x >= 0 && draw_x < WINDOW_W && draw_y >= 0 && draw_y < WINDOW_H && color != TRANSPARENT_COLOR)
// 			{
// 				t_ray	ray = dt->rays[draw_x];
// 				float	distance_to_wall = ray.corrected_distance_to_wall * ray.corrected_distance_to_wall;
// 				if (distance_to_wall > sprite->distance_to_player)
// 					img_pix_put(dt->scene_img, draw_x, draw_y, color);
// 			}
// 		}
// 	}
// 	return (EXIT_SUCCESS);
// }

// int	test_render_sprite(t_data *dt, int sprite_screen_x, char type_sprite, float transform_y, t_sprite *sprite)
// {
// 	t_sprite_textures	sprite_textures;

// 	if (transform_y < 0)
// 		return (0);
// 	if (!valid_sprites(dt, type_sprite, &sprite_textures))
// 		return (EXIT_FAILURE);

// 	int offset_x = sprite_screen_x - sprite_textures.width / 2;
// 	int offset_y = WINDOW_H / 2 - sprite_textures.height / 2;

// 	for (int row = 0; row < sprite_textures.height; row++)
// 	{
// 		for (int col = 0; col < sprite_textures.width; col++)
// 		{
// 			unsigned int color = sprite_textures.sprite_data[row * sprite_textures.width + col];

// 			int draw_x = offset_x + col;
// 			int draw_y = offset_y + row;

// 			if (draw_x >= 0 && draw_x < WINDOW_W && draw_y >= 0 && draw_y < WINDOW_H && color != TRANSPARENT_COLOR)
// 				img_pix_put(dt->scene_img, draw_x, draw_y, color);
// 		}
// 	}
// 	return (EXIT_SUCCESS);
// }
