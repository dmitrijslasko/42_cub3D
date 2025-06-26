#include "cub3d.h"

size_t	size_array(char **array)
{
	size_t	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}
