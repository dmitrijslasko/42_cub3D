#include "cub3d.h"

bool	is_valid_position(t_map map, size_t x, size_t y)
{
	if (x == 0 || x == map.map_size_cols)
		return (0);
	if (y == 0 || y == map.map_size_rows)
		return (0);
	if (map.map_data[y][x - 1] == ' ' || map.map_data[y][x + 1] == ' ')
		return (0);
	if (map.map_data[y - 1][x] == ' ' || map.map_data[y + 1][x] == ' ')
		return (0);
	return (1);
}

bool	check_valid_player(t_data *dt)
{
	size_t	x;
	size_t	y;
	bool	flag;

	x = 0;
	y = 0;
	flag = 0;
	while (x < dt->map->map_size_cols)
	{
		while (y < dt->map->map_size_rows)
		{
			if (is_delimiter(dt->map->map_data[y][x], "NSWE") && flag)
				return (0);
			if (is_delimiter(dt->map->map_data[y][x], "NSWE"))
			{
				if (!is_valid_position(*dt->map, x, y))
					return (0);
				flag = 1;
			}
			y++;
		}
		x++;
	}
	return (1);
}
