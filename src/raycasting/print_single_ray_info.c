#include "cub3d.h"

void	print_single_ray_info(t_ray ray)
{
	printf(TXT_YELLOW "Ray distance:\t%f \n" TXT_RESET, ray.distance_to_wall);
	printf("Wall type: \t");
	if (ray.wall_type == NORTH)
		printf("NORTH\n");
	if (ray.wall_type == WEST)
		printf("WEST\n");
	if (ray.wall_type == EAST)
		printf("EAST\n");
	if (ray.wall_type == SOUTH)
		printf("SOUTH\n");
	printf("Ray hits wall at x == %f\n", ray.percentage_of_image);
}
