#include "cub3d.h"

void	update_single_ray(t_data *dt, t_ray *ray)
{
	t_x_y	side_dist;
	t_x_y	delta_dist;

	set_delta_dist(&delta_dist, ray->vector);
	set_side_dist(&side_dist, &ray->vector, &dt->player.pos, &delta_dist);

	calculate_ray_distance(dt, ray, &delta_dist, &side_dist);
}
