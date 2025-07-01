#include "cub3d.h"

void	init_text_sprites(t_sprite_texture *texture)
{
	size_t	i;

	i = 0;
	while (i < SPRITE_FRAMES)
	{
		texture->sprite_data[i] = NULL;
		texture->sprite_img[i] = NULL;
	}
	texture->filepath = NULL;
}
