#include "cub3d.h"

int set_coor_values(t_coor *coor, int x, int y)
{
	coor->x = x;
	coor->y = y;
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
	// size_t	grid_repr;

	set_coor_values(	&player_coor,
						dt->minimap->width / 2,
						dt->minimap->height / 2);

	if (MINIMAP_PLAYER_DISPLAY_STYLE == CIRCLE)
		draw_circle(dt->minimap, player_coor.x, player_coor.y, MINIMAP_PLAYER_SIZE_PX, MINIMAP_PLAYER_COLOR);
	else if (MINIMAP_PLAYER_DISPLAY_STYLE == SQUARE)
		draw_square_from_center(dt->minimap, player_coor.x, player_coor.y, MINIMAP_PLAYER_SIZE_PX, MINIMAP_PLAYER_COLOR);

	// grid_repr = MIN_DISTANCE_TO_WALL * MINIMAP_GRID_SIZE;

	// draw_circle(dt->minimap, player_coor.x + grid_repr, player_coor.y + grid_repr, 2, MAGENTA);
	// draw_circle(dt->minimap, player_coor.x + grid_repr, player_coor.y - grid_repr, 2, MAGENTA);
	// draw_circle(dt->minimap, player_coor.x - grid_repr, player_coor.y + grid_repr, 2, MAGENTA);
	// draw_circle(dt->minimap, player_coor.x - grid_repr, player_coor.y - grid_repr, 2, MAGENTA);
	return (EXIT_SUCCESS);
}
