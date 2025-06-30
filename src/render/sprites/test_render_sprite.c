#include "cub3d.h"

bool	check_sprite_closer_than_wall(t_data *dt, t_coor *coor, t_sprite *spr)
{
	float	distance_to_wall;

	distance_to_wall = dt->rays[coor->x / (WINDOW_W / CASTED_RAYS_COUNT)] \
													.distance_to_wall;
	if (distance_to_wall * distance_to_wall > spr->distance_to_player)
		return (1);
	return (0);
}

// unsigned int	find_color_texture(t_sprite_texture *texture, t_coor *coor, t_coor *offset, t_coor *sprite_size)
// {
// 	unsigned int	color;
// 	int				tex_y;
// 	int				tex_x;

// 	tex_y = (coor->y - offset->y) * texture->height / sprite_size->y;
// 	tex_x = (coor->x - offset->x) * texture->width / sprite_size->x;
// 	color = *texture->sprite_data[tex_y * texture->width + tex_x];
// 	return (color);
// }

// unsigned int	find_color_texture(t_sprite_texture *texture, t_coor *coor, t_coor *offset, t_coor *sprite_size, int time)
// {
// 	unsigned int	color;
// 	int				tex_y;
// 	int				tex_x;

// 	tex_y = (coor->y - offset->y) * texture->height / sprite_size->y;
// 	tex_x = (coor->x - offset->x) * texture->width / sprite_size->x;
// 	color = texture->sprite_data[tex_y * texture->width + tex_x];
// 	return (color);
// }


int	render_sprite(t_data *dt, t_sprite *sprite, int sprite_screen_x, float transform_y)
{
	unsigned int	color;
	t_coor			coor;
	t_coor			offset;
	t_coor			sprite_size;
	int				time;

	time = (dt->last_time - dt->start_time) / 100 % 2;
	sprite_size.y = fmin(WINDOW_H * 4, WINDOW_H / transform_y);
	sprite_size.x = fmin(WINDOW_W * 4, sprite_size.y);
	offset.x = sprite_screen_x - sprite_size.x / 2;
	offset.y = dt->view->screen_center_y - sprite_size.y / 3;
	coor.y = ft_max(offset.y, 0);
	while (coor.y < sprite_size.y + offset.y && coor.y < WINDOW_H)
	{
		coor.x = ft_max(offset.x, 0);
		while (coor.x < sprite_size.x + offset.x && coor.x < WINDOW_W)
		{
			if (check_sprite_closer_than_wall(dt, &coor, sprite))
			{
				int tex_y = (coor.y - offset.y) * sprite->texture->height / sprite_size.y;
				int tex_x = (coor.x - offset.x) * sprite->texture->width / sprite_size.x;
				color = sprite->texture->sprite_data[time][tex_y * sprite->texture->width + tex_x];
				// color = find_color_texture(sprite->texture, &coor, &offset, &sprite_size);
				if (color == TRANSPARENT_COLOR)
				{
					coor.x++;
					continue;
				}
				img_pix_put(dt->scene_img, coor.x, coor.y, color);
			}
			coor.x++;
		}
		coor.y++;
	}
	return (EXIT_SUCCESS);
}
