#include "cub3d.h"

int render_sprite(t_data *dt, t_sprite *sprite)
{
	float	dx;
	float	dy;

	dx = sprite->pos.x - dt->player.pos.x;
	dy = sprite->pos.y - dt->player.pos.y;

	// float inv_det = 1 / (-FIELD_OF_VIEW_SCALE * (dt->player.direction_vector.x * dt->player.direction_vector.x +
	// 											dt->player.direction_vector.y * dt->player.direction_vector.y) )

	float inv_det = -1 / FIELD_OF_VIEW_SCALE;

	float transform_x = inv_det * (dt->player.direction_vector.y * dx -
								 dt->player.direction_vector.x * dy);
	// float transform_y = inv_det * (-dt->camera.plane.y * dx +
	// 							 dt->camera.plane.x * dy);

	float transform_y = (dt->player.direction_vector.x * dx +
								 dt->player.direction_vector.y * dy);

	int sprite_screen_x = (WINDOW_W / 2) * (1 + transform_x / transform_y);

	test_render_sprite(dt, sprite, sprite_screen_x, sprite->type, transform_y);
	return (EXIT_SUCCESS);
}

int	render_all_sprites(t_data *dt)
{
	size_t	i;

	//puts("Rendering sprites...");
	sort_sprites_by_distance(dt);
	//sort_sprites(dt, dt->sprite_count);
	i = 0;
	while (i < dt->sprite_count)
	{
		render_sprite(dt, &dt->sprites[i]);
		i++;
	}
}
