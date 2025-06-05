#include "cub3d.h"

/**
 * @brief Draws the player's representation on the 2D minimap.
 *
 * @param dt
 * @return int
 */
int draw_player(t_data *dt)
{
	t_coor player_pos;
	t_coor orientation_vector;

	player_pos.x = dt->player->player_pos_x;
	player_pos.y = dt->player->player_pos_y;

	//printf("Player position (X, Y): %d %d\n", player_pos.x, player_pos.y);
	orientation_vector.x = player_pos.x - 1;
	orientation_vector.y = 10;

	//printf("Player orientation (deg): %zu\n", dt->player->direction_vector_deg);
	draw_square(dt, dt->player->player_pos_x, dt->player->player_pos_y, PLAYER_SIZE_PX, PLAYER_COLOR);
	draw_sloped_line(dt, orientation_vector, player_pos);

	return (0);
}
