#include "cub3d.h"

bool	set_texture(char *identifier, char *file_texture, t_map *map)
{
	t_type_wall	wall_type; 

	if (!check_valid_identifier_texture(identifier))
		return (0);
	wall_type = check_valid_identifier_texture_wall(identifier);
	if (map->wall_tile[wall_type].wall_type != DEFAULT)
		return (error_message("Error: duplicated wall/door/floor.", 1));
	map->wall_tile[wall_type].wall_type = wall_type;
	map->wall_tile[wall_type].texture.file = file_texture;
	return (0);
}
