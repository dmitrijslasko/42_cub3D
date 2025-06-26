#include "cub3d.h"

bool	initialize_rays(t_data *dt)
{
	size_t	i;

	printf(TXT_YELLOW "Initializing the ray array...\n" TXT_RESET);
	printf(TXT_YELLOW "Total rays to be cast: %d\n" TXT_RESET, CASTED_RAYS_COUNT);
	dt->rays = malloc(sizeof(t_ray) * WINDOW_W);
	if (dt->rays == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < CASTED_RAYS_COUNT)
	{
		dt->rays[i].distance_to_wall = 0;
		dt->rays[i].distance_to_door = 0;
		dt->rays[i].percentage_of_image = 0;
		dt->rays[i].wall_hit.x = 0;
		dt->rays[i].wall_hit.y = 0;
		dt->rays[i].wall_type = -1;
		dt->rays[i].cell_type = -1;
		dt->rays[i].door = NULL;
		dt->rays[i].hit_side = NULL;
		dt->rays[i].hit_content = NULL;
		i++;
	}
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	print_separator_default();
	return (0);
}
