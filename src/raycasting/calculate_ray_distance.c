#include "cub3d.h"

void	init_raycasting(t_coor *step, t_coor *map_coor,
			t_data *dt, t_ray *ray)
{
	set_step(step, &ray->vector);
	map_coor->x = (int)dt->player.pos.x;
	map_coor->y = (int)dt->player.pos.y;
}

int	check_hit_door_cell(t_coor *map, t_data *dt)
{
	return (dt->map.map_data[map->y][map->x] == '|');
}

int	handle_door_hit(t_data *dt, t_ray *ray, t_coor *map)
{
	int	door_hit;

	door_hit = ray_hits_door(dt, map, ray);
	if (ray->door_hit_coor.y < ray->door->cell_y + ray->door->open_progress)
		return (0);
	return (door_hit);
}

int	run_dda_loop(t_data *dt, t_ray *ray, t_dda_info *info)
{
	int	door_hit;

	door_hit = 0;
	while (info->map->x < dt->map.map_size_cols
		&& info->map->y < dt->map.map_size_rows)
	{
		step_and_set_side(info);
		ray->hit_side = *(info->hit_side);
		update_ray_distance_to_cell_edge(dt, ray, info->map);
		update_ray_hit_point(dt, ray);
		if (check_hit_door_cell(info->map, dt))
		{
			door_hit = handle_door_hit(dt, ray, info->map);
			if (door_hit)
				break ;
		}
		if (check_hit_wall(info->map, &dt->map, ray, *(info->hit_side)))
			break ;
	}
	return (door_hit);
}

void	step_and_set_side(t_dda_info *info)
{
	if (info->side->x < info->side->y)
	{
		info->side->x += info->delta->x;
		info->map->x += info->step->x;
		*(info->hit_side) = 'x';
	}
	else
	{
		info->side->y += info->delta->y;
		info->map->y += info->step->y;
		*(info->hit_side) = 'y';
	}
}


