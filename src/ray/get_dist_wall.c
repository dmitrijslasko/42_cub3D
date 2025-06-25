#include "cub3d.h"

void 	set_cell_type(t_data *dt, t_ray *ray, t_coor *map_coor)
{
	char cell_type = get_cell_type(&dt->map, map_coor);

	if (cell_type == '1')
		ray->cell_type = SOLID_WALL;
	else if (cell_type == '|')
		ray->cell_type = DOOR_VERTICAL;
	else if (cell_type == '-')
		ray->cell_type = DOOR_HORIZONTAL;
	else if (cell_type == 'v')
		ray->cell_type = THIN_WALL_VERTICAL;
	else if (cell_type == 'h')
		ray->cell_type = THIN_WALL_HORIZONTAL;
	else
		ray->cell_type = EMPTY_CELL;
}

void	set_ray_distance_to_wall(t_data *dt, t_ray *ray, t_coor *map_coor)
{
	t_x_y	step;
	float	distance;

	set_step(&step, &ray->vector);

	distance = 0.0f;

	if (ray->hit_side == 'x')
	{
		distance = (map_coor->x - dt->player.pos.x + (1 - step.x) / 2) / ray->vector.x;
		// if (distance < 0.0f) distance = 0.0f;
	}
	else if (ray->hit_side == 'y')
	{
		distance = (map_coor->y - dt->player.pos.y + (1 - step.y) / 2) / ray->vector.y;

		// if (distance < 0.0f) distance = 0.0f;
	}

	if (ray->id == 0 || ray->id == CASTED_RAYS_COUNT - 1 || ray->id == CASTED_RAYS_COUNT / 2)
	{
		printf("map coor x: %zu\n", map_coor->x);
		printf("map coor y: %zu\n", map_coor->y);
		printf("player coor x: %f\n", dt->player.pos.x);
		printf("ray vector x: %f\n", ray->vector.x);
		printf("Ray [%zu] distance to cell edge: %f\n", ray->id, ray->distance_to_wall);
	}

	ray->distance_to_wall = distance;
	// ray->corrected_distance_to_wall = fix_fish_eye(ray, &dt->player);
}
