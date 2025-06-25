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
	char	tile;

	(void) ray;
	tile = get_cell_type(&dt->map, coord);
	if (side == 'x')
	{
		if (tile == '|')
		{
			// if (ray->id == CASTED_RAYS_COUNT / 2 - 1)
			// 	printf("Ray [%zu] entered vertical door tile at map [%zu, %zu]\n", ray->id, coord->x, coord->y);
			return (1);
		}
	}
	return (0);
}

int door_is_hit(t_data *dt, t_coor *coor_map, t_ray *ray)
{
	t_door *door;
	float cell_entry_x, cell_entry_y;
	float step;
	float door_hit_x, door_hit_y;

	door = find_door_at(dt, coor_map->x, coor_map->y);
	if (!door)
		return 0;

	cell_entry_x = dt->player.pos.x + ray->vector.x * ray->distance_to_wall;
	cell_entry_y = dt->player.pos.y + ray->vector.y * ray->distance_to_wall;

	if (ray->hit_side == 'x')
	{
		step = (ray->vector.x > 0) ? 0.5f : -0.5f;
		ray->distance_to_door_center = step / ray->vector.x;
	}
	else
	{
		step = (ray->vector.y > 0) ? 0.5f : -0.5f;
		ray->distance_to_door_center = step / ray->vector.y;
	}

	float	angle_cos;

	angle_cos = ray->vector.x * dt->player.direction_vector.x + \
				ray->vector.y * dt->player.direction_vector.y;

	ray->distance_to_door_center *= angle_cos;

	// Go deeper into the cell
	door_hit_x = cell_entry_x + ray->vector.x * ray->distance_to_door_center;
	door_hit_y = cell_entry_y + ray->vector.y * ray->distance_to_door_center;

	// if (ray->id == CASTED_RAYS_COUNT / 2 - 1)
	// 	printf("Ray [%zu] entered door at [%f, %f]\n", ray->id, door_hit_x, door_hit_y);

	if (door_hit_x >= coor_map->x && door_hit_x <= coor_map->x + 1 &&
		door_hit_y >= coor_map->y && door_hit_y <= coor_map->y + 1)
	{
		ray->door = door;
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
		if (check_hit_door_cell(&coor_map, dt, ray, hit_side))
		{
			set_wall_distance_and_type(dt, ray, &coor_map);
			ray->hit_point.x = dt->player.pos.x + ray->vector.x * ray->distance_to_wall;
			ray->hit_point.y = dt->player.pos.y + ray->vector.y * ray->distance_to_wall;

			door_hit = door_is_hit(dt, &coor_map, ray);
			if (door_hit)
				break ;
		}
		if (check_hit_wall(&coor_map, &dt->map, ray, hit_side))
			break ;
	}
	ray->hit_side = hit_side;

	if (door_hit == 0)
   		set_wall_distance_and_type(dt, ray, &coor_map);
	if (door_hit)
	{
		ray->distance_to_wall += ray->distance_to_door_center;
		ray->corrected_distance_to_wall += ray->distance_to_door_center;
		set_perc_wall(&dt->player.pos, ray);
	}
	ray->hit_point.x = dt->player.pos.x + ray->vector.x * ray->distance_to_wall;
	ray->hit_point.y = dt->player.pos.y + ray->vector.y * ray->distance_to_wall;
}
