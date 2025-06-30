#include "cub3d.h"

int	draw_ceiling(t_data *dt)
{
	int			color;
	t_coor		top_left;
	t_coor		bottom_right;

	set_coor_values(&top_left, 0, 0);
	set_coor_values(&bottom_right, WINDOW_W, dt->view->screen_center_y);
	color = create_color_rgb(	dt->map.wall_tile[CEILING].color.r,
								dt->map.wall_tile[CEILING].color.g,
								dt->map.wall_tile[CEILING].color.b);
	draw_rectangle(dt->scene_img, top_left, bottom_right, color);

	return (EXIT_SUCCESS);
}

int	draw_floor(t_data *dt)
{
	int		color;
	t_coor	top_left;
	t_coor	bottom_right;

	set_coor_values(&top_left, 0, dt->view->screen_center_y);
	set_coor_values(&bottom_right, WINDOW_W, WINDOW_H);

	color = create_color_rgb(dt->map.wall_tile[FLOOR].color.r, dt->map.wall_tile[FLOOR].color.g, dt->map.wall_tile[FLOOR].color.b);
	draw_rectangle(dt->scene_img, top_left, bottom_right, color);
	return (EXIT_SUCCESS);
}
