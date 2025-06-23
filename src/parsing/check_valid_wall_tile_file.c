#include "cub3d.h"

bool	check_valid_wall_tile_file(int fd)
{
	char	**array;
	char	*line;


	array = NULL;
	line = free_line_get_next(NULL, fd);
	while (line)
	{
		if (is_empty_line(line))
		{
			line = free_line_get_next(line, fd);
			continue ;
		}
		if (!is_valid_line_texture(line))
			break ;
		array = ft_split_special(line, WHITE_SPACE);
		if (!array || !array[0] || !array[1])
			return (error_message_free("Not valid input!", array, 1));
		if (!check_valid_color_or_texture(array))
			return (free_array_return(array, 1));
		line = free_line_get_next(line, fd);
	}
	free_line_get_next(line, -1);
	close(fd);
	return (free_array_return(array, 0));
}
