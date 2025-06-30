#include "cub3d.h"

bool	check_hit_door_cell(t_coor *map_coor, t_data *dt)
{
	char	tile;

	tile = get_cell_type(&dt->map, map_coor);
	if (tile == '|')
		return (1);
	return (0);
}

void	calculate_ray_distance(t_data *dt, t_ray *ray, t_x_y *delta_dist, t_x_y*side_dist)
{
	t_coor	map_coor;
	t_coor	step;
	char	hit_side;
	int		door_hit;

	door_hit = 0;
	hit_side = 0;
	set_step(&step, &ray->vector);

	map_coor.x = (int)dt->player.pos.x;
	map_coor.y = (int)dt->player.pos.y;
	while (map_coor.x < dt->map.map_size_cols && map_coor.y < dt->map.map_size_rows)
	{
		if (side_dist->x < side_dist->y)
		{
			side_dist->x += delta_dist->x;
			map_coor.x += step.x;
			hit_side = 'x';
		}
		else
		{
			side_dist->y += delta_dist->y;
			map_coor.y += step.y;
			hit_side = 'y';
		}

		ray->hit_side = hit_side;

		// Ray distances
		update_ray_dist_to_cell_edge(dt, ray, &map_coor);

		ray->wall_hit.x = dt->player.pos.x + ray->vector.x * ray->distance_to_wall;
		ray->wall_hit.y = dt->player.pos.y + ray->vector.y * ray->distance_to_wall;

		// CHECK IF THE RAY HITS A DOOR CELL
		if (check_hit_door_cell(&map_coor, dt))
		{
			door_hit = ray_hits_door(dt, &map_coor, ray);
			if (ray->door_hit_coor.y < ray->door->cell_y + ray->door->open_progress)
				door_hit = 0;
			if (door_hit)
				break ;
		}
		if (check_hit_wall(&map_coor, &dt->map, ray, hit_side))
			break ;
	}
	set_cell_type(dt, ray, &map_coor);
	if (door_hit == 1)
		ray->distance_to_wall += ray->distance_to_door;
	set_wall_type(ray);
	set_perc_wall(&dt->player.pos, ray);
	ray->corrected_distance_to_wall = fix_fish_eye(ray, &dt->player);
}
