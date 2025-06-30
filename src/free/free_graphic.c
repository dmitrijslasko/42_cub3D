#include "cub3d.h"

void	free_graphic(t_data *dt)
{
	free_img(dt->scene_img, dt->mlx_ptr);
	free_img(dt->minimap_base_img, dt->mlx_ptr);
	free_img(dt->minimap, dt->mlx_ptr);
	free_img(dt->sky_image, dt->mlx_ptr);
	free_img(dt->message_img, dt->mlx_ptr);
	mlx_destroy_display(dt->mlx_ptr);
	mlx_destroy_window(dt->mlx_ptr, dt->win_ptr);
	dt->mlx_ptr = NULL;
}