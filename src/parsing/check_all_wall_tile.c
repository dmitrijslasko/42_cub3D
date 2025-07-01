#include "cub3d.h"

bool	check_all_wall_tile(t_map *map)
{
	int	i;

	i = 0;
	while (i < NUMBER_TEXTURES)
		if (map->wall_tile[i++].wall_type == DEFAULT_WALL)
			return (error_msg("Error: Wall, floor or door N/D.", 0));
	return (1);
}
