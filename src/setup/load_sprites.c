/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:10:31 by dmlasko           #+#    #+#             */
/*   Updated: 2025/06/30 20:10:31 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_sprite_file
{
	const char	minimap_repr;
	char		*filepath;
	char		*filepath2;
}				t_sprite_file;

static const t_sprite_file	g_sprites[] = {
{'s', "./sprites/heart.xpm", "./sprites/heart.xpm"},
{'q', "./sprites/test.xpm", "./sprites/test.xpm"},
{'p', "./sprites/container.xpm", "./sprites/container.xpm"},
{'h', "./sprites/sammy1.xpm", "./sprites/sammy2.xpm"},
{'a', "./sprites/tommy1.xpm", "./sprites/tommy2.xpm"},
};

static int	set_sprite_img(t_data *dt, t_sprite_texture *texture,
	size_t i, size_t frame)
{
	texture[i].sprite_img[frame] = mlx_xpm_file_to_image(\
		dt->mlx_ptr, \
		g_sprites[i].filepath, \
		&texture[i].width, \
		&texture[i].height);
	return (EXIT_SUCCESS);
}

int	load_sprite_images(t_data *dt)
{
	size_t				i;
	t_sprite_texture	*sprite_textures;

	sprite_textures = dt->sprite_textures;
	printf("Sprite types to be loaded: %zu\n", dt->sprite_texture_count);
	i = 0;
	while (i < dt->sprite_texture_count)
	{
		sprite_textures[i].type = g_sprites[i].minimap_repr;
		set_sprite_img(dt, sprite_textures, i, 0);
		sprite_textures[i].sprite_data[0] = (int *)mlx_get_data_addr(\
						sprite_textures[i].sprite_img[0], \
						&sprite_textures[i].bpp, \
						&sprite_textures[i].size_line, \
						&sprite_textures[i].endian);
		set_sprite_img(dt, sprite_textures, i, 1);
		sprite_textures[i].sprite_data[1] = (int *)mlx_get_data_addr(\
						sprite_textures[i].sprite_img[1], \
						&sprite_textures[i].bpp, \
						&sprite_textures[i].size_line, \
						&sprite_textures[i].endian);
		printf("Sprite image loaded!\n");
		i++;
	}
	return (EXIT_SUCCESS);
}

int	load_sprite_textures(t_data *dt)
{
	size_t	sprite_element_count;
	size_t	sprite_type_count;

	sprite_element_count = count_elements_in_the_map(&dt->map, SPRITE_TYPES);
	sprite_type_count = count_types_elements_in_the_map(&dt->map, SPRITE_TYPES);
	if (sprite_type_count == 0)
		return (EXIT_SUCCESS);
	printf("Sprite elements found in the map: %zu\n", sprite_element_count);
	printf("Sprite types found in the map: %zu\n", sprite_type_count);
	dt->sprite_textures = protected_malloc(sizeof(t_sprite_texture) * \
		sprite_type_count, dt);
	dt->sprite_texture_count = sprite_type_count;
	load_sprite_images(dt);
	return (EXIT_SUCCESS);
}

int	load_sprites(t_data *dt)
{
	print_separator_default();
	printf(TXT_YELLOW ">>> LOADING SPRITES\n" TXT_RESET);
	load_sprite_textures(dt);
	find_all_sprites(dt);
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	return (EXIT_SUCCESS);
}
