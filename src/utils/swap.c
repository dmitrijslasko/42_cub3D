#include "cub3d.h"

void	swap(void *a, void *b, size_t size)
{
	void	*temp;

	temp = malloc(size);
	if (temp == NULL)
		return ;
	memcpy(temp, a, size);
	memcpy(a, b, size);
	memcpy(b, temp, size);
	free(temp);
}
