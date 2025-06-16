#include "cub3d.h"

bool	find_position(t_data *dt, size_t x, size_t y)
{
	if (dt->map->map_data[y][x] == 'N')
	{
		dt->player->direction_vector.x = 0;
		dt->player->direction_vector.y = -1;
	}
	else if (dt->map->map_data[y][x] == 'S')
	{
		dt->player->direction_vector.x = 1;
		dt->player->direction_vector.y = 0;
	}
	else if (dt->map->map_data[y][x] == 'E')
	{
		dt->player->direction_vector.x = 0;
		dt->player->direction_vector.y = -1;
	}
	else if (dt->map->map_data[y][x] == 'W')
	{
		dt->player->direction_vector.x = 0;
		dt->player->direction_vector.y = 1;
	}
	else
		return (0);
	set_values_x_y(&dt->player->pos, x + 0.5, y + 0.5);
	return (1);
}

void	get_init_position(t_data *dt)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < dt->map->map_size_cols)
	{
		while (y < dt->map->map_size_rows)
		{
			if (find_position(dt->map->map_data, x, y))
				return ;
			y++;
		}
		x++;
	}
}
