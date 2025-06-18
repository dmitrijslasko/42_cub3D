#include "cub3d.h"

bool	set_color_or_texture(t_map *map, char *identifier, char *value)
{
	int	fd_tex;

	if (!identifier || !value)
		return (error_message("Error: Split.", 1));
	// remove_new_line(value);
	fd_tex = open(value, O_RDONLY);
	if (fd_tex < 0)
		return (set_color(identifier, value, map));
	close(fd_tex);
	return (set_texture(identifier, value, map));
}
