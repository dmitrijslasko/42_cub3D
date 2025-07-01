#include "cub3d.h"

int	show_welcome_img(t_data *dt)
{
	if (dt->win_ptr == NULL)
		return (1);
	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->welcome_img, 0, 0);
	return (0);
}
