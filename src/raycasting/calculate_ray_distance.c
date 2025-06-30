#include "cub3d.h"

static void	step_and_set_side(t_dda_info *info);
static void	update_ray_hit_point(t_data *dt, t_ray *ray);
static int	handle_door_hit(t_data *dt, t_ray *ray, t_coor *map);
static int	check_hit_door_cell(t_coor *map, t_data *dt);
static void	init_raycasting(t_coor *step, t_coor *map_coor,
				t_data *dt, t_ray *ray);
static void	finish_ray_casting(t_data *dt, t_ray *ray,
				t_coor *map_coor, int door_hit);

static void	init_raycasting(t_coor *step, t_coor *map_coor,
			t_data *dt, t_ray *ray)
{
	set_step(step, &ray->vector);
	map_coor->x = (int)dt->player.pos.x;
	map_coor->y = (int)dt->player.pos.y;
}

static int	check_hit_door_cell(t_coor *map, t_data *dt)
{
	return (dt->map.map_data[map->y][map->x] == '|');
}

static int	handle_door_hit(t_data *dt, t_ray *ray, t_coor *map)
{
	int	door_hit;

	door_hit = ray_hits_door(dt, map, ray);
	if (ray->door_hit_coor.y < ray->door->cell_y + ray->door->open_progress)
		return (0);
	return (door_hit);
}

static int	run_dda_loop(t_data *dt, t_ray *ray, t_dda_info *info)
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

static void	step_and_set_side(t_dda_info *info)
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

static void	update_ray_hit_point(t_data *dt, t_ray *ray)
{
	ray->wall_hit.x = dt->player.pos.x
		+ ray->vector.x * ray->distance_to_wall;
	ray->wall_hit.y = dt->player.pos.y
		+ ray->vector.y * ray->distance_to_wall;
}

static void	finish_ray_casting(t_data *dt, t_ray *ray,
			t_coor *map_coor, int door_hit)
{
	set_cell_type(dt, ray, map_coor);
	if (door_hit == 1)
		ray->distance_to_wall += ray->distance_to_door;
	set_wall_type(ray);
	set_perc_wall(&dt->player.pos, ray);
	ray->corrected_distance_to_wall = fix_fish_eye(ray, &dt->player);
}

void	calculate_ray_distance(t_data *dt, t_ray *ray,
			t_x_y *delta_dist, t_x_y *side_dist)
{
	t_coor		map_coor;
	t_coor		step;
	char		hit_side;
	int			door_hit;
	t_dda_info	info;

	door_hit = 0;
	hit_side = 0;
	init_raycasting(&step, &map_coor, dt, ray);
	info.map = &map_coor;
	info.step = &step;
	info.delta = delta_dist;
	info.side = side_dist;
	info.hit_side = &hit_side;
	door_hit = run_dda_loop(dt, ray, &info);
	finish_ray_casting(dt, ray, &map_coor, door_hit);
}
