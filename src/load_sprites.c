#include "cub3d.h"

int	load_sprite_images(t_data *dt)
{
	size_t		i;
	t_sprite	*sprites;
	size_t		sprite_count;

	sprite_count = count_elements_in_the_map(&dt->map, "s");
	i = 0;
	sprites = dt->sprites;

	printf("Sprite images to be loaded: %zu\n", sprite_count);
	while (i < sprite_count)
	{
		sprites[i].sprite_img = mlx_xpm_file_to_image( \
			dt->mlx_ptr, \
			"./sprites/sprite-1.xpm", \
			&sprites[i].width, \
			&sprites[i].height \
		);

		sprites[i].sprite_data = (int *)mlx_get_data_addr( \
			sprites[i].sprite_img, \
			&sprites[i].bpp, \
			&sprites[i].size_line, \
			&sprites[i].endian \
		);
		printf("Sprite image loaded!\n");
		i++;
	}

	return (EXIT_SUCCESS);
}


int	load_sprites(t_data *dt)
{
	size_t	sprite_count;

	printf("Loading sprites...\n");
	print_separator_default();

	sprite_count = count_elements_in_the_map(&dt->map, "s");
	printf("Sprites found in the map: %zu\n", sprite_count);
	dt->sprites = protected_malloc(sizeof(t_sprite) * sprite_count, *dt);
	load_sprite_images(dt);
	dt->sprites->x = 1.5f;
	dt->sprites->y = 1.5f;

	printf("Done!\n");
	return (EXIT_SUCCESS);
}
