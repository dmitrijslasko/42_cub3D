#include "cub3d.h"

int render_sprites(t_data *dt)
{
	float	dx;
	float	dy;
	float	distance;

	for (int i = 0; i < 1; i++)
	{
		dx = fabs(dt->sprites[i].x[i] - dt->player.pos.x);
		dy = fabs(dt->sprites[i].y[i] - dt->player.pos.y);

		distance = sqrtf(dx * dx + dy * dy);
		(void) distance;
		// printf("Distance to sprite[%d]: %.2f\n", i, distance);
	}
	// test_render_sprite(dt);

	return (EXIT_SUCCESS);
}
