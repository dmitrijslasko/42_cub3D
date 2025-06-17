#include "cub3d.h"

void	init_default_color(t_color *color)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
}

void	init_default_texture(t_texture *texture)
{
	texture->file = NULL;
	texture->texture_img = NULL;
	texture->texture_data = NULL;
}

bool	init_default_map(t_map **map)
{
	t_map	*new;
	int		i;

	new = malloc(sizeof(t_map));
	if (!map)
		return (error_message("Malloc error.", 1));
	new->map_data = NULL;
	new->map_size_cols = 0;
	new->map_size_rows = 0;
	init_default_color(&new->ceiling_color);
	init_default_color(&new->floor_color);
	i = 0;
	while (i < 4)
		init_default_texture(&new->textures[i++]);
	*map = new;
	return (0);
}

bool	init_value_map_data(char *file, t_data *dt)
{
	if (init_default_map(&dt->map))
		return (1);
	if (set_size_map_data(dt->map, file))
		return (1);
	if (create_map_data(dt->map))
		return (1);
	if (get_value_file(dt->map, file))
		return (1);
	if (check_valid_player(dt))
		return (1);
	return (0);
}

