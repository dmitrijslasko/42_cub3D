#include "cub3d.h"

bool	init_value_map_data(char *file, t_data *dt)
{
	if (init_default_map(&dt->map))
		return (1);
	if (set_size_map_data(&dt->map, file))
		return (1);
	if (create_map_data(&dt->map, dt))
		return (1);
	if (get_value_file(&dt->map, file))
		return (1);
	if (!check_valid_player(&dt->map))
		return (1);
	return (!check_all_wall_tile(&dt->map));
}
