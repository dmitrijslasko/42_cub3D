#include "cub3d.h"

int	update_coor_pos(int pos, double dir, int signal)
{
	if (signal > 0)
	{
		if (dir > 0)
			return (pos + 1);
	}
	if (signal < 0)
	{
		if (dir < 0)
			return (pos - 1);
	}
	return (pos);
}

t_coor	get_updated_coor_player(t_x_y pos, t_x_y dir, int signal)
{
	int	x;
	int	y;

	x = update_coor_pos((int)pos.x, dir.x, signal);
	y = update_coor_pos((int)pos.y, dir.y, signal);
	return (get_values_coor(x, y));
}

t_coor	get_updated_coor_player_(t_coor coor, t_x_y dir, int signal)
{
	int	x;
	int	y;

	x = update_coor_pos(coor.x, dir.x, signal);
	y = update_coor_pos(coor.y, dir.y, signal);
	return (get_values_coor(x, y));
}
