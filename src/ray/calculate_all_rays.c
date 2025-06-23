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
		vector = rotate_vector(&dt->player.direction_vector, angle);
		dt->rays[i].id = i;
		dt->rays[i].vector = vector;
		update_single_ray(dt, &dt->rays[i]);
		angle += FIELD_OF_VIEW_DEG / (CASTED_RAYS_COUNT - 1);
		i++;
	}
	return (EXIT_SUCCESS);
}

// int	calculate_all_rays(t_data *dt)
// {
// 	t_x_y	vector;
// 	float	angle;

// 	angle = FIELD_OF_VIEW_DEG / 2;
// 	vector = dt->player.direction_vector;
// 	dt->rays[0].vector = vector;
// 	update_single_ray(dt, &dt->rays[0]);
// 	return (EXIT_SUCCESS);
// }
