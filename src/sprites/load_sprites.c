#include "cub3d.h"

int	load_sprite_images(t_data *dt)
{
	size_t			i;
	t_sprite_txt	*sprites_txt;

	i = 0;
	sprites_txt = dt->sprites_txt;
	printf("Sprite images to be loaded: %zu\n", dt->sprite_txt_count);
	while (i < dt->sprite_txt_count)
	{
		if (i == 0)
		{
			sprites_txt[i].type = 's';
			sprites_txt[i].sprite_img = mlx_xpm_file_to_image( \
			dt->mlx_ptr, \
			"./sprites/sprite-1.xpm", \
			&sprites_txt[i].width, \
			&sprites_txt[i].height \
			);
		}

		if (i == 1)
		{
			sprites_txt[i].type = 'q';
			sprites_txt[i].sprite_img = mlx_xpm_file_to_image( \
			dt->mlx_ptr, \
			"./sprites/KODOS.xpm", \
			&sprites_txt[i].width, \
			&sprites_txt[i].height \
			);
		}

		sprites_txt[i].sprite_data = (int *)mlx_get_data_addr( \
			sprites_txt[i].sprite_img, \
			&sprites_txt[i].bpp, \
			&sprites_txt[i].size_line, \
			&sprites_txt[i].endian \
		);
		printf("Sprite image loaded!\n");
		i++;
	}

	return (EXIT_SUCCESS);
}

int	load_sprites_textures(t_data *dt)
{
	size_t	sprite_type_count;

	sprite_type_count = count_types_elements_in_the_map(&dt->map, SPRITES_TYPES);
	if (sprite_type_count == 0)
		return (EXIT_SUCCESS);
	printf("Sprites found in the map: %zu\n", sprite_type_count);
	dt->sprites_txt = protected_malloc(sizeof(t_sprite_txt) * sprite_type_count, dt);
	dt->sprite_txt_count = sprite_type_count;
	load_sprite_images(dt);
}

int	load_sprites(t_data *dt)
{
	printf("Loading sprites...\n");
	print_separator_default();

	load_sprites_textures(dt);

	find_all_sprites(dt);
	sort_sprites_distance(dt);
	printf("Done!\n");
	return (EXIT_SUCCESS);
}
