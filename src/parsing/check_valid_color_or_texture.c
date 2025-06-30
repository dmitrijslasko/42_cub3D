#include "cub3d.h"

bool	check_valid_color_or_texture(char **info)
{
	int	fd_texture_file;

	fd_texture_file = open(info[1], O_RDONLY);
	if (fd_texture_file < 0)
	{
		if (!check_valid_color(&info[1]))
			return (error_message2("Error: invalid color or file for ", \
									info[0], 0));
		return (1);
	}
	close(fd_texture_file);
	if (info[2])
		return (error_message2("Error: invalid file for ", info[0], 0));
	return (1);
}
