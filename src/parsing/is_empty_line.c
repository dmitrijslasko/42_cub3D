#include "cub3d.h"

bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == ' ' || line[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}
