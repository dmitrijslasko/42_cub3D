#include "cub3d.h"

void	*protected_malloc(size_t size, t_data *dt)
{
	void	*ptr;

	if (size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
	{
		perror("Failed to allocate memory.");
		if (dt)
			free_dt(dt);
		exit (1);
	}
	return (ptr);
}
