#include "cub3d.h"

bool	is_delimiter(char c, const char *delimiters)
{
	size_t	i;

	i = 0;
	while (delimiters[i])
	{
		if (c == delimiters[i++])
			return (true);
	}
	return (false);
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
				return (1);
			if (is_delimiter(dt->map->map_data[y][x], "NSWE") && !flag)
				flag = 1;
			y++;
		}
		x++;
	}
	return (0);
}
