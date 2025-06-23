#include "cub3d.h"

bool	get_value_file(t_map *map, char *file)
{
	int		fd;
	char	*line;
	char	**array;

	fd = ft_open(file);
	if (fd < 0)
		return (1);
	line = free_line_get_next(NULL, fd);
	while (line && (is_empty_line(line) || is_valid_line_texture(line)))
	{
		if (is_valid_line_texture(line))
		{
			array = ft_split_special(line, WHITE_SPACE);
			if (set_color_or_texture(map, array[0], &array[1]))
				return (free_array_return(array, 1));
			free_array(array);
		}
		line = free_line_get_next(line, fd);
	}
	get_value_map(line, fd, map);
	close (fd);
	return (0);
}
