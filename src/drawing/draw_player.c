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
	t_coor pt1;

	set_coor_values(&pt1, dt->player->pos.x * DEF_GRID_SIZE, dt->player->pos.y * DEF_GRID_SIZE);
	draw_circle(dt, dt->player->pos.x * DEF_GRID_SIZE, dt->player->pos.y * DEF_GRID_SIZE, PLAYER_SIZE_PX, PLAYER_COLOR);
	draw_vector(dt, pt1, dt->player->direction_vet, 1);
	return (0);
}
