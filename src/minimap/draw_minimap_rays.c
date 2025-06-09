#include "cub3d.h"

int	draw_minimap_rays(t_data *dt, int draw_direction_vector)
{
	t_coor	player_coor;
	size_t	i;

	set_coor_values(&player_coor, MINIMAP_OFFSET_X + dt->player->pos.x * MINIMAP_GRID_SIZE, MINIMAP_OFFSET_Y + dt->player->pos.y * MINIMAP_GRID_SIZE);

	// draw the direction vector
	if (draw_direction_vector)
		draw_vector(dt, player_coor, dt->player->direction_vector, MAGENTA);
	else
	{
		i = 0;
		while (i < CASTED_RAYS_COUNT)
		{
			draw_vector(dt, player_coor, dt->rays[i].vector, YELLOW);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
