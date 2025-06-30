#include "cub3d.h"

void	free_texture_sprite(t_data *dt)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dt->sprite_texture_count)
	{
		j = 0;
		while (j < SPRITE_FRAMES)
		{
			if (dt->sprite_textures[i].sprite_img[j])
				mlx_destroy_image(dt->mlx_ptr, dt->sprite_textures[i].sprite_img[j]);
			dt->sprite_textures[i].sprite_img[j] = NULL;
			j++;
		}
		i++;
	}
}
