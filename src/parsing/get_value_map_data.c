#include "cub3d.h"

void	copy_line(t_map *map, int row, char *line)
{
	size_t	i;

	i = 0;
	while (line && line[i])
	{
		map->map_data[row][i] = line[i];
		i++;
	}
}

void	get_value_map(char *line, int fd, t_map *map)
{
	size_t	count_row;

	count_row = 0;
	while (line && !is_empty_line(line))
	{
		copy_line(map, count_row, line);
		line = free_line_get_next(line, fd);
		count_row++;
	}
}

bool	set_texture(char *identifier, char *file_texture, t_map *map)
{
	t_type_wall	wall_type; 

	if (!check_valid_identifier_texture(identifier))
		return (0);
	wall_type = check_valid_identifier_texture_wall(identifier);
	if (map->wall_tile[wall_type].texture.file || map->wall_tile[wall_type].is_color)
		return (error_message("Error: duplicated wall/door/floor.", 1));
	map->wall_tile[wall_type].wall_type = wall_type;
	map->wall_tile[wall_type].texture.file = file_texture;
	return (0);
}

bool	set_color(char *identifier, char *color, t_map *map)
{
	char	**array;
	t_type_wall	wall_type;

	wall_type = check_valid_identifier_texture_wall(identifier);
	if (map->wall_tile[wall_type].texture.file || map->wall_tile[wall_type].is_color)
		return (error_message("Error: duplicated wall/door/floor.", 1));
	array = ft_split(color, ',');
	if (!array)
		return (error_message("Error: Malloc.", 1));
	map->wall_tile[wall_type].is_color = true;
	map->wall_tile[wall_type].color.r = ft_atoi(array[0]);
	map->wall_tile[wall_type].color.g = ft_atoi(array[1]);
	map->wall_tile[wall_type].color.b = ft_atoi(array[2]);
	return (free_array_return(array, 0));
}

bool	set_color_or_texture(t_map *map, char *identifier, char *value)
{
	int	fd_tex;

	if (!identifier || !value)
		return (error_message("Error: Split.", 1));
	remove_new_line(value);
	fd_tex = open(value, O_RDONLY);
	if (fd_tex < 0)
		return (set_color(identifier, value, map));
	close(fd_tex);
	return (set_texture(identifier, value, map));
}

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
			array = ft_split(line, ' ');
			if (set_color_or_texture(map, array[0], array[1]))
				return (free_array_return(array, 1));
			free_array_return(array, 0);
		}
		line = free_line_get_next(line, fd);
	}
	get_value_map(line, fd, map);
	close (fd);
	return (0);
}
