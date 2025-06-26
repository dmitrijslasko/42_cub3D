# include "cub3d.h"

void	swap_sprites(t_sprite *a, t_sprite *b)
{
	t_sprite	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_sprites(t_sprite *sprites, size_t num_sprites)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < num_sprites - 1)
	{
		j = 0;
		while (j < num_sprites - i - 1)
		{
			if (sprites[j].dist_to_player < sprites[j + 1].dist_to_player)
				swap_sprites(&sprites[j], &sprites[j + 1]);
			j++;
		}
		i++;
	}
}

void	sort_sprites_distance(t_data *dt)
{
	size_t	i;
	float	distance;

	i = 0;
	while (i < dt->sprite_count)
	{
		distance = (dt->sprites[i].pos.x - dt->player.pos.x) *
				(dt->sprites[i].pos.x - dt->player.pos.x) +
				(dt->sprites[i].pos.y - dt->player.pos.y) *
				(dt->sprites[i].pos.y - dt->player.pos.y);
		dt->sprites[i++].dist_to_player = distance;
	}
	sort_sprites(dt->sprites, dt->sprite_count);
}
