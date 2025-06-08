#include "cub3d.h"

int set_coor_values(t_coor *coor, int x, int y)
{
	coor->x = x;
	coor->y = y;
	return (EXIT_SUCCESS);
}

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

typedef enum e_minimap_player_display_style
{
	SQUARE,
	CIRCLE
}	t_minimap_player_display_style;

/**
 * @brief Draws the player's representation on the 2D minimap.
 *
 * @param dt
 * @return int
 */
int draw_minimap_player(t_data *dt)
{
	t_coor player_coor;

	set_coor_values(&player_coor, MINIMAP_OFFSET_X + dt ->player->pos.x * MINIMAP_GRID_SIZE,  MINIMAP_OFFSET_Y + dt->player->pos.y * MINIMAP_GRID_SIZE);
	if (MINIMAP_PLAYER_DISPLAY_STYLE == CIRCLE)
		draw_circle(dt, player_coor.x, player_coor.y, MINIMAP_PLAYER_SIZE_PX, MINIMAP_PLAYER_COLOR);
	else if (MINIMAP_PLAYER_DISPLAY_STYLE == SQUARE)
		draw_square_from_center(dt, player_coor.x, player_coor.y, MINIMAP_PLAYER_SIZE_PX, MINIMAP_PLAYER_COLOR);
	return (EXIT_SUCCESS);
}
