#include "cub3d.h"

int render_sprites(t_data *dt)
{
	float	distance;

	for (int i = 0; i < 1; i++)
	{
		distance = (dt->sprites[i].x - dt->player.pos.x) *
				(dt->sprites[i].x - dt->player.pos.x) +
				(dt->sprites[i].y - dt->player.pos.y) *
				(dt->sprites[i].y - dt->player.pos.y);
		(void) distance;
		// printf("Distance to sprite[%d]: %.2f\n", i, distance);
	}
	// dt->camera.plane.x =  -dt->player.direction_vector.y * FIELD_OF_VIEW_SCALE;
	// dt->camera.plane.y =  dt->player.direction_vector.x * FIELD_OF_VIEW_SCALE;

	float dx;
	float dy;
	dx = dt->sprites[0].x - dt->player.pos.x;
	dy = dt->sprites[0].y - dt->player.pos.y;

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

	if (transformY > 0)
		test_render_sprite(dt, spriteScreenX);

	(void)spriteScreenX;
	return (EXIT_SUCCESS);
}
