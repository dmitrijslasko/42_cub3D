#include "cub3d.h"

void	add_color(t_color *color, int num_color, int count)
{
	if (count == 1)
		color->r = num_color;
	else if (count == 2)
		color->g = num_color;
	else
		color->b = num_color;
}

t_color	get_color(char **color_arr)
{
	t_color	color;
	char	**array;
	int		count;
	size_t	i;
	size_t	j;

	i = 0;
	count = 1;
	while (color_arr[i])
	{
		j = 0;
		array = ft_split(color_arr[i++], ',');
		while (array[j])
			add_color(&color, ft_atoi(array[j++]), count++);
		free_array(array);
	}
	return (color);
}

bool	set_color(char *identifier, char **color, t_map *map)
{
	t_type_wall	wall_type;

	wall_type = check_valid_identifier_texture_wall(identifier);
	if (map->wall_tile[wall_type].wall_type != DEFAULT)
		return (error_message("Error: duplicated wall/door/floor.", 1));
	map->wall_tile[wall_type].wall_type = wall_type;
	map->wall_tile[wall_type].is_color = true;
	map->wall_tile[wall_type].color = get_color(color);
	return (0);
}
