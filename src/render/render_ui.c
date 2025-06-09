#include "cub3d.h"

void	add_coor_info(t_data *dt)
{
	int		y;
	void	*mlx;
	void	*win;
	size_t	log_placement_x;

	log_placement_x = WINDOW_W - 200;

	y = 15;
	mlx = dt->mlx_ptr;
	win = dt->win_ptr;
	mlx_string_put(mlx, win, log_placement_x, y, UI_CLR_1, "Player position X: ");
	mlx_string_put(mlx, win, WINDOW_W - 40, y, UI_CLR_1, ft_itoa(dt->player->pos.x));
	mlx_string_put(mlx, win, log_placement_x, y += 10, UI_CLR_1, "Player position Y: ");
	mlx_string_put(mlx, win, WINDOW_W - 40, y, UI_CLR_1,  ft_itoa(dt->player->pos.y));

	char buffer[32];
	snprintf(buffer, sizeof(buffer), "%.2f", dt->player->direction_vector_deg);
	mlx_string_put(mlx, win, log_placement_x, y += 10, UI_CLR_1, "Player orientation (deg): ");
	mlx_string_put(mlx, win, WINDOW_W - 40, y, UI_CLR_1, buffer);

	mlx_string_put(mlx, win, log_placement_x, y += 20, UI_CLR_1, "Frames per second (FPS): ");
	mlx_string_put(mlx, win, WINDOW_W - 40, y, UI_CLR_1, ft_itoa(FPS));
	mlx_string_put(mlx, win, log_placement_x, y += 10, UI_CLR_1, "Window W: ");
	mlx_string_put(mlx, win, WINDOW_W - 40, y, UI_CLR_1, ft_itoa(WINDOW_W));
	mlx_string_put(mlx, win, log_placement_x, y += 10, UI_CLR_1, "Window H: ");
	mlx_string_put(mlx, win, WINDOW_W - 40, y, UI_CLR_1, ft_itoa(WINDOW_H));
	mlx_string_put(mlx, win, log_placement_x, y += 10, UI_CLR_1, "Casted rays: ");
	mlx_string_put(mlx, win, WINDOW_W - 40, y, UI_CLR_1, ft_itoa(CASTED_RAYS_COUNT));
	mlx_string_put(mlx, win, log_placement_x, y += 20, UI_CLR_1, "LMB presses: ");
	mlx_string_put(mlx, win, WINDOW_W - 40, y, UI_CLR_1, ft_itoa(dt->mouse.lmb_press_count));

	mlx_string_put(mlx, win, log_placement_x, y += 20, UI_CLR_1, "Wall type: ");
	mlx_string_put(mlx, win, WINDOW_W - 40, y, UI_CLR_1, ft_itoa(dt->rays[CASTED_RAYS_COUNT/2].wall_type));

	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[CASTED_RAYS_COUNT / 2].distance_to_wall);
	mlx_string_put(mlx, win, log_placement_x, y += 10, UI_CLR_1, "Distance to wall: ");
	mlx_string_put(mlx, win, WINDOW_W - 40, y, UI_CLR_1, buffer);
}

void	add_crosshair(t_data *dt, int color)
{
	t_coor	xy;
	t_coor	xy2;

	set_coor_values(&xy2, WINDOW_W / 2, WINDOW_H);

	set_coor_values(&xy, WINDOW_W / 2, WINDOW_H / 2);
	draw_square_from_center(dt, WINDOW_W / 2, WINDOW_H / 2, 5, color);
	//draw_vertical_line(dt, xy, xy2, color);
}

void	add_ui(t_data *dt)
{
	add_coor_info(dt);
	add_crosshair(dt, MAGENTA);
}
