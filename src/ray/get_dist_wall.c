#include "cub3d.h"

void	set_wall_dist_and_type(t_ray *ray, char c, t_coor *map_coor, t_player *player)
{
	t_x_y	step;
	float	dist;

	set_step(&step, &ray->vector);
	if (c == 'x')
		dist = (map_coor->x - player->pos.x + (1 - step.x) / 2) / ray->vector.x;
	else
		dist = (map_coor->y - player->pos.y + (1 - step.y) / 2) / ray->vector.y;

	ray->distance_to_wall = dist;
	// fix_fish_eye(ray, player);
	ray->corrected_distance_to_wall = fix_fish_eye(ray, player);

	set_wall_type(c, ray);
	set_perc_wall(&player->pos, ray);
}
