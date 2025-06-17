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
	if (map->textures[wall_type - 1].file)
		return (error_message("Error: duplicated wall.", 1));
	map->textures[wall_type - 1].wall_type = wall_type;
	map->textures[wall_type - 1].file = file_texture;
	return (0);
}

bool	set_color(char *identifier, char *color, t_map *map)
{
	char	**array;
	t_color	select;

	if (identifier[0] == 'C')
	{
		if (map->ceiling_color.b != -1)
			return (error_message("Error: duplicated ceiling.", 1));
		select = map->ceiling_color;
	}
	else if (identifier[0] == 'F')
	{
		if (map->floor_color.b != -1)
			return (error_message("Error: duplicated floor.", 1));
		select = map->floor_color;
	}
	else
		return (0);
	array = ft_split(color, ',');
	if (!array)
		return (error_message("Error: Malloc.", 0));
	select.r = ft_atoi(array[0]);
	select.g = ft_atoi(array[1]);
	select.b = ft_atoi(array[2]);
	free_array_return(array, 1);
	return (0);
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
			if (set_color(array[0], array[1], map) || \
				set_texture(array[0], array[1], map))
				return (free_array_return(array, 1));
		}
		line = free_line_get_next(line, fd);
		free_array_return(array, 0);
	}
	get_value_map(line, fd, map);
	return (0);
}
