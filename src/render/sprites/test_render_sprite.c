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

t_coor	calculate_tex_x_y(t_sprite_texture *texture, t_coor *coor,
	t_coor *offset, t_coor *sprite_size)
{
	t_coor	tex_coor;

	tex_coor.y = (coor->y - offset->y) * texture->height / sprite_size->y;
	tex_coor.x = (coor->x - offset->x) * texture->width / sprite_size->x;
	return (tex_coor);
}

void	sprite_put_color(t_data *dt, t_sprite_texture *texture,
	t_coor *coor, int time, t_coor *tex_coor)
{
	unsigned int	color;

	color = texture->sprite_data[time][tex_coor->y * texture->width + \
			tex_coor->x];
	dt->has_changed = 1;
	if (color == TRANSPARENT_COLOR)
		return ;
	img_pix_put(dt->scene_img, coor->x, coor->y, color);
}

int	render_sprite(t_data *dt, t_sprite *sprite, \
					t_coor *offset, t_coor	*sprite_size)
{
	t_coor	coor;
	t_coor	tex_coor;
	int		time;

	time = (dt->last_time - dt->start_time) / 100 % 2;
	coor.y = ft_max(offset->y, 0);
	while (coor.y < sprite_size->y + offset->y && coor.y < WINDOW_H)
	{
		coor.x = ft_max(offset->x, 0);
		while (coor.x < sprite_size->x + offset->x && coor.x < WINDOW_W)
		{
			if (check_sprite_closer_than_wall(dt, &coor, sprite))
			{
				tex_coor = calculate_tex_x_y(sprite->texture,
						&coor, offset, sprite_size);
				sprite_put_color(dt, sprite->texture,
					&coor, time, &tex_coor);
			}
			coor.x++;
		}
		coor.y++;
	}
	return (EXIT_SUCCESS);
}
