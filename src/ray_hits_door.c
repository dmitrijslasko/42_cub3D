#include "cub3d.h"

int ray_hits_door(t_data *dt, t_coor *map_coor, t_ray *ray)
{
	t_door *door;
	float	step;
	float	door_hit_x;
	float	door_hit_y;

	float distance_to_door;
	float distance_to_wall;

	door = find_door_at(dt, map_coor->x, map_coor->y);
	if (!door)
		return (0);
	ray->door = door;

	distance_to_door = 0;

	if (ray->hit_side == 'x')
	{
		step = (ray->vector.x > 0) ? door->pos_x : -door->pos_x;
		distance_to_door = step / ray->vector.x;
	}
	else
	{
		step = (ray->vector.y > 0) ? door->pos_y : -door->pos_y;
		distance_to_door = step / ray->vector.y;
	}

	ray->distance_to_door = distance_to_door;

	door_hit_x = ray->wall_hit.x + ray->vector.x * ray->distance_to_door;
	door_hit_y = ray->wall_hit.y + ray->vector.y * ray->distance_to_door;

	ray->door_hit.x = door_hit_x;
	ray->door_hit.y = door_hit_y;

	if ((int)door_hit_x == map_coor->x && (int)door_hit_y == map_coor->y)
		return (1);
	return (0);
}
