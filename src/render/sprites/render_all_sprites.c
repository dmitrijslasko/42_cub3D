#include "cub3d.h"

int	render_all_sprites(t_data *dt)
{
	size_t	i;

	i = 0;
	sort_sprites_by_distance(dt);
	set_texture_sprites(dt);
	while (i < dt->sprite_count)
	{
		get_position_and_render_sprite(dt, &dt->sprites[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
