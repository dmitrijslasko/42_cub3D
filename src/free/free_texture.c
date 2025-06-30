#include "cub3d.h"

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
