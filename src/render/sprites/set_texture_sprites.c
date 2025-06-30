#include "cub3d.h"

bool	set_texture_sprites(t_data *dt)
{
	size_t	i;
	size_t	j;

	if (!dt->sprites || !dt->sprite_textures)
		return (0);
	i = 0;
	while (i < dt->sprite_count)
	{
		j = 0;
		while (j < dt->sprite_texture_count)
		{
			if (dt->sprites[i].type == dt->sprite_textures[j].type)
			{
				dt->sprites[i].texture = &dt->sprite_textures[j];
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}
