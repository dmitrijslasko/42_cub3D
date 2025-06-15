#include "cub3d.h"

bool	find_position(t_data *dt, size_t x, size_t y)
{
	if (dt->map->map_data[x][y] == 'N')
	{
		dt->player->direction_vector.x = 
		dt->player->direction_vector.y = 
	}
	else if (dt->map->map_data[x][y] == 'S')
	{
			dt->player->direction_vector.x = 
			dt->player->direction_vector.y = 
	}
	else if (dt->map->map_data[x][y] == 'E')
	{
			dt->player->direction_vector.x = 
			dt->player->direction_vector.y = 
	}
	else if (dt->map->map_data[x][y] == 'W')
	{
			dt->player->direction_vector.x = 
			dt->player->direction_vector.y = 
	}
	return (0);
}

int	get_init_position(t_data *dt)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < dt->map->map_size_cols)
	{
		while (y < dt->map->map_size_rows)
		{
			find_position(dt->map->map_data, x, y);
		}
		x++;
	}

}