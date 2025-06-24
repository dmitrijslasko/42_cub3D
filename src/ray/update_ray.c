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
			return (1);
	}
	return (0);
}

void	calc_dist_ray(t_data *dt, t_ray *ray, t_x_y *delta_dist, t_x_y*side_dist)
{
	t_coor	coor_map;
	t_x_y	step;
	char	hit_side;
	int		found_door;

	found_door = 0;
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

		found_door = check_hit_door_cell(&coor_map, dt, ray, hit_side);
		if (found_door)
			break ;
		if (check_hit_wall(&coor_map, &dt->map, ray, hit_side))
			break ;
	}
	ray->hit_side = hit_side;

    set_wall_distance_and_type(dt, ray, &coor_map);

	ray->hit_point.x = dt->player.pos.x + ray->vector.x * ray->distance_to_wall;
	ray->hit_point.y = dt->player.pos.y + ray->vector.y * ray->distance_to_wall;

	if (found_door)
	{
		if (ray->id == CASTED_RAYS_COUNT / 2 - 1)
			printf("Ray [%zu] hits vertical door cell at X Y: %.2f %.2f\n", ray->id, ray->hit_point.x, ray->hit_point.y);
		float dy = ray->hit_point.y;

		dy = dy - (int)dy;
		float dx = (dy * ray->vector.x) / fabs(ray->vector.y);
		if (ray->id == CASTED_RAYS_COUNT / 2 - 1)
			printf("Ray [%zu] hits vertical door at X Y: %.2f %.2f\n---\n", ray->id, dx, dy);
		t_door *door = find_door_at(dt, coor_map.x, coor_map.y);
		if (dx >= 0.5f)
		{
			ray->door = door;
			ray->cell_type = DOOR_VERTICAL;
		}
		else
		{
			ray->cell_type = SOLID_WALL;
		}
	}
}
