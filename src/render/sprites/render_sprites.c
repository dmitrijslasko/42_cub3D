#include "cub3d.h"

int render_sprites1(t_data *dt, t_sprite *sprite)
{
	// dt->camera.plane.x =  -dt->player.direction_vector.y * FIELD_OF_VIEW_SCALE;
	// dt->camera.plane.y =  dt->player.direction_vector.x * FIELD_OF_VIEW_SCALE;

	float	dx;
	float	dy;

	dx = sprite->pos.x - dt->player.pos.x;
	dy = sprite->pos.y - dt->player.pos.y;

	// float invDet = 1 / (-FIELD_OF_VIEW_SCALE * (dt->player.direction_vector.x * dt->player.direction_vector.x + 
	// 											dt->player.direction_vector.y * dt->player.direction_vector.y) )

	float invDet = -1 / FIELD_OF_VIEW_SCALE;

	float transformX = invDet * (dt->player.direction_vector.y * dx - 
								 dt->player.direction_vector.x * dy);
	// float transformY = invDet * (-dt->camera.plane.y * dx + 
	// 							 dt->camera.plane.x * dy);
	
	float transformY = (dt->player.direction_vector.x * dx + 
								 dt->player.direction_vector.y * dy);

	int spriteScreenX = (WINDOW_W / 2) * (1 + transformX / transformY);

	test_render_sprite(dt, spriteScreenX, sprite->type, transformY, sprite);
	return (EXIT_SUCCESS);
}

int	render_sprites(t_data *dt)
{
	size_t	i;

	i = 0;
	while (i < dt->sprite_count)
	{
		render_sprites1(dt, &dt->sprites[i]);
		i++;
	}

}
