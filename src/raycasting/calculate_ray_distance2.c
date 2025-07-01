#include "cub3d.h"

void	update_ray_hit_point(t_data *dt, t_ray *ray)
{
	ray->wall_hit.x = dt->player.pos.x
		+ ray->vector.x * ray->distance_to_wall;
	ray->wall_hit.y = dt->player.pos.y
		+ ray->vector.y * ray->distance_to_wall;
}

void	finish_ray_casting(t_data *dt, t_ray *ray,
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
