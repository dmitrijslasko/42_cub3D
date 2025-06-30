#include "cub3d.h"

void	init_mouse(t_mouse *mouse)
{
	mouse->suppress_mouse_frames = 0;
	mouse->x = 0;
	mouse->y = 0;
	mouse->prev_x = 0;
	mouse->prev_y = 0;
	mouse->lmb_press_count = 0;
	mouse->suppress_mouse_frames = 0;
}

void	init_dt(t_data *dt)
{
	dt->mlx_ptr = NULL;
	dt->win_ptr = NULL;
	dt->scene_img = NULL;
	dt->minimap_base_img = NULL;
	dt->minimap = NULL;
	dt->map.map_data = NULL;
	dt->doors = NULL;
	dt->rays = NULL;
	dt->sprites = NULL;
	dt->sprite_textures = NULL;
	dt->sprite_count = 0;
	dt->sprite_texture_count = 0;
	dt->view = NULL;
	dt->welcome_img = NULL;
	dt->sky_image = NULL;
	dt->message_img = NULL;
	init_mouse(&dt->mouse);
}
