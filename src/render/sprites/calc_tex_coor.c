#include "cub3d.h"

t_coor	calculate_tex_x_y(t_sprite_texture *texture, t_coor *coor,
	t_coor *offset, t_coor *sprite_size)
{
	t_coor	tex_coor;

	tex_coor.y = (coor->y - offset->y) * texture->height / sprite_size->y;
	tex_coor.x = (coor->x - offset->x) * texture->width / sprite_size->x;
	return (tex_coor);
}
