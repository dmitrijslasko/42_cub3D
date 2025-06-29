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

void	free_img(t_img *img, void *mlx_ptr)
{
	if (img->mlx_img)
		mlx_destroy_image(mlx_ptr, img->mlx_img);
	img->mlx_img = NULL;
}

void	free_dt(t_data *dt)
{
	if (dt->win_ptr)
		mlx_destroy_window(dt->mlx_ptr, dt->win_ptr);
	dt->win_ptr = NULL;
	free_img(dt->scene_img, dt->mlx_ptr);
	free_img(dt->minimap_base_img, dt->mlx_ptr);
	free_img(dt->minimap, dt->mlx_ptr);
	free_img(dt->sky_image, dt->mlx_ptr);
	free_img(dt->message_img, dt->mlx_ptr);
	free_img(dt->welcome_img, dt->mlx_ptr);
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
	free_file_texture(dt);
	mlx_destroy_display(dt->mlx_ptr);
	dt->mlx_ptr = NULL;
	// free(dt->bgm);
}
