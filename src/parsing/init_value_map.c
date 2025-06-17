#include "cub3d.h"

bool	init_value_map_data(char *file, t_data *dt)
{
	if (set_size_map_data(dt->map, file))
		return (1);
	if (create_map_data(dt->map))
		return (1);
	check_valid_player(dt);
	return (0);
}

