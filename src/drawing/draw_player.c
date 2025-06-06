#include "cub3d.h"

void draw_vector_line(t_data *dt, t_coor origin, t_x_y dir)
{
	(void)dt;
	(void)origin;
	(void)dir;
	puts("Drawing vector line");
}

//int draw_direction_vector(t_data (*dt))
//{

//}

/**
 * @brief Draws the player's representation on the 2D minimap.
 *
 * @param dt
 * @return int
 */
int draw_player(t_data *dt)
{
	t_coor player_pos;

	player_pos.x = dt->player->pos.x * DEF_GRID_SIZE;
	player_pos.y = dt->player->pos.y * DEF_GRID_SIZE;

	//printf("Player position (X, Y): %f %f\n", dt->player->pos.x, dt->player->pos.y);
	//printf("Player orientation (deg): %zu\n", dt->player->direction_vector_deg);
	draw_square(dt, dt->player->pos.x * DEF_GRID_SIZE, dt->player->pos.y * DEF_GRID_SIZE, PLAYER_SIZE_PX, PLAYER_COLOR);
	draw_vector_line(dt, player_pos, dt->player->direction_vet);
	return (0);
}
