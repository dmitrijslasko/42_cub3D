# include "cub3d.h"

static void	swap_sprites(t_sprite *a, t_sprite *b)
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

	//printf("Sorting sprites...");
	i = 0;
	while (i < num_sprites - 1)
	{
		j = 0;
		while (j < num_sprites - i - 1)
		{
			//printf("%f vs %f\n", sprites[j].distance_to_player, sprites[j+1].distance_to_player);
			if (sprites[j].distance_to_player < sprites[j + 1].distance_to_player)
			{
				//printf("Before swap: j=%zu |\tsprite[j]=%p |\tsprite[j+1]=%p\n", j, (void *)&sprites[j], (void *)&sprites[j + 1]);
				swap_sprites(&sprites[j], &sprites[j + 1]);
			}
			j++;
		}
		i++;
	}
}

void	sort_sprites_by_distance(t_data *dt)
{
	size_t	i;

	i = 0;
	while (i < dt->sprite_count)
	{
		float dx = dt->sprites[i].pos.x - dt->player.pos.x;
		float dy = dt->sprites[i].pos.y - dt->player.pos.y;
		dt->sprites[i].distance_to_player = dx * dx + dy * dy;
		i++;
	}
	//printf(">>> Sorting sprites! Sprite count: %zu\n", dt->sprite_count);
	sort_sprites(dt->sprites, dt->sprite_count);
}
