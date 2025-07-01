#include "cub3d.h"

void	update_ray_hit_point(t_data *dt, t_ray *ray)
{
	ray->wall_hit.x = dt->player.pos.x
		+ ray->vector.x * ray->distance_to_wall;
	ray->wall_hit.y = dt->player.pos.y
		+ ray->vector.y * ray->distance_to_wall;
}
