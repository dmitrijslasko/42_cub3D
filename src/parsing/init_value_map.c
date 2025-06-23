#include "cub3d.h"

bool	init_value_map_data(char *file, t_map *map)
{
	if (init_default_map(map, file))
		return (1);
	if (set_size_map_data(map))
		return (1);
	if (create_map_data(map))
		return (1);
	if (get_value_file(map))
		return (1);
	if (!check_valid_player(map))
		return (1);
	return (!check_all_wall_tile(map));
}
