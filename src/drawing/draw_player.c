#include "cub3d.h"

void draw_vector_line(t_data *dt, t_coor origin, t_x_y dir)
{
	t_coor end;

	end.x = origin.x + dir.x * DEF_GRID_SIZE * 5;
	end.y = origin.y + dir.y * DEF_GRID_SIZE * 5;
	draw_line(dt, origin, end, YELLOW);
}

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
	draw_vector_line(dt, pt1, dt->player->direction_vet);
	return (0);
}
