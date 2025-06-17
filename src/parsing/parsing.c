#include "cub3d.h"

bool	parsing(t_data *dt, char *file)
{
	int	fd;

	(void)dt;
	fd = open(file, O_RDONLY);
	if (check_valid_texture_file(fd))
		return (error_message_close_fd("Error: Reading textures.", fd, 1));
	return (0);
}
