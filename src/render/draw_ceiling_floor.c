#include "cub3d.h"

int	draw_ceiling(t_data *dt)
{
	t_coor	top_left;
	t_coor	bottom_right;

	set_coor_values(&top_left, 0, 0);
	set_coor_values(&bottom_right, WINDOW_W, WINDOW_H / 2);

	draw_rectangle(dt, top_left, bottom_right, DEF_CEILING_COLOR);
	return (EXIT_SUCCESS);
}

int	draw_floor(t_data *dt)
{
	t_coor	top_left;
	t_coor	bottom_right;

	set_coor_values(&top_left, 0, WINDOW_H / 2);
	set_coor_values(&bottom_right, WINDOW_W, WINDOW_H);

	draw_rectangle(dt, top_left, bottom_right, DEF_FLOOR_COLOR);
	return (EXIT_SUCCESS);
}
