# include "cub3d.h"

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
				dt->sprites[count].id = count;
				dt->sprites[count].type = c;
				dt->sprites[count].pos.x = col + 0.5;
				dt->sprites[count].pos.y = row + 0.5;
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
	dt->sprites = protected_malloc(sprite_count * sizeof(t_sprite), dt);
	dt->sprite_count = sprite_count;
	find_sprites(dt);
}
