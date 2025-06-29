#include "cub3d.h"

int init_keys(t_data *dt)
{
	size_t i;

	i = 0;
	while (i < TRACKED_KEYS)
	{
		dt->keys[i] = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}
