#include "cub3d.h"

void	free_wall_tile_texture(t_data *dt)
{
	size_t	i;

	i = 0;
	while (i < NUMBER_TEXTURES)
	{
		if (!dt->map.wall_tile[i].is_color)
			free_texture(dt, &dt->map.wall_tile[i].texture);
		i++;
	}
	free_texture(dt, &dt->map.door.texture);
}
