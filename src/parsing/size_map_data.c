#include "cub3d.h"

size_t	count_size_col(char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i + j])
	{
		j = 0;
		while (line[i + j] && ft_strchr(WHITE_SPACE, line[i + j]))
			j++;
		if (line[i + j])
		{
			i += j;
			j = 0;
		}
		if (line[i + j])
			i++;
	}
	return (i);
}

bool	set_size_map_data(t_map *map)
{
	bool	flag_map;
	int		fd;
	char	*line;
	size_t	count_row;
	size_t	count_col;

	count_col = 0;
	count_row = 0;
	flag_map = 0;
	fd = ft_open(map->file);
	if (fd < 0)
		return (1);
	line = free_line_get_next(NULL, fd);
	while (line)
	{
		if (is_empty_line(line) || is_valid_line_texture(line))
		{
			line = free_line_get_next(line, fd);
			if (flag_map && !is_empty_line(line))
				return (error_message_close_fd("Error map->", fd, 1));
			continue ;
		}
		flag_map = 1;
		count_row++;
		if (count_col < count_size_col(line))
			count_col = count_size_col(line);
		line = free_line_get_next(line, fd);
	}
	if (!flag_map)
		return (error_message_close_fd("Error: map not found.", fd, 1));
	free_line_get_next(line, -1);
	close(fd);
	set_values_size_t(&map->map_size_cols, &map->map_size_rows, count_col, count_row);
	return (0);
}
