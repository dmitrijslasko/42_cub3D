#include "cub3d.h"

void	set_values_size_t(int *new_x, int *new_y, int x, int y)
{
	*new_x = x;
	*new_y = y;
}

// TODO FV: rename this function in the future
t_x_y	get_values_x_y(float x, float y)
{
	t_x_y	new;

	new.x = x;
	new.y = y;
	return (new);
}

void	set_values_x_y(t_x_y *new, float x, float y)
{
	new->x = x;
	new->y = y;
}

// TODO FV: rename this function in the future
t_coor	get_values_coor(int x, int y)
{
	t_coor	new;

	new.x = x;
	new.y = y;
	return (new);
}

void	set_value_coor(t_coor *new, int x, int y)
{
	new->x = x;
	new->y = y;
}
