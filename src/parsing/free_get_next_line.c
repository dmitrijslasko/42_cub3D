#include "cub3d.h"

char	*free_line_get_next(char *line, int fd)
{
	char	*str_new;

	if (line)
		free(line);
	line = NULL;
	str_new = get_next_line(fd);
	return (str_new);
}
