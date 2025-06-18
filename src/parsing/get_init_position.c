#include "cub3d.h"

void	find_position(t_player **player, size_t x, size_t y, char c)
{
	float	dir_x;
	float	dir_y;

	if (c == 'N')
	{
		dir_x = 0;
		dir_y = -1;
	}
	else if (c == 'S')
	{
		dir_x = 1;
		dir_y = 0;
	}
	else if (c == 'E')
	{
		dir_x = 0;
		dir_y = -1;
	}
	else
	{
		dir_x = 0;
		dir_y = 1;
	}
	set_values_x_y(&(*player)->direction_vector, dir_x, dir_y);
	set_values_x_y(&(*player)->pos, x + 0.5, y + 0.5);
}

void	get_init_position(t_map map, t_player **player)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (row < map.map_size_cols)
	{
		col = 0;
		while (col < map.map_size_rows)
		{
			if (ft_strchr("NSWE", map.map_data[col][row]))
			{
				find_position(player, row, col, map.map_data[col][row]);
				return ;
			}
			col++;
		}
		row++;
	}
}
