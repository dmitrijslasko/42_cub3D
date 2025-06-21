#include "cub3d.h"

bool	set_size_map_data(t_map *map, char *file)
{
	bool	flag_map;
	int		fd;
	char	*line;
	size_t	count_row;
	size_t	count_col;

	count_col = 0;
	count_row = 0;
	flag_map = 0;
	fd = ft_open(file);
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
		if (count_col < ft_strlen(line))
			count_col = ft_strlen(line);
		line = free_line_get_next(line, fd);
	}
	if (!flag_map)
		return (error_message("Error: map not found.", 1));
	free_line_get_next(line, -1);
	close(fd);
	set_values_size_t(&map->map_size_cols, &map->map_size_rows, count_col, count_row);
	return (0);
}
