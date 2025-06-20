#include "cub3d.h"

int	draw_minimap_rays(t_data *dt, int is_direction_vector)
{
	t_coor	player_coor;
	size_t	i;

	set_coor_values(	&player_coor,
						dt->minimap->width / 2,
						dt->minimap->height / 2);
	//printf("X Y: %d %d\n", player_coor.x, player_coor.y);

	// draw the direction vector
	if (is_direction_vector)
		draw_minimap_ray(dt, player_coor, dt->player.direction_vector, MINIMAP_DIRECTION_RAY_COLOR);
	else
	{
		i = 0;
		while (i < CASTED_RAYS_COUNT)
		{
			if (i == 0 || i == CASTED_RAYS_COUNT - 1)
				draw_minimap_ray(dt, player_coor, dt->rays[i].vector, MINIMAP_RENDER_RAY_COLOR);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
