#include "cub3d.h"

bool	check_all_wall_tile(t_map map)
{
	int	i;

	i = 0;
	while (i < 6)
		if (map.wall_tile[i++].wall_type == DEFAULT)
			return (error_message("Error: Wall or door no definided.", 0));
	return (1);
}
