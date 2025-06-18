#include "cub3d.h"

void	init_default_color(t_color *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
	color->a = 0;
}

void	init_default_texture(t_texture *texture)
{
	texture->file = NULL;
	texture->texture_img = NULL;
	texture->texture_data = NULL;
}

void	init_default_wall_tile(t_wall_tile *wall_tile)
{
	wall_tile->is_color = 0;
	wall_tile->wall_type = DEFAULT;
	init_default_texture(&wall_tile->texture);
	init_default_color(&wall_tile->color);
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
	i = 0;
	while (i < 6)
		init_default_wall_tile(&new->wall_tile[i++]);
	*map = new;
	return (0);
}
