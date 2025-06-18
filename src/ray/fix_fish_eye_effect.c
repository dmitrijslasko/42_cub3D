#include "cub3d.h"

/**
 * 	fish-eye correction - angle_cos
 */
void	fix_fish_eye(t_x_y ray_vector, t_player player, float *dist)
{
	float	angle_cos;

	angle_cos = ray_vector.x * player.direction_vector.x + \
				ray_vector.y * player.direction_vector.y;
	*dist *= angle_cos;
}
