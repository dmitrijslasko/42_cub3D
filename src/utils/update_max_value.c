#include "cub3d.h"

void	update_value_max(int *count, char *line)
{
	if ((size_t)*count < ft_strlen(line))
		*count = (int)ft_strlen(line);
}
