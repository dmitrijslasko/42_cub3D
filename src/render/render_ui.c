#include "cub3d.h"

void	add_crosshair(t_data *dt, int color)
{
	t_coor	coor;

	coor.x = WINDOW_W / 2;
	coor.y = WINDOW_H / 2;
	draw_square_from_center(dt->scene_img,
							&coor,
							DEFAULT_CROSSHAIR_SIZE,
							color);
}

void	add_ui(t_data *dt)
{
	if (ENABLE_CROSSHAIR)
		add_crosshair(dt, DEFAULT_CROSSHAIR_COLOR);
}
