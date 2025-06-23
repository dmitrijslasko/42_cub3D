
#include "cub3d.h"

void	set_wall_type(char c, t_ray *ray)
{
	int wall_type;

	if (c == 'y' && ray->vector.y < 0)
		wall_type = SOUTH;
	else if (c == 'y')
		wall_type = NORTH;
	else if (c == 'x' && ray->vector.x < 0)
		wall_type = EAST;
	else
		wall_type = WEST;

	ray->wall_type = wall_type;
}

//void	print_ray(t_ray ray)
//{
//	printf("Ray distance is %f \n", ray.distance_to_wall);
//	printf("Wall type ");
//	if (ray.wall_type == NORTH)
//		printf("NORTH\n");
//	if (ray.wall_type == WEST)
//		printf("WEST\n");
//	if (ray.wall_type == EAST)
//		printf("EAST\n");
//	if (ray.wall_type == SOUTH)
//		printf("SOUTH\n");
//	printf("Ray has %f percentage \n", ray.percentage_of_image);
//}
