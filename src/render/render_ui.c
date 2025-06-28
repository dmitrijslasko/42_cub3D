#include "cub3d.h"

void	show_debug_info(t_data *dt)
{
	int		y;
	void	*mlx;
	void	*win;
	size_t	field_1_x;
	size_t	field_2_x;

	size_t	ray_index;

	if (CASTED_RAYS_COUNT == 1)
		ray_index = 0;
	else
		ray_index = CASTED_RAYS_COUNT / 2;

	field_1_x = WINDOW_W - DEBUG_FIELD_1_OFFSET_X;
	field_2_x = WINDOW_W - DEBUG_FIELD_2_OFFSET_X;

	y = DEBUG_FIELD_OFFSET_Y;
	mlx = dt->mlx_ptr;
	win = dt->win_ptr;

	mlx_string_put(mlx, win, field_1_x, y, UI_CLR_1, "Frames per second (FPS):");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, ft_itoa(FPS));
	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL, UI_CLR_1, "Window W:");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, ft_itoa(WINDOW_W));
	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL, UI_CLR_1, "Window H:");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, ft_itoa(WINDOW_H));
	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL, UI_CLR_1, "Casted rays:");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, ft_itoa(CASTED_RAYS_COUNT));

	char buffer[32];
	snprintf(buffer, sizeof(buffer), "%.2f", dt->player.pos.x);
	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL_2, UI_CLR_1, "Player position X:");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	snprintf(buffer, sizeof(buffer), "%.2f", dt->player.pos.y);
	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL, UI_CLR_1, "Player position Y:");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	snprintf(buffer, sizeof(buffer), "%.2f", dt->player.direction_vector_deg);
	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL, UI_CLR_1, "Player orientation (deg):");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL_2, UI_CLR_1, "LMB presses:");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, ft_itoa(dt->mouse.lmb_press_count));

	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[ray_index].distance_to_wall);
	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL_2, UI_CLR_1, "Distance to obstacle:");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL, UI_CLR_1, "Obstacle type:");
	if (dt->rays[ray_index].cell_type == DOOR_VERTICAL)
		mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, "DOOR");
	else if (dt->rays[ray_index].cell_type == SOLID_WALL)
		mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, "WALL");
	else if (dt->rays[ray_index].cell_type == THIN_WALL_VERTICAL)
		mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, "THIN (V)");
	else
		mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, "N/D");

	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL, UI_CLR_1, "Wall type:");
	if (dt->rays[ray_index].cell_type == SOLID_WALL)
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, ft_itoa(dt->rays[ray_index].wall_type));

	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[ray_index].wall_hit.x);
	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL_2, UI_CLR_1, "Cell hit point X:");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[ray_index].wall_hit.y);
	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL, UI_CLR_1, "Cell hit point Y:");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[ray_index].percentage_of_image);
	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL_2, UI_CLR_1, "Percentage of image:");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[ray_index].door_hit_coor.x);
	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL_2, UI_CLR_1, "Door hit point X:");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[ray_index].door_hit_coor.y);
	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL, UI_CLR_1, "Door hit point Y:");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL, UI_CLR_1, "Door ID:");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, ft_itoa(dt->rays[ray_index].door->id));

	snprintf(buffer, sizeof(buffer), "%ld", dt->last_time);
	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL_2, UI_CLR_1, "Current time:");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	snprintf(buffer, sizeof(buffer), "%ld", (dt->last_time - dt->start_time) / 1000);
	mlx_string_put(mlx, win, field_1_x, y += DEBUG_MENU_NL_2, UI_CLR_1, "Elapsed time (s):");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);
}

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
