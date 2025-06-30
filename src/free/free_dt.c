#include "cub3d.h"

void	free_dt(t_data *dt)
{
	ft_free(dt->doors);
	ft_free(dt->rays);
	free_array(dt->map.map_data);
	ft_free(dt->sprites);
	ft_free(dt->view);
	free_texture_sprite(dt);
	free_wall_tile_texture(dt);
	free_audio(dt->background_music);
}
