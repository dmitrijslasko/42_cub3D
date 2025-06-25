#include "cub3d.h"

void	add_coor_info(t_data *dt)
{
	int		y;
	void	*mlx;
	void	*win;
	size_t	field_1_x;
	size_t	field_2_x;

	field_1_x = WINDOW_W - 250;
	field_2_x = WINDOW_W - 50;

	y = 15;
	mlx = dt->mlx_ptr;
	win = dt->win_ptr;
	mlx_string_put(mlx, win, field_1_x, y, UI_CLR_1, "Player position X: ");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, ft_itoa(dt->player.pos.x));
	mlx_string_put(mlx, win, field_1_x, y += 10, UI_CLR_1, "Player position Y: ");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1,  ft_itoa(dt->player.pos.y));

	char buffer[32];
	snprintf(buffer, sizeof(buffer), "%.2f", dt->player.direction_vector_deg);
	mlx_string_put(mlx, win, field_1_x, y += 10, UI_CLR_1, "Player orientation (deg): ");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	mlx_string_put(mlx, win, field_1_x, y += 20, UI_CLR_1, "Frames per second (FPS): ");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, ft_itoa(FPS));
	mlx_string_put(mlx, win, field_1_x, y += 10, UI_CLR_1, "Window W: ");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, ft_itoa(WINDOW_W));
	mlx_string_put(mlx, win, field_1_x, y += 10, UI_CLR_1, "Window H: ");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, ft_itoa(WINDOW_H));
	mlx_string_put(mlx, win, field_1_x, y += 10, UI_CLR_1, "Casted rays: ");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, ft_itoa(CASTED_RAYS_COUNT));
	mlx_string_put(mlx, win, field_1_x, y += 20, UI_CLR_1, "LMB presses: ");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, ft_itoa(dt->mouse.lmb_press_count));

	mlx_string_put(mlx, win, field_1_x, y += 20, UI_CLR_1, "Wall type: ");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, ft_itoa(dt->rays[CASTED_RAYS_COUNT/2].wall_type));

	mlx_string_put(mlx, win, field_1_x, y += 10, UI_CLR_1, "Cell type: ");
	if (dt->rays[CASTED_RAYS_COUNT/2].cell_type == 4)
		mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, "DOOR");
	else if (dt->rays[CASTED_RAYS_COUNT/2].cell_type == 1)
		mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, "WALL");
	else if (dt->rays[CASTED_RAYS_COUNT/2].cell_type == 2)
		mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, "THIN (V)");
	else
		mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, "N/D");

	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[CASTED_RAYS_COUNT / 2].distance_to_wall);
	mlx_string_put(mlx, win, field_1_x, y += 20, UI_CLR_1, "Distance to wall: ");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[CASTED_RAYS_COUNT / 2].percentage_of_image);
	mlx_string_put(mlx, win, field_1_x, y += 10, UI_CLR_1, "Percentage of image: ");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[CASTED_RAYS_COUNT / 2].wall_hit.x);
	mlx_string_put(mlx, win, field_1_x, y += 20, UI_CLR_1, "Cell hit point X: ");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[CASTED_RAYS_COUNT / 2].wall_hit.y);
	mlx_string_put(mlx, win, field_1_x, y += 10, UI_CLR_1, "Cell hit point Y: ");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[CASTED_RAYS_COUNT / 2].door_hit.x);
	mlx_string_put(mlx, win, field_1_x, y += 20, UI_CLR_1, "Door hit point X: ");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);

	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[CASTED_RAYS_COUNT / 2].door_hit.y);
	mlx_string_put(mlx, win, field_1_x, y += 10, UI_CLR_1, "Door hit point Y: ");
	mlx_string_put(mlx, win, field_2_x, y, UI_CLR_1, buffer);
}

void	add_crosshair(t_data *dt, int color)
{
	t_coor	xy;
	t_coor	xy2;

	set_coor_values(&xy2, WINDOW_W / 2, WINDOW_H);

	set_coor_values(&xy, WINDOW_W / 2, WINDOW_H / 2);
	draw_square_from_center(dt->scene_img, WINDOW_W / 2, WINDOW_H / 2, 5, color);
	//draw_vertical_line(dt, xy, xy2, color);
}

void	add_ui(t_data *dt)
{
	add_coor_info(dt);
	add_crosshair(dt, WHITE);
}
