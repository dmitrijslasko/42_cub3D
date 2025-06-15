#include "cub3d.h"

size_t	count_elements_in_the_map(t_map map, char element)
{
	size_t	row;
	size_t	col;
	size_t	element_count;

	element_count = 0;
	row = 0;
	while (row < map.map_size_rows)
	{
		col = 0;
		while (col < map.map_size_cols)
		{
			if (map.map_data[row][col] == element)
				element_count++;
			col++;
		}
		row++;
	}
	return (element_count);
}

int	load_sprite_images(t_data *dt)
{
	size_t	i;
	t_sprite *sprites;
	size_t	sprite_count;

	sprite_count = count_elements_in_the_map(*dt->map, 'S');
	i = 0;
	sprites = dt->sprites;

	while (i < sprite_count)
	{
		sprites[i].sprite_img = mlx_xpm_file_to_image(
			dt->mlx_ptr,
			"./sprites/sprite-1.xpm",
			&sprites[i].width,
			&sprites[i].height
		);

		sprites[i].sprite_data = (int *)mlx_get_data_addr(
			sprites[i].sprite_img,
			&sprites[i].bpp,
			&sprites[i].size_line,
			&sprites[i].endian
		);
		i++;
	}

	return (EXIT_SUCCESS);
}


int	load_sprites(t_data *dt)
{
	size_t	sprite_count;

	printf("Loading sprites...\n");
	print_separator(1, DEF_SEPARATOR_CHAR);

	sprite_count = count_elements_in_the_map(*dt->map, 'S');
	printf("Sprites found in the map: %zu\n", sprite_count);
	dt->sprites = protected_malloc(sizeof(t_sprite) * sprite_count, *dt);
	load_sprite_images(dt);
	dt->sprites->x = 1.5f;
	dt->sprites->y = 1.5f;

	printf("Done!\n");
	return (EXIT_SUCCESS);
}
