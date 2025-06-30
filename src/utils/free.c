#include "cub3d.h"

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
	return ;
}

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

void	free_img(t_img *img, void *mlx_ptr)
{
	if (img->mlx_img)
		mlx_destroy_image(mlx_ptr, img->mlx_img);
	img->mlx_img = NULL;
}

void	free_texture(t_data *dt, t_texture *texture)
{
	if (texture && texture->file)
	{
		free(texture->file);
		texture->file = NULL;
		free_img(texture->texture_img, dt->mlx_ptr);
		texture->texture_img = NULL;
	}
}


void	free_wall_tile_texture(t_data *dt)
{
	size_t	i;

	i = 0;
	while (i < NUMBER_TEXTURES)
	{
		if (!dt->map.wall_tile[i].is_color)
			free_texture(dt, &dt->map.wall_tile[i].texture);
		i++;
	}
}

void	free_graphic(t_data *dt)
{
	free_img(dt->scene_img, dt->mlx_ptr);
	free_img(dt->minimap_base_img, dt->mlx_ptr);
	free_img(dt->minimap, dt->mlx_ptr);
	free_img(dt->sky_image, dt->mlx_ptr);
	free_img(dt->message_img, dt->mlx_ptr);
	mlx_destroy_display(dt->mlx_ptr);
	mlx_destroy_window(dt->mlx_ptr, dt->win_ptr);
	dt->mlx_ptr = NULL;
}

void	free_dt(t_data *dt)
{
	ft_free(dt->doors);
	ft_free(dt->rays);
	free_array(dt->map.map_data);
	ft_free(dt->sprites);
	ft_free(dt->view);
	if (dt->sprite_textures)
		ft_free(dt->sprite_textures);
	free_wall_tile_texture(dt);
	free_audio(dt->background_music);
}
