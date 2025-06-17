#include "cub3d.h"

bool	check_valid_texture_file(int fd)
{
	char	**array;
	char	*line;

	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (is_empty_line(line))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (!is_valid_line_texture(line))
			break ;
		array = ft_split(line, ' ');
		if (!array || !array[0] || !array[1] || array[2])
			return (error_message_free("Not valid input!", array, 1));
		if (!check_valid_texture(array))
			return (free_array_return(array, 1));
		free(line);
		line = get_next_line(fd);
	}
	return (free_array_return(array, 0));
}
