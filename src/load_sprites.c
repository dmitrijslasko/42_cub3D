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

void	find_sprites(t_data *dt, int index, char sprite_type, size_t n)
{
	size_t	row;
	size_t	col;
	size_t	count;

	count = 0;
	row = 0;
	dt->sprites[index].type = sprite_type;
	while (row < dt->map.map_size_rows)
	{
		col = 0;
		while (col < dt->map.map_size_cols && count < n)
		{
			if (get_cell_type_by_coordinates(&dt->map, row, col) == sprite_type)
			{
				dt->sprites[index].x = row + 0.5;
				dt->sprites[index].y = col + 0.5;
				count++;
			}
			col++;
		}
		row++;
	}
}

void	find_all_sprites(t_data *dt)
{
	size_t	i;
	size_t	count;
	size_t	sprite_type_count;
	char	*types;

	types = SPRITES_TYPES;
	count = 0;
	i = 0;
	while(types[i])
	{
		sprite_type_count = count_elements_in_the_map(&dt->map, ft_substr(types, i, 1));
		if (!sprite_type_count)
		{
			i++;
			continue;
		}
		find_sprites(dt, count++, types[i++], sprite_type_count);
	}
}


int	load_sprites(t_data *dt)
{
	size_t	sprite_type_count;

	printf("Loading sprites...\n");
	print_separator_default();

	sprite_type_count = count_elements_in_the_map(&dt->map, SPRITES_TYPES);
	if (sprite_type_count == 0)
		return (EXIT_SUCCESS);
	printf("Sprites found in the map: %zu\n", sprite_type_count);
	dt->sprites = protected_malloc(sizeof(t_sprite) * sprite_type_count, *dt);
	load_sprite_images(dt);
	find_all_sprites(dt);
	printf("Done!\n");
	return (EXIT_SUCCESS);
}
