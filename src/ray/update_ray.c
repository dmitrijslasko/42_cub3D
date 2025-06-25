#include "cub3d.h"

t_door *find_door_at(t_data *dt, int x, int y)
{
	size_t	i;

	i = 0;

    while (i < dt->door_count)
    {
        if (dt->doors[i].cell_x == x && dt->doors[i].cell_y == y)
            return &dt->doors[i];
		i++;
    }
	//printf("Door found!");
    return (NULL);
}

void set_door_dist_and_type(t_data *dt, t_ray *ray, char side, t_coor *map_pos)
{
    t_x_y step;

    // Recalculate step (same logic as in your DDA)
    step.x = (ray->vector.x < 0) ? -1 : 1;
    step.y = (ray->vector.y < 0) ? -1 : 1;

    if (side == 'x')
    {
        ray->distance_to_wall = (map_pos->x - dt->player.pos.x +
                               (1 - step.x) / 2) / ray->vector.x;
    }
    else
    {
        ray->distance_to_wall = (map_pos->y - dt->player.pos.y +
                               (1 - step.y) / 2) / ray->vector.y;
    }
    ray->hit_side = side;
    ray->hit_content = dt->map.map_data[map_pos->y][map_pos->x];
}
bool	check_hit_door_cell(t_coor *coord, t_data *dt, t_ray *ray, char side)
{
	char	next_tile;
	//char	current_tile;

	(void) ray;
	next_tile = get_cell_type(&dt->map, coord);
	if (side == 'x')
	{
		if (next_tile == '|')
			return (1);
	}
	return (0);
}

int ray_hits_door(t_data *dt, t_coor *coor_map, t_ray *ray)
{
	t_door *door;
	float step;
	float door_hit_x, door_hit_y;

	door = find_door_at(dt, coor_map->x, coor_map->y);
	if (!door)
		return 0;

	float distance_to_door;
	float distance_to_wall = ray->distance_to_wall;

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

	float wall_hit_x = dt->player.pos.x + ray->vector.x * distance_to_wall;
	float wall_hit_y = dt->player.pos.y + ray->vector.y * distance_to_wall;

	// Go deeper into the cell
	door_hit_x = wall_hit_x + ray->vector.x * ray->distance_to_door;
	door_hit_y = wall_hit_y + ray->vector.y * ray->distance_to_door;

	if (door_hit_x >= coor_map->x && door_hit_x <= coor_map->x + 1 &&
		door_hit_y >= coor_map->y && door_hit_y <= coor_map->y + 1)
	{
		ray->door = door;
		ray->distance_to_door = distance_to_door;
		ray->distance_to_wall += distance_to_door;
		ray->cell_type = DOOR_VERTICAL;
		return (1);
	}
	return (0);
}

void	calculate_ray_distance(t_data *dt, t_ray *ray, t_x_y *delta_dist, t_x_y*side_dist)
{
	t_coor	coor_map;
	t_x_y	step;
	char	hit_side;
	int		door_hit;

	door_hit = 0;
	hit_side = 0;

	// This line sets the step based on the vector directions
	set_step(&step, &ray->vector);

	coor_map.x = (size_t)dt->player.pos.x;
	coor_map.y = (size_t)dt->player.pos.y;

	while (coor_map.x < dt->map.map_size_cols && \
			coor_map.y < dt->map.map_size_rows)
	{
		if (side_dist->x < side_dist->y)
		{
			side_dist->x += delta_dist->x;
			coor_map.x += step.x;
			hit_side = 'x';
		}
		else
		{
			side_dist->y += delta_dist->y;
			coor_map.y += step.y;
			hit_side = 'y';
		}

		set_wall_distance_and_type(dt, ray, &coor_map);
		ray->wall_hit.x = dt->player.pos.x + ray->vector.x * ray->distance_to_wall;
		ray->wall_hit.y = dt->player.pos.y + ray->vector.y * ray->distance_to_wall;

		if (check_hit_door_cell(&coor_map, dt, ray, hit_side))
		{
			door_hit = ray_hits_door(dt, &coor_map, ray);
			if (ray->id == CASTED_RAYS_COUNT / 2 - 1)
				printf("Ray hitting door: %d!\n", door_hit);

			if (door_hit)
			{


				break ;
			}
		}
		if (check_hit_wall(&coor_map, &dt->map, ray, hit_side))
			break ;
	}

	set_cell_type(dt, ray, &coor_map);


	ray->hit_side = hit_side;

	if (door_hit == 0)
   		set_wall_distance_and_type(dt, ray, &coor_map);
	set_wall_type(ray);
	set_perc_wall(&dt->player.pos, ray);
	ray->corrected_distance_to_wall = fix_fish_eye(ray, &dt->player);


}
