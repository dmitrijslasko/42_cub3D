#include "cub3d.h"

void	add_coor_info(t_data *dt)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 15;
	mlx = dt->mlx_ptr;
	win = dt->win_ptr;
	mlx_string_put(mlx, win, 10, y, UI_CLR_1, "Player position: ");
	mlx_string_put(mlx, win, 150, y, UI_CLR_1, "X Y");
	mlx_string_put(mlx, win, 10, y += 10, UI_CLR_1, "Player orientation: ");
	mlx_string_put(mlx, win, 150, y, UI_CLR_1, "deg");
}

void	add_ui(t_data *dt)
{
	add_coor_info(dt);
}
