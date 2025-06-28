#include "cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
	array = NULL;
}

void	free_file_texture(t_data *dt)
{
	size_t	i;

	i = 0;
	while (i < NUMBER_TEXTURES)
	{
		if (dt->map.wall_tile[i].texture.file)
			free(dt->map.wall_tile[i].texture.file);
		i++;
	}
}

void	free_dt(t_data *dt)
{
	if (dt->mlx_ptr)
		free(dt->mlx_ptr);
	if (dt->win_ptr)
		free(dt->win_ptr);
	if (dt->scene_img)
		free(dt->scene_img);
	if (dt->minimap)
		free(dt->minimap);
	if (dt->minimap_base_img)
		free(dt->minimap_base_img);
	if (dt->doors)
		free(dt->doors);
	if (dt->rays)
		free(dt->rays);
	if (dt->map.map_data)
		free_array(dt->map.map_data);
	if (dt->sprites)
		free(dt->sprites);
	if (dt->sprite_textures)
		free(dt->sprite_textures);
	if (dt->view)
		free(dt->view);
	if (dt->welcome_img)
		free(dt->welcome_img);
	free_file_texture(dt);
}
