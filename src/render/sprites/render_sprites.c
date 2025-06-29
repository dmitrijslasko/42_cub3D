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

	render_sprite(dt, sprite, sprite_screen_x, sprite->type, transform_y);
	return (EXIT_SUCCESS);
}

int	render_all_sprites(t_data *dt)
{
	size_t	i;

	sort_sprites_by_distance(dt);
	i = 0;
	while (i < dt->sprite_count)
	{
		get_position_and_render_sprite(dt, &dt->sprites[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
