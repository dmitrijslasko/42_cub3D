#include "cub3d.h"

/**
 * @brief Draws the player's representation on the 2D minimap.
 *
 * @param dt
 * @return int
 */
int draw_player(t_data *dt)
{
	printf("Player position (X, Y): %f %f\n", dt->player->pos.x, dt->player->pos.y);
	//printf("Player orientation (deg): %zu\n", dt->player->direction_vector_deg);
	draw_square(dt, dt->player->pos.x * DEF_GRID_SIZE, dt->player->pos.y * DEF_GRID_SIZE, PLAYER_SIZE_PX, PLAYER_COLOR);

	return (0);
}
