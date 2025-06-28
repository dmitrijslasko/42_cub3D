//#include "cub3d.h"

//int	load_sprite_images(t_data *dt)
//{
//	size_t			i;
//	t_sprite_texture	*sprite_texture;

//	i = 0;
//	sprite_texture = dt->sprite_textures;
//	printf("Sprite images to be loaded: %zu\n", dt->sprite_type_count);
//	while (i <  dt->sprite_type_count)
//	{
//		if (i == 0)
//		{
//		sprite_texture[i].sprite_img = mlx_xpm_file_to_image( \
//			dt->mlx_ptr, \
//			"./sprites/sprite-1.xpm", \
//			&sprite_texture[i].width, \
//			&sprite_texture[i].height \
//		);}

//		if (i == 1)
//		{ sprite_texture[i].sprite_img = mlx_xpm_file_to_image( \
//			dt->mlx_ptr, \
//			"./sprites/KODOS.xpm", \
//			&sprite_texture[i].width, \
//			&sprite_texture[i].height \
//		);}

//		sprite_texture[i].sprite_data = (int *)mlx_get_data_addr( \
//			sprite_texture[i].sprite_img, \
//			&sprite_texture[i].bpp, \
//			&sprite_texture[i].size_line, \
//			&sprite_texture[i].endian \
//		);
//		printf("Sprite image loaded!\n");
//		i++;
//	}

//	return (EXIT_SUCCESS);
//}

//void	find_sprites(t_data *dt)
//{
//	size_t	row;
//	size_t	col;
//	size_t	count;
//	char	c;

//	count = 0;
//	row = 0;
//	while (row < dt->map.map_size_rows && count < dt->sprite_count)
//	{
//		col = 0;
//		while (col < dt->map.map_size_cols && count < dt->sprite_count)
//		{
//			c = get_cell_type_by_coordinates(&dt->map, row, col);
//			if (ft_strchr(SPRITE_TYPES, c))
//			{
//				dt->sprites[count].type = c;
//				dt->sprites[count].pos.x = row + 0.5;
//				dt->sprites[count].pos.y = col + 0.5;
//				count++;
//			}
//			col++;
//		}
//		row++;
//	}
//}

//void	find_all_sprites(t_data *dt)
//{
//	size_t	sprite_count;

//	sprite_count = count_elements_in_the_map(&dt->map, SPRITE_TYPES);
//	if (!sprite_count)
//		return ;
//	dt->sprites = protected_malloc(sprite_count * sizeof(t_sprite), dt);
//	dt->sprite_count = sprite_count;
//	find_sprites(dt);
//}


//int	load_sprites(t_data *dt)
//{
//	size_t	sprite_type_count;

//	print_separator_default();
//	printf(TXT_YELLOW ">>> LOADING SPRITES\n" TXT_RESET);
//	sprite_type_count = count_types_elements_in_the_map(&dt->map, SPRITE_TYPES);
//	if (sprite_type_count == 0)
//		return (EXIT_SUCCESS);
//	printf("Sprites found in the map: %zu\n", sprite_type_count);
//	dt->sprite_textures = protected_malloc(sizeof(t_sprite_texture) * sprite_type_count, dt);
//	dt->sprite_type_count = sprite_type_count;
//	load_sprite_images(dt);
//	find_all_sprites(dt);
//	printf(TXT_GREEN "Done!\n" TXT_RESET);
//	return (EXIT_SUCCESS);
//}
