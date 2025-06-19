#include "cub3d.h"
/**
 * A file texture should have this format .xpm
 */
bool	check_valid_texture(char **value)
{
	int		fd_texture_file;
	size_t	len;
	if (!value || !value[0] || value[1] || ft_strlen(value[0]) < 5)
		return (1);
	len = ft_strlen(value[0]);
	if (!ft_strncmp(value[len - 4], ".xpm", 4))
		return (error_message2("Error: Texture invalid", value[0], 1));
	fd_texture_file = open(value[0], O_RDONLY);
	if (fd_texture_file < 0)
		return (error_message2("Error: Opening texture", value[0], 1));
}

bool	set_color_or_texture(t_map *map, char *identifier, char **value)
{
	if (!identifier || !*value)
		return (error_message("Error: Split.", 1));
	
		return (set_color(identifier, value, map));
	return (set_texture(identifier, *value, map));
}

// bool	set_color_or_texture(t_map *map, char *identifier, char **value)
// {
// 	int	fd_tex;

// 	if (!identifier || !*value)
// 		return (error_message("Error: Split.", 1));
// 	fd_tex = open(*value, O_RDONLY);
// 	if (fd_tex < 0)
// 		return (set_color(identifier, value, map));
// 	close(fd_tex);
// 	return (set_texture(identifier, *value, map));
// }
