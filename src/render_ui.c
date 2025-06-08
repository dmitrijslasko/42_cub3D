#include "cub3d.h"

void	add_coor_info(t_data *dt)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 15;
	mlx = dt->mlx_ptr;
	win = dt->win_ptr;
	mlx_string_put(mlx, win, WINDOW_W - 200, y, UI_CLR_1, "Player position X: ");
	mlx_string_put(mlx, win, WINDOW_W - 50, y, UI_CLR_1, ft_itoa(dt->player->pos.x));
	mlx_string_put(mlx, win, WINDOW_W - 200, y += 10, UI_CLR_1, "Player position Y: ");
	mlx_string_put(mlx, win, WINDOW_W - 50, y, UI_CLR_1,  ft_itoa(dt->player->pos.y));
	mlx_string_put(mlx, win, WINDOW_W - 200, y += 10, UI_CLR_1, "Player orientation: ");
	mlx_string_put(mlx, win, WINDOW_W - 50, y, UI_CLR_1, ft_itoa(dt->player->direction_vector_deg));
	mlx_string_put(mlx, win, WINDOW_W - 200, y += 10, UI_CLR_1, "Frames per second (FPS): ");
	mlx_string_put(mlx, win, WINDOW_W - 50, y, UI_CLR_1, ft_itoa(FPS));
}

void	add_crosshair(t_data *dt, int color)
{
	t_coor	xy;

	set_coor_values(&xy, WINDOW_W / 2, WINDOW_H / 2);
	draw_square_from_center(dt, WINDOW_W / 2, WINDOW_H / 2, 5, color);
}

void	add_ui(t_data *dt)
{
	add_coor_info(dt);
	add_crosshair(dt, MAGENTA);
}
