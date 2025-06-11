#include "cub3d.h"

// NOTE DL: I believe this will be deprecated when we implement map parsing.
void	initialize_player_position(t_player *player,t_map *map)
{
	for (size_t x = 0; x < map->map_size_rows; x++)
	{
		for(size_t y = 0; y < map->map_size_cols; y++)
		{
			if (map->map_data[y][x] == 'N')
			{
				player->pos.x = x + 0.5;
				player->pos.y = y + 0.5;
				player->direction_vector.x = 0;
				player->direction_vector.y = -1;
			}
		}
	}
}

int	init_player(t_data *dt)
{
	t_player	*player;

	player = protected_malloc(sizeof(t_player), *dt);
	initialize_player_position(player, dt->map);
	dt->player = player;

	return (EXIT_SUCCESS);
}
