#include "cub3d.h"

t_door	*find_door_at(t_data *dt, int x, int y)
{
	size_t	i;

	i = 0;
	while (i < dt->door_count)
	{
		if (dt->doors[i].cell_x == x && dt->doors[i].cell_y == y)
			return (&dt->doors[i]);
		i++;
	}
	return (NULL);
}
