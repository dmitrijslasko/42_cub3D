#include "cub3d.h"

int ray_hits_door(t_data *dt, t_coor *map_coor, t_ray *ray)
{
	t_door 	*door;
	float	step;
	t_x_y	door_hit_coor;
	float 	distance_to_door;

	door = find_door_at(dt, map_coor->x, map_coor->y);
	if (!door)
		return (0);
	ray->door = door;

	distance_to_door = 0.0f;

	if (ray->hit_side == 'x')
	{
		if (ray->vector.x > 0)
			step = door->pos_x;
		else
			step = -door->pos_x;
		distance_to_door = step / ray->vector.x;
	}
	else
	{
		if (ray->vector.y > 0)
			step = door->pos_y;
		else
			step = -door->pos_y;
		distance_to_door = step / ray->vector.y;
	}

	door_hit_coor.x = ray->wall_hit.x + ray->vector.x * distance_to_door;
	door_hit_coor.y = ray->wall_hit.y + ray->vector.y * distance_to_door;

	if ((int)door_hit_coor.x == (int)map_coor->x && (int)door_hit_coor.y == (int) map_coor->y)
	{
		ray->distance_to_door = distance_to_door;
		ray->door_hit_coor.x = door_hit_coor.x;
		ray->door_hit_coor.y = door_hit_coor.y;
		return (1);
	}
	return (0);
}
