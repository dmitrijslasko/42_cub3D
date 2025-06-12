#include "cub3d.h"

float	get_dist_wall(char c, t_x_y direction, t_coor map_coor, t_x_y player_pos, t_x_y step)
{
	if (c == 'x')
		return ((map_coor.x - player_pos.x + (1 - step.x) / 2) / direction.x) ;
	return ((map_coor.y - player_pos.y + (1 - step.y) / 2) / direction.y);
}

char	initialize_wall_hit(t_x_y side_dist)
{
	if (side_dist.x < side_dist.y)
		return ('x');
	return ('y');
}

void	update_ray(t_data dt, t_ray *ray, t_x_y direction, t_x_y delta_dist, t_x_y	step, t_x_y	side_dist)
{
	//t_ray	*ray;
	t_coor	coor_map;
	char	c;
	int		i;

	i = 0;

	coor_map = get_values_coor(dt.player->pos.x, dt.player->pos.y);

	while (i < 2 * max_float(dt.map->map_size_cols, dt.map->map_size_rows))
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
    	if (check_hit_wall(coor_map, *dt.map))
			break;
	}
	ray->distance_to_wall = get_dist_wall(c, direction, coor_map, dt.player->pos, step);

	// fish-eye correction
	float angle_cos = direction.x * dt.player->direction_vector.x + direction.y * dt.player->direction_vector.y;
	ray->distance_to_wall *= angle_cos;

	ray->wall_type = get_type_wall(dt, c, direction);
	ray->percentage_of_image = get_perc_wall(dt.player->pos, direction, ray->distance_to_wall, ray->wall_type);
}

void	update_single_ray(t_data *dt, t_ray *ray, t_x_y direction)
{
	t_x_y	step;
	t_x_y	side_dist;
	t_x_y	delta_dist;

	// Delta distance
	set_delta_dist(&delta_dist, direction);
	//printf("delta_x = %f and delta_y = %f\n", delta_dist.x, delta_dist.y);

	// Step
	set_step(&step, direction);
	//printf("step_x = %f and step_y = %f\n", step.x, step.y);

	// Step distance
	set_side_dist(&side_dist, direction, dt->player->pos, delta_dist);
	//printf("side_dist_x = %f and side_dist_y = %f\n", side_dist.x, side_dist.y);

	// Create ray & print out its information
	update_ray(*dt, ray, direction, delta_dist, step, side_dist);

	ray->vector = direction;
	//print_single_ray_info(*ray);
}

//t_ray	*calculate_ray(t_data dt, t_x_y direction, )

//{
//	t_x_y	step;
//	t_x_y	side_dist;
//	t_x_y	delta_dist;

//	// Delta distance
//	set_delta_dist(&delta_dist, direction);
//	//printf("delta_x = %f and delta_y = %f\n", delta_dist.x, delta_dist.y);

//	// Step
//	set_step(&step, direction);
//	//printf("step_x = %f and step_y = %f\n", step.x, step.y);

//	// Step distance
//	set_side_dist(&side_dist, direction, dt.player->pos, delta_dist);
//	//printf("side_dist_x = %f and side_dist_y = %f\n", side_dist.x, side_dist.y);

//	// Create ray & print out its information
//	update_ray(*dt, &ray, direction, delta_dist, step, side_dist);
//	ray->vector = direction;
//	//print_single_ray_info(*ray);
//}

int calculate_all_rays(t_data *dt)
{
	size_t	i;
	t_x_y 	vector;
	float	angle;

	angle = -FIELD_OF_VIEW_DEG / 2;
	i = 0;
	while (i < CASTED_RAYS_COUNT)
	{
		vector = rotate_vector(*dt, dt->player->direction_vector, angle);
		update_single_ray(dt, &dt->rays[i], vector);
		angle += FIELD_OF_VIEW_DEG / (CASTED_RAYS_COUNT);
		i++;
	}
	return (EXIT_SUCCESS);
}
