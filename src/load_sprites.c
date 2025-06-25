#include "cub3d.h"

int	load_sprite_images(t_data *dt)
{
	size_t			i;
	t_sprite_txt	*sprites_txt;

	i = 0;
	sprites_txt = dt->sprites_txt;
	printf("Sprite images to be loaded: %zu\n", dt->sprite_txt_count);
	while (i <  dt->sprite_txt_count)
	{
		if (i == 0)
		{
		sprites_txt[i].sprite_img = mlx_xpm_file_to_image( \
			dt->mlx_ptr, \
			"./sprites/sprite-1.xpm", \
			&sprites_txt[i].width, \
			&sprites_txt[i].height \
		);}

		if (i == 1)
		{ sprites_txt[i].sprite_img = mlx_xpm_file_to_image( \
			dt->mlx_ptr, \
			"./sprites/KODOS.xpm", \
			&sprites_txt[i].width, \
			&sprites_txt[i].height \
		);}

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

void	find_sprites(t_data *dt)
{
	size_t	row;
	size_t	col;
	size_t	count;
	char	c;

	count = 0;
	row = 0;
	while (row < dt->map.map_size_rows && count < dt->sprite_count)
	{
		col = 0;
		while (col < dt->map.map_size_cols && count < dt->sprite_count)
		{
			c = get_cell_type_by_coordinates(&dt->map, row, col);
			if (ft_strchr(SPRITES_TYPES, c))
			{
				dt->sprites[count].type = c;
				dt->sprites[count].pos.x = row + 0.5;
				dt->sprites[count].pos.y = col + 0.5;
				count++;
			}
			col++;
		}
		row++;
	}
}

void	find_all_sprites(t_data *dt)
{
	size_t	sprite_count;

	sprite_count = count_elements_in_the_map(&dt->map, SPRITES_TYPES);
	if (!sprite_count)
		return ;
	dt->sprites = protected_malloc(sprite_count * sizeof(t_sprite), *dt);
	dt->sprite_count = sprite_count;
	find_sprites(dt);
}


int	load_sprites(t_data *dt)
{
	size_t	sprite_type_count;

	printf("Loading sprites...\n");
	print_separator_default();

	sprite_type_count = count_types_elements_in_the_map(&dt->map, SPRITES_TYPES);
	if (sprite_type_count == 0)
		return (EXIT_SUCCESS);
	printf("Sprites found in the map: %zu\n", sprite_type_count);
	dt->sprites_txt = protected_malloc(sizeof(t_sprite_txt) * sprite_type_count, *dt);
	dt->sprite_txt_count = sprite_type_count;
	load_sprite_images(dt);
	find_all_sprites(dt);
	printf("Done!\n");
	return (EXIT_SUCCESS);
}