#include "cub3d.h"

int	apply_distance_shadow(t_data *dt, size_t i, int *color)
{
	float distance;
	float shade;

	distance = dt->rays[i].distance_to_wall;
	shade = 1.0f / (1.0f + distance * DISTANCE_SHADOW_STRENGTH);

	if (shade < 0.1f)
		shade = 0.1f;

	int r = ((*color >> 16) & 0xFF) * shade;
	int g = ((*color >> 8) & 0xFF) * shade;
	int b = (*color & 0xFF) * shade;
	*color = (r << 16) | (g << 8) | b;

	return (EXIT_SUCCESS);
}
