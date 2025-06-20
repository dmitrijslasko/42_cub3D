#include "cub3d.h"

bool	init_default_player(t_player *player)
{
	player->can_move = false;
	player->direction_vector_deg = 0;
	player->move_speed_multiplier = 0;
	set_values_x_y(&player->direction_vector, 0, 1);
	set_values_x_y(&player->pos, 0, 0);
	return (0);
}

bool	init_value_player(t_map map, t_player *player)
{
	if (init_default_player(player))
		return (1);
	get_init_position(map, player);
	return (0);
}

bool	parsing(t_data *dt, char *file)
{
	int	fd;

	if (!check_type_file(file, "cub"))
		return (1);
	fd = ft_open(file);
	if (fd <= 0)
		return (1);
	if (check_valid_wall_tile_file(fd))
		return (error_message_close_fd("Error: Reading textures.", fd, 1));
	if (init_value_map_data(file, &dt->map))
		return (1);
	if (init_value_player(dt->map, &dt->player))
		return (1);
	return (0);
}
