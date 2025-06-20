#include "cub3d.h"

bool	set_color(char *identifier, char *color, t_map *map)
{
	char		**array;
	t_type_wall	wall_type;

	wall_type = check_valid_identifier_texture_wall(identifier);
	if (map->wall_tile[wall_type].wall_type != DEFAULT)
		return (error_message("Error: duplicated wall/door/floor.", 1));
	array = ft_split(color, ',');
	if (!array)
		return (error_message("Error: Malloc.", 1));
	map->wall_tile[wall_type].wall_type = wall_type;
	map->wall_tile[wall_type].is_color = true;
	map->wall_tile[wall_type].color.r = ft_atoi(array[0]);
	map->wall_tile[wall_type].color.g = ft_atoi(array[1]);
	map->wall_tile[wall_type].color.b = ft_atoi(array[2]);
	return (free_array_return(array, 0));
}
