
#include "cub3d.h"

t_ray	*constructor_ray(float dist, t_type_wall wall)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->distance_to_wall = dist;
	ray->wall_type = wall;
	ray->percentage_of_image = 0;
	return (ray);
}
