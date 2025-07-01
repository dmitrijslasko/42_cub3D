#include "cub3d.h"

void	calc_texture_coor(t_data *dt, int *texture_y, \
							float *distance_to_wall, int d)
{
	float	wall_height;
	t_coor	tex_size;

	tex_size.y = dt->map.wall_tile->texture.height;
	wall_height = 1.0f / *distance_to_wall * SCALING;
	*texture_y = (d * tex_size.y) / (2 * wall_height);
	if (*texture_y >= tex_size.y)
		*texture_y = tex_size.y - 1;
}
