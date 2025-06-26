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

	(void) ray;
	next_tile = get_cell_type(&dt->map, coord);
	if (side = 'x' && next_tile == '|')
		return (1);
	ray->wall_hit.x = dt->player.pos.x + ray->vector.x * ray->distance_to_wall;
	ray->wall_hit.y = dt->player.pos.y + ray->vector.y * ray->distance_to_wall;
	return (0);
}

int ray_hits_door(t_data *dt, t_coor *map_coor, t_ray *ray)
{
	t_door *door;
	float	step;
	float	door_hit_x;
	float	door_hit_y;

	// find the door in the specified cell

	door = find_door_at(dt, map_coor->x, map_coor->y);
	ray->door = door;
	if (!door)
		return (0);

	float distance_to_door;
	float distance_to_wall = ray->distance_to_wall;

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
	if (distance_to_door > distance_to_wall)
		return (0);

	ray->distance_to_door = distance_to_door;

	if (ray->id == 0 || ray->id == CASTED_RAYS_COUNT - 1 || ray->id == CASTED_RAYS_COUNT / 2)
		printf("Ray [%zu] distance to door: %f\n", ray->id, ray->distance_to_door);

	// Go deeper into the cell
	door_hit_x = ray->wall_hit.x + ray->vector.x * ray->distance_to_door;
	door_hit_y = ray->wall_hit.y + ray->vector.y * ray->distance_to_door;

	// door_hit_x = ray->wall_hit.x;
	// door_hit_y = ray->wall_hit.y;

	ray->door_hit.x = door_hit_x;
	ray->door_hit.y = door_hit_y;

	if ((int)door_hit_x == map_coor->x &&
	(int)door_hit_y == map_coor->y)
	{
		if (ray->id == 0 || ray->id == CASTED_RAYS_COUNT - 1 || ray->id == CASTED_RAYS_COUNT / 2)
			printf("Ray [%zu] hits the door!\n", ray->id);
		return (1);
	}
	return (0);
}

void	calculate_ray_distance(t_data *dt, t_ray *ray, t_x_y *delta_dist, t_x_y*side_dist)
{
	t_coor	map_coor;
	t_x_y	step;
	char	hit_side;
	int		door_hit;
	int		door_cell_hit;

	door_hit = 0;
	hit_side = 0;
	door_cell_hit = 0;

	// This line sets the step based on the vector directions
	set_step(&step, &ray->vector);

	map_coor.x = (size_t)dt->player.pos.x;
	map_coor.y = (size_t)dt->player.pos.y;

	if (ray->id == 0 || ray->id == CASTED_RAYS_COUNT - 1 || ray->id == CASTED_RAYS_COUNT / 2)
		printf("Ray [%zu] first checking cell X Y: %zu %zu\n", ray->id, map_coor.x, map_coor.y);

	while (map_coor.x <  dt->map.map_size_cols && \
			map_coor.y < dt->map.map_size_rows)
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

		// ray distances
		set_ray_distance_to_wall(dt, ray, &map_coor);

		if (ray->id == 0 || ray->id == CASTED_RAYS_COUNT - 1 || ray->id == CASTED_RAYS_COUNT / 2)
			printf("Ray [%zu] distance to cell edge: %f\n", ray->id, ray->distance_to_wall);

		ray->wall_hit.x = dt->player.pos.x + ray->vector.x * ray->distance_to_wall;
		ray->wall_hit.y = dt->player.pos.y + ray->vector.y * ray->distance_to_wall;

		if (ray->id == 0 || ray->id == CASTED_RAYS_COUNT - 1 || ray->id == CASTED_RAYS_COUNT / 2)
			printf(TXT_CYAN "Ray [%zu] checking cell X Y: %zu %zu\n" TXT_RESET, ray->id, map_coor.x, map_coor.y);

		door_cell_hit = check_hit_door_cell(&map_coor, dt, ray, hit_side);

		if (door_cell_hit &&
			(ray->id == 0 || ray->id == CASTED_RAYS_COUNT - 1 || ray->id == CASTED_RAYS_COUNT / 2))

			printf("The ray hits the door cell at X Y: %f %f\n", dt->player.pos.x + ray->vector.x * ray->distance_to_wall, ray->wall_hit.y);

		if (door_cell_hit)
		{
			door_hit = ray_hits_door(dt, &map_coor, ray);
			// door_hit = 1;
			if (door_hit)
				break ;
		}
		if (check_hit_wall(&map_coor, &dt->map, ray, hit_side))
			break ;
	}

	set_cell_type(dt, ray, &map_coor);
	ray->hit_side = hit_side;

   	set_ray_distance_to_wall(dt, ray, &map_coor);
	if (door_hit == 1)
		ray->distance_to_wall += ray->distance_to_door;

	set_wall_type(ray);
	set_perc_wall(&dt->player.pos, ray);

	ray->corrected_distance_to_wall = fix_fish_eye(ray, &dt->player);
	if (ray->id == 0 || ray->id == CASTED_RAYS_COUNT - 1 || ray->id == CASTED_RAYS_COUNT / 2)
		printf("----------------------------\n");

	if (ray->id == CASTED_RAYS_COUNT / 2 - 1)
	{
		printf(TXT_YELLOW "Ray [%zu] vector: (%f, %f)\n" TXT_RESET, ray->id, ray->vector.x, ray->vector.y);
		printf(TXT_YELLOW "Ray [%zu] distance_to_wall: %f\n" TXT_RESET, ray->id, ray->distance_to_wall);
	}


}
