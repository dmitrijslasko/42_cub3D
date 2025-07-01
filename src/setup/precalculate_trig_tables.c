#include "cub3d.h"

int	precalculate_trig_tables(t_data *dt)
{
	printf("Precalculating sin and cos tables (%d values)...", PRECALCULATED_TRIG);
	for (int i = 0; i < PRECALCULATED_TRIG; i++)
	{
		float angle_deg = (float)i / TRIG_PRECISION;
		float angle_rad = deg_to_rad(angle_deg);
		dt->sin_table[i] = sinf(angle_rad);
		dt->cos_table[i] = cosf(angle_rad);
	}
	printf(" Done!\n");
	return (EXIT_SUCCESS);
}

