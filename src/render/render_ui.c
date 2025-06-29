#include "cub3d.h"

void	add_crosshair(t_data *dt, int color)
{
	draw_square_from_center(dt->scene_img,
							WINDOW_W / 2,
							WINDOW_H / 2,
							DEFAULT_CROSSHAIR_SIZE,
							color);
}

void	add_ui(t_data *dt)
{
	add_crosshair(dt, DEFAULT_CROSSHAIR_COLOR);
}
