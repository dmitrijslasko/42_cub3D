#include "cub3d.h"

bool	valid_sprites(t_data *dt, char type_sprite, t_sprite_texture *sprite_texture)
{
	size_t	i;

	if (!dt->sprites || !dt->sprite_textures)
		return (0);

	i = 0;
	while (i < dt->sprite_texture_count)
	{
		if (dt->sprite_textures[i].type == type_sprite)
		{
			*sprite_texture = dt->sprite_textures[i];
			return (1);
		}
		i++;
	}
	return (0);
}

int	render_sprite(t_data *dt, t_sprite *sprite, int sprite_screen_x, float transform_y)
{
	//t_sprite_texture	sprite_textures;
	unsigned int	color;
	int				row;
	int				col;
	int 			time;

	time = (dt->last_time - dt->start_time) / 100 % 2;
	int sprite_height = fmin(WINDOW_H * 4, WINDOW_H / transform_y);
	int sprite_width = fmin(WINDOW_W * 4, sprite_height);

	int offset_x = sprite_screen_x - sprite_width  / 2;
	int offset_y = dt->view->screen_center_y - sprite_height / 3;

	row = 0;
	while (row < sprite_height)
	{
		int draw_y = offset_y + row;
		if (draw_y < 0 || draw_y >= WINDOW_H)
		{
			row++;
			continue;
		}

		int tex_y = row * sprite->texture->height / sprite_height;

		col = 0;
		while (col < sprite_width && col < WINDOW_W - offset_x)
		{
			int draw_x = offset_x + col;
			if (draw_x < 0 || draw_x >= WINDOW_W)
			{
				col++;
				continue;
			}
			float distance_to_wall = dt->rays[draw_x / (WINDOW_W / CASTED_RAYS_COUNT)].distance_to_wall;
			if (distance_to_wall * distance_to_wall > sprite->distance_to_player)
			{
				int tex_x = col * sprite->texture->width / sprite_width;
				color = sprite->texture->sprite_data[time][tex_y * sprite->texture->width + tex_x];
				if (color == TRANSPARENT_COLOR)
				{
					col++;
					continue;
				}
				img_pix_put(dt->scene_img, draw_x, draw_y, color);
			}
			col++;
		}
		row++;
	}
	return (EXIT_SUCCESS);
}
