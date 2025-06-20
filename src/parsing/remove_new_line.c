#include "cub3d.h"

void	remove_new_line(char *str)
{
	size_t	last_pos;

	if (!str)
		return ;
	last_pos = ft_strlen(str);
	if (last_pos != 0 && str[last_pos - 1] == '\n')
		str[last_pos - 1] = '\0';
}
