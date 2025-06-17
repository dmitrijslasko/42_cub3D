#include "cub3d.h"

bool	parsing(t_data *dt, char *file)
{
	int	fd;

	(void)dt;
	if (!check_type_file(file, "cub"))
		return (1);
	fd = ft_open(file);
	if (fd <= 0)
		return (1);
	if (check_valid_texture_file(fd))
		return (error_message_close_fd("Error: Reading textures.", fd, 1));
	init_value_map_data(file, dt);
	return (0);
}
