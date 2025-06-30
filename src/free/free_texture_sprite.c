#include "cub3d.h"

//TODO FV: Change 2 for NUM_FRAMES. No  hardcode;
void	free_texture_sprite(t_data *dt)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dt->sprite_texture_count)
	{
		j = 0;
		while (j < 2)
		{
			if (dt->sprite_textures[i].sprite_img[j])
				mlx_destroy_image(dt->mlx_ptr, dt->sprite_textures[i].sprite_img[j]);
			dt->sprite_textures[i].sprite_img[j] = NULL;
			j++;
		}
		i++;
	}
}