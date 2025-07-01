#include "cub3d.h"

void	init_mouse(t_mouse *mouse)
{
	mouse->suppress_mouse_frames = 0;
	mouse->x = 0;
	mouse->y = 0;
	mouse->prev_x = 0;
	mouse->prev_y = 0;
	mouse->lmb_press_count = 0;
}

void	init_texture(t_texture *texture)
{
	if (!texture)
		return ;
	texture->texture_img = NULL;
	texture->texture_data = NULL;
	texture->file = NULL;
}

void	init_map(t_map	*map)
{
	size_t	i;

	map->map_data = NULL;
	i = 0;
	while (i < NUMBER_TEXTURES)
		init_texture(&map->wall_tile[i++].texture);
	init_texture(&map->door.texture);
}

void	init_img(t_img *img)
{
	if (!img)
		return ;
	img->addr = NULL;
	img->mlx_img = NULL;
}

void	init_graphic(t_data *dt)
{
	dt->mlx_ptr = NULL;
	dt->win_ptr = NULL;
	dt->scene_img = NULL;
	dt->minimap_base_img = NULL;
	dt->minimap = NULL;
	dt->sky_image = NULL;
	dt->message_img = NULL;

}


//TODO: change hardcode 2
void	init_text_sprites(t_sprite_texture *texture)
{
	size_t	i;

	i = 0;
	while (i < 2)
	{
		texture->sprite_data[i] = NULL;
		texture->sprite_img[i] = NULL;
	}
	texture->filepath = NULL;
}

void	init_dt(t_data *dt)
{
	dt->doors = NULL;
	dt->rays = NULL;
	dt->sprites = NULL;
	dt->sprite_textures = NULL;
	dt->sprite_count = 0;
	dt->sprite_texture_count = 0;
	dt->view = NULL;
	dt->welcome_img = NULL;
	dt->background_music = NULL;
	dt->has_changed = 1;
	dt->frames_drawn = 0;
	init_mouse(&dt->mouse);
	init_map(&dt->map);
	init_graphic(dt);
}
