#include "cub3d.h"

void	update_ray(t_data dt, t_ray *ray, t_x_y delta_dist, t_x_y	step, t_x_y	side_dist)
{
	t_coor	coor_map;
	char	c;

	coor_map = get_values_coor(dt.player->pos.x, dt.player->pos.y);
	while (coor_map.x >= 0 && coor_map.x < dt.map->map_size_rows && \
			coor_map.y >= 0 && coor_map.y < dt.map->map_size_cols)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			coor_map.x += step.x;
			c = 'x';
		}
		else
		{
			side_dist.y += delta_dist.y;
			coor_map.y += step.y;
			c = 'y';
		}
		if (check_hit_wall(coor_map, *dt.map, ray))
			break ;
	}
	ray->distance_to_wall = get_dist_wall(c, ray->vector, coor_map, dt.player->pos, step);
	ray->percentage_of_image = get_perc_wall(dt.player->pos, ray->vector, ray->distance_to_wall, ray->wall_type);
	ray->wall_type = get_type_wall(c, ray->vector);
}
