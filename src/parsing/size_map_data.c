#include "cub3d.h"

char	*free_line_get_next(char *line, int fd)
{
	char	*str_new;

	if (line)
		free(line);
	str_new = get_next_line(fd);
	return (str_new);
}

bool	set_size_map_data(t_map *map, char *file)
{
	int		fd;
	char	*line;
	size_t	count_row;
	size_t	count_col;

	count_col = 0;
	count_row = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error_message_close_fd("Error opening file.", fd, 1));
	line = free_line_get_next(NULL, fd);
	while (line)
	{
		if (is_empty_line(line) || is_valid_line_texture(line))
		{
			line = free_line_get_next(line, fd);
			continue ;
		}
		count_row++;
		if (count_col < ft_strlen(line))
			count_col = ft_strlen(line);
		line = free_line_get_next(line, fd);
	}
	map->map_size_cols = count_col;
	map->map_size_rows = count_row;
	close(fd);
	return (0);
}
