
#include "cub3d.h"

t_type_wall	get_type_wall(char c, t_x_y direction)
{
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
	printf("ray distance is %f \n", ray.dist);
	printf("Wall type ");
	if (ray.type_wall == NORTH)
		printf("NORTH\n");
	if (ray.type_wall == WEST)
		printf("WEST\n");
	if (ray.type_wall == EAST)
		printf("EAST\n");
	if (ray.type_wall == SOUTH)
		printf("SOUTH\n");
	printf("ray has %f percentage \n", ray.perc_img);
}
