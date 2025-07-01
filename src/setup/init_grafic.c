#include "cub3d.h"

void	init_graphic(t_data *dt)
{
	dt->mlx_ptr = NULL;
	dt->win_ptr = NULL;
	dt->frames_img = NULL;
	dt->scene_img = NULL;
	dt->minimap_base_img = NULL;
	dt->minimap = NULL;
	dt->sky_image = NULL;
	dt->message_img = NULL;
}
