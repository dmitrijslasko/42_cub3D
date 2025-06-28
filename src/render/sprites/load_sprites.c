#include "cub3d.h"

int	load_sprite_images(t_data *dt)
{
	size_t			i;
	t_sprite_texture	*sprite_textures;

	i = 0;
	sprite_textures = dt->sprite_textures;
	printf("Sprite images to be loaded: %zu\n", dt->sprite_texture_count);

	while (i < dt->sprite_texture_count)
	{
		if (i == 0)
		{
			sprite_textures[i].type = 's';
			sprite_textures[i].sprite_img = mlx_xpm_file_to_image( \
										dt->mlx_ptr, \
										"./sprites/cacti1-min.xpm", \
										&sprite_textures[i].width, \
										&sprite_textures[i].height \
			);
		}

		if (i == 1)
		{
			sprite_textures[i].type = 'q';
			sprite_textures[i].sprite_img = mlx_xpm_file_to_image( \
										dt->mlx_ptr, \
										"./sprites/cacti2-min.xpm", \
										&sprite_textures[i].width, \
										&sprite_textures[i].height \
			);
		}

		sprite_textures[i].sprite_data = (int *)mlx_get_data_addr( \
			sprite_textures[i].sprite_img, \
			&sprite_textures[i].bpp, \
			&sprite_textures[i].size_line, \
			&sprite_textures[i].endian \
		);
		printf("Sprite image loaded!\n");
		i++;
	}

	return (EXIT_SUCCESS);
}

int	load_sprite_textures(t_data *dt)
{
	size_t	sprite_element_count;
	size_t	sprite_type_count;

	sprite_element_count = count_elements_in_the_map(&dt->map, SPRITES_TYPES);
	sprite_type_count = count_types_elements_in_the_map(&dt->map, SPRITES_TYPES);
	if (sprite_type_count == 0)
		return (EXIT_SUCCESS);
	printf("Sprite elements found in the map: %zu\n", sprite_element_count);
	printf("Sprite types found in the map: %zu\n", sprite_type_count);
	dt->sprite_textures = protected_malloc(sizeof(t_sprite_texture) * sprite_type_count, dt);
	dt->sprite_texture_count = sprite_type_count;
	load_sprite_images(dt);
	return (EXIT_SUCCESS);
}

int	load_sprites(t_data *dt)
{
	print_separator_default();
	printf(TXT_YELLOW ">>> SPRITES\n" TXT_RESET);
	load_sprite_textures(dt);
	find_all_sprites(dt);
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	return (EXIT_SUCCESS);
}
