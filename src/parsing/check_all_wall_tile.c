#include "cub3d.h"

bool	check_all_wall_tile(t_map *map)
{
	int	i;

	i = 0;
	while (i < NUMBER_TEXTURES)
	{
		if (map->wall_tile[i].wall_type == DEFAULT_WALL)
			return (error_msg("Error: Wall, floor or ceiling N/D.", 0));
		if (i == NORTH || i == SOUTH || i == WEST || i == EAST)
		{
			if (map->wall_tile[i].is_color)
				return (error_msg("Error: Walls need to be a texture.", 0));
		}
		else
		{
			if (!map->wall_tile[i].is_color)
				return (error_msg("Error: Ceiling/Floor is not a color.", 0));
		}
		i++;
	}
	return (1);
}
