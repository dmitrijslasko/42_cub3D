#include "cub3d.h"

#define SHADOW_STRENGTH 0.2f

int	apply_wall_shading_1(t_data *dt, size_t i, int *color)
{
	// Apply shading
	float distance = dt->rays[i].distance_to_wall;
	float shade = 1.0f / (1.0f + distance * SHADOW_STRENGTH);
	if (shade < 0.1f) shade = 0.1f;

	int r = ((*color >> 16) & 0xFF) * shade;
	int g = ((*color >> 8) & 0xFF) * shade;
	int b = (*color & 0xFF) * shade;
	*color = (r << 16) | (g << 8) | b;

	return (EXIT_SUCCESS);
}
