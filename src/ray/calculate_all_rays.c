#include "cub3d.h"

int	calculate_all_rays(t_data *dt)
{
	size_t	i;
	t_x_y	vector;
	float	angle;

	angle = -FIELD_OF_VIEW_DEG / 2;
	i = 0;
	while (i < CASTED_RAYS_COUNT)
	{
		//dt->rays[i].wall_type = DEFAULT;
		vector = rotate_vector(*dt, dt->player.direction_vector, angle);
		dt->rays[i].vector = vector;
		update_single_ray(dt, &dt->rays[i]);
		angle += FIELD_OF_VIEW_DEG / (CASTED_RAYS_COUNT - 1);
		i++;
	}
	return (EXIT_SUCCESS);
}
