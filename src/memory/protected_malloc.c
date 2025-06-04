#include "cub3d.h"

void	*protected_malloc(size_t size, t_data *dt)
{
	void	*ptr;

	(void)dt;
	if (size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
	{
		perror("Failed to allocate memory.");
		//if (dt)
		//	free_data(dt);
		exit (1);
	}
	memset(ptr, 0, size);
	return (ptr);
}
