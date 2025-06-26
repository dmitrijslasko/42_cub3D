#include "cub3d.h"

void	update_value_max(size_t *count, char *line)
{
	if (*count < ft_strlen(line))
		*count = ft_strlen(line);
}

bool	check_empty_line_end_file(char *line, int fd)
{
	while (line && is_empty_line(line))
		line = free_line_get_next(line, fd);
	if (line)
		return (error_message("Error: don't expected line after map.", 1));
	return (0);
}

char	*get_first_line_map(int fd)
{
	bool	flag_map;
	char	*line;

	line = free_line_get_next(NULL, fd);
	flag_map = 0;
	while (line)
	{
		if (!is_empty_line(line) && !is_valid_line_texture(line))
			break ;
		line = free_line_get_next(line, fd);
	}
	return (line);
}

bool	set_size_map_data1(t_map *map, int fd)
{
	char	*line;
	size_t	count_row;
	size_t	count_col;

	count_col = 0;
	count_row = 0;
	line = get_first_line_map(fd);
	if (!line)
		return (error_message("Error: map not found.", 1));
	while (line)
	{
		if (is_empty_line(line))
			break ;
		if (is_valid_line_texture(line))
			return (error_free_char_return("Error map->", line, 1));
		count_row++;
		update_value_max(&count_col, line);
		line = free_line_get_next(line, fd);
	}
	if (check_empty_line_end_file(line, fd))
		return (1);
	free_line_get_next(line, -1);
	set_values_size_t(&map->map_size_cols, &map->map_size_rows, count_col, count_row);
	return (0);
}

bool	set_size_map_data(t_map *map, char *file)
{
	int	fd;
	int	ret;

	fd = ft_open(file);
	if (fd < 0)
		return (1);
	ret = set_size_map_data1(map, fd);
	close(fd);
	return (ret);
}
