#include "cub3d.h"

bool	parsing(t_data *dt, char *file)
{
	if (!check_type_file(file, ".cub"))
		return (1);
	if (!check_valid_wall_tile_file(file))
		return (1);
	if (init_value_map_data(file, &dt->map))
		return (1);
	if (init_value_player(&dt->map, &dt->player))
		return (1);
	if (!check_valid_map(&dt->map, &dt->player))
		return (1);
	return (0);
}
