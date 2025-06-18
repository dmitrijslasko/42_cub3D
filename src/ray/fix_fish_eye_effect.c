#include "cub3d.h"

/**
 * 	fish-eye correction - angle_cos
 */
void	fix_fish_eye(t_x_y direction, t_player player, float *dist)
{
    float   angle_cos;

	angle_cos = direction.x * player.direction_vector.x + \
				direction.y * player.direction_vector.y;
	*dist *= angle_cos;
}
