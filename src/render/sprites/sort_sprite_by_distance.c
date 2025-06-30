# include "cub3d.h"

void	sort_sprites_by_distance(t_data *dt)
{
	float	dx;
	float	dy;
	size_t	i;

	i = 0;
	while (i < dt->sprite_count)
	{
		dx = dt->sprites[i].pos.x - dt->player.pos.x;
		dy = dt->sprites[i].pos.y - dt->player.pos.y;
		dt->sprites[i].distance_to_player = dx * dx + dy * dy;
		i++;
	}
	sort_sprites(dt->sprites, dt->sprite_count);
}
