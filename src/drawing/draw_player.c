#include "cub3d.h"

int set_coor_values(t_coor *coor, int x, int y)
{
	coor->x = x;
	coor->y = y;
	return (0);
}
/**
 * @brief Draws the player's representation on the 2D minimap.
 *
 * @param dt
 * @return int
 */
int draw_player(t_data *dt)
{
	t_coor player_coor;

	set_coor_values(&player_coor, dt->player->pos.x * DEF_GRID_SIZE, dt->player->pos.y * DEF_GRID_SIZE);
	draw_circle(dt, dt->player->pos.x * DEF_GRID_SIZE, dt->player->pos.y * DEF_GRID_SIZE, PLAYER_SIZE_PX, PLAYER_COLOR);

	// draw rays
	size_t	i;
	i = 0;
	while (i < CASTED_RAYS_COUNT)
	{
		draw_vector(dt, player_coor, dt->rays[i].vector, 1);
		i++;
	}

	// draw direction vector
	draw_vector(dt, player_coor, dt->player->direction_vector, 1);


	return (0);
}
