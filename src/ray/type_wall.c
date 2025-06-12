
#include "cub3d.h"

t_type_wall	get_type_wall(t_data dt, char c, t_x_y direction)
{
	printf("X Y: %f %f\n", dt.player->pos.x, dt.player->pos.y);
	if (c == 'y' && direction.y < 0)
		return (SOUTH);
	if (c == 'y')
		return (NORTH);
	if (c == 'x' && direction.x < 0)
		return (EAST);
	return (WEST);
}

void	print_ray(t_ray ray)
{
	printf("ray distance is %f \n", ray.distance_to_wall);
	printf("Wall type ");
	if (ray.wall_type == NORTH)
		printf("NORTH\n");
	if (ray.wall_type == WEST)
		printf("WEST\n");
	if (ray.wall_type == EAST)
		printf("EAST\n");
	if (ray.wall_type == SOUTH)
		printf("SOUTH\n");
	printf("ray has %f percentage \n", ray.percentage_of_image);
}
