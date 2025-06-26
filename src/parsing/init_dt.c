#include "cub3d.h"

void	init_dt(t_data *dt)
{
	dt->mlx_ptr = NULL;
	dt->win_ptr = NULL;
	dt->scene_img = NULL;
	dt->minimap = NULL;
	dt->minimap_base = NULL;
	dt->doors = NULL;
	dt->rays = NULL;
	dt->map.map_data = NULL;
	dt->sprites = NULL;
	dt->sprites_txt = NULL;
	dt->view = NULL;
	dt->welcome_img = NULL;
}
