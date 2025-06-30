#include "cub3d.h"

#define INV_FIELD_OF_VIEW_SCALE (-1.0f / FIELD_OF_VIEW_SCALE)

int	get_position_and_render_sprite(t_data *dt, t_sprite *sprite)
{
	t_x_y	dist;
	t_x_y	transform;
	int		sprite_screen_x;
	t_coor	sprite_size;
	t_coor	offset;

	dist.x = sprite->pos.x - dt->player.pos.x;
	dist.y = sprite->pos.y - dt->player.pos.y;
	transform.y = (dt->player.direction_vector.x * dist.x + \
					dt->player.direction_vector.y * dist.y);
	if (transform.y <= 0.4f)
		return (EXIT_SUCCESS);
	transform.x = INV_FIELD_OF_VIEW_SCALE * \
					(dt->player.direction_vector.y * dist.x - \
								dt->player.direction_vector.x * dist.y);
	sprite_size.y = fmin(WINDOW_H * 4, WINDOW_H / transform.y);
	sprite_size.x = fmin(WINDOW_W * 4, sprite_size.y);
	sprite_screen_x = (WINDOW_W / 2) * (1 + transform.x / transform.y);
	offset.x = sprite_screen_x - sprite_size.x / 2;
	offset.y = dt->view->screen_center_y - sprite_size.y / 3;
	render_sprite(dt, sprite, &offset, &sprite_size);
	return (EXIT_SUCCESS);
}

bool	set_texture_sprites(t_data *dt)
{
	size_t	i;
	size_t	j;

	if (!dt->sprites || !dt->sprite_textures)
		return (0);
	i = 0;
	while (i < dt->sprite_count)
	{
		j = 0;
		while (j < dt->sprite_texture_count)
		{
			if (dt->sprites[i].type == dt->sprite_textures[j].type)
			{
				dt->sprites[i].texture = &dt->sprite_textures[j];
				break;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	render_all_sprites(t_data *dt)
{
	size_t	i;

	i = 0;
	sort_sprites_by_distance(dt);
	set_texture_sprites(dt);
	while (i < dt->sprite_count)
	{
		get_position_and_render_sprite(dt, &dt->sprites[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
