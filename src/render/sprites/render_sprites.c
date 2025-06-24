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
	test_render_sprite(dt);

	return (EXIT_SUCCESS);
}
