#include "cub3d.h"

int get_position_and_render_sprite(t_data *dt, t_sprite *sprite)
{
	float	dx;
	float	dy;
	float	transform_x;
	float	transform_y;
	int		sprite_screen_x;

	dx = sprite->pos.x - dt->player.pos.x;
	dy = sprite->pos.y - dt->player.pos.y;

	transform_x = (1 / -FIELD_OF_VIEW_SCALE) *
					(dt->player.direction_vector.y * dx -
								dt->player.direction_vector.x * dy);

	transform_y = (	dt->player.direction_vector.x * dx +
					dt->player.direction_vector.y * dy);

	sprite_screen_x = (WINDOW_W / 2) * (1 + transform_x / transform_y);

	if (transform_y >= 0.4f)
		render_sprite(dt, sprite, sprite_screen_x, sprite->type, transform_y);
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
