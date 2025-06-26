#include "cub3d.h"

void	update_value_max(size_t *count, char *line)
{
	if (*count < ft_strlen(line))
		*count = ft_strlen(line);
}
