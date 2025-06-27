#include "cub3d.h"

int	precalculate_trig_tables(t_data *dt)
{
	size_t	angle_index;

	printf("Precalculating sin and cos tables...");
	angle_index = 0;
	while (angle_index < PRECALCULATED_TRIG)
	{
    	dt->sin_table[angle_index] = sinf(angle_index * M_PI / 180);
		dt->cos_table[angle_index] = cosf(angle_index * M_PI / 180);
		angle_index++;
	}
	printf(" Done!\n");
	return (EXIT_SUCCESS);
}
