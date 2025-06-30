#include "cub3d.h"

void	free_texture(t_data *dt, t_texture *texture)
{
	if (!texture)
		return ;
	if (texture->texture_img && dt->mlx_ptr)
	{
		mlx_destroy_image(dt->mlx_ptr, texture->texture_img);
		texture->texture_img = NULL;
	}
	if (texture->file)
	{
		free(texture->file);
		texture->file = NULL;
	}
}
