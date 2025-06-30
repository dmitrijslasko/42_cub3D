#include "cub3d.h"

void	sprite_put_color(t_data *dt, t_sprite *sprite,
	t_coor *coor, t_coor *tex_coor)
{
	int					time;
	t_sprite_texture	*texture;
	unsigned int		color;

	time = sprite->time;
	texture = sprite->texture;
	color = texture->sprite_data[time][tex_coor->y * texture->width + \
			tex_coor->x];
	if (color == TRANSPARENT_COLOR)
		return ;
	img_pix_put(dt->scene_img, coor->x, coor->y, color);
}
