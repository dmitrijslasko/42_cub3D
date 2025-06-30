#include "cub3d.h"

int	apply_distance_shadow(t_data *dt, size_t i, int *color, float strength)
{
	float	distance;
	float	shade;
	int		r;
	int		g;
	int		b;

	distance = dt->rays[i].distance_to_wall;
	shade = 1.0f / (1.0f + distance * strength);
	if (shade < 0.1f)
		shade = 0.1f;
	r = ((*color >> 16) & 0xFF) * shade;
	g = ((*color >> 8) & 0xFF) * shade;
	b = ((*color >> 0) & 0xFF) * shade;
	*color = (r << 16) | (g << 8) | (b << 0);
	return (EXIT_SUCCESS);
}
