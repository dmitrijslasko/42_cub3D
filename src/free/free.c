#include "cub3d.h"

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
	return ;
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
	array = NULL;
}
