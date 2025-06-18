#include "cub3d.h"

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error_message_close_fd("Error opening file.", fd, -1));
	return (fd);
}
