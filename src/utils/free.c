#include "cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (!array[i])
		free(array[i++]);
	free(array);
	array = NULL;
}

