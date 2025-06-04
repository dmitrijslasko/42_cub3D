#include "cub3d.h"

int	setup_mlx_and_win(t_data *dt)
{
	dt->mlx_ptr = mlx_init();
	if (dt->mlx_ptr == NULL)
	{
		//free_data(dt);
		return (MLX_ERROR);
	}
	printf("MLX pointer created!\n");
	dt->win_ptr = mlx_new_window(dt->mlx_ptr, WINDOW_W, WINDOW_H, WINDOW_NAME);
	if (dt->win_ptr == NULL)
	{
		//free_data(dt);
		return (MLX_ERROR);
	}
	printf("Window created!\n");
	return (0);
}
