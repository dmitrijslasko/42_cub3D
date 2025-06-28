#include "cub3d.h"

t_door *find_door_at(t_data *dt, int x, int y)
{
	size_t	i;

	i = 0;
	while (i < dt->door_count)
	{
		// printf("%d vs %d   %d vs %d\n", dt->doors[i].cell_x, x, dt->doors[i].cell_y, y);
		if (dt->doors[i].cell_x == x && dt->doors[i].cell_y == y)
		{
			// printf("Door found!\n");
			return &dt->doors[i];
		}
		i++;
	}
	return (NULL);
}
