#include "cub3d.h"

/**
 * 	fish-eye correction - angle_cos
 */
float	fix_fish_eye(t_ray *ray, t_player *player)
{
	float	angle_cos;

	angle_cos = ray->vector.x * player->direction_vector.x + \
				ray->vector.y * player->direction_vector.y;
	return (ray->distance_to_wall * angle_cos);
}

int	fix_fish_eye_2(t_ray *ray, t_player *player, float *distance)
{
	float	angle_cos;

	angle_cos = ray->vector.x * player->direction_vector.x + \
				ray->vector.y * player->direction_vector.y;
	*distance *= angle_cos;
	return (EXIT_SUCCESS);
}
