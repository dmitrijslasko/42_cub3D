#include "cub3d.h"

void	calc_dist_ray(t_data *dt, t_ray *ray, t_x_y *delta_dist, t_x_y*side_dist)
{
	t_x_y	player_pos;
	t_coor	coor_map;
	t_x_y	step;
	char	c;

	set_step(&step, &ray->vector);

	player_pos.x = dt->player.pos.x;
	player_pos.y = dt->player.pos.y;

	coor_map.x = (size_t)dt->player.pos.x;
	coor_map.y = (size_t)dt->player.pos.y;

	while (coor_map.x < dt->map.map_size_cols && \
			coor_map.y < dt->map.map_size_rows)
	{
		if (side_dist->x < side_dist->y)
		{
			side_dist->x += delta_dist->x;
			coor_map.x += step.x;
			c = 'x';
		}
		else
		{
			side_dist->y += delta_dist->y;
			coor_map.y += step.y;
			c = 'y';
		}
		if (check_hit_wall(&coor_map, &dt->map, ray, c))
			break ;
	}
	set_wall_dist_and_type(dt, ray, c, &coor_map);

	ray->hit_point.x = player_pos.x + ray->vector.x * ray->distance_to_wall;
	ray->hit_point.y = player_pos.y + ray->vector.y * ray->distance_to_wall;

}
