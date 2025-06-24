#include "cub3d.h"

void	set_wall_distance_and_type(t_data *dt, t_ray *ray, t_coor *map_coor)
{
	t_x_y	step;
	float	distance;

	char cell_type = get_cell_type(&dt->map, map_coor);

	if (cell_type == '1')
		ray->cell_type = SOLID_WALL;
	else if (cell_type == 'v')
		ray->cell_type = THIN_WALL_VERTICAL;
	else if (cell_type == 'h')
		ray->cell_type = THIN_WALL_HORIZONTAL;
	else if (cell_type == '|')
		ray->cell_type = DOOR_VERTICAL;
	else if (cell_type == '_')
		ray->cell_type = DOOR_HORIZONTAL;
	else
		ray->cell_type = EMPTY_CELL;

	set_step(&step, &ray->vector);

	distance = 0.0f;
	if (ray->hit_side == 'x')
		distance = (map_coor->x - dt->player.pos.x + (1 - step.x) / 2) / ray->vector.x;
	else if (ray->hit_side == 'y')
		distance = (map_coor->y - dt->player.pos.y + (1 - step.y) / 2) / ray->vector.y;

	ray->distance_to_wall = distance;
	ray->corrected_distance_to_wall = fix_fish_eye(ray, &dt->player);

	set_wall_type(ray);
	set_perc_wall(&dt->player.pos, ray);
}
