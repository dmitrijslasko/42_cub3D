#include "cub3d.h"

t_x_y	rotate_vector(t_x_y *vec, float angle_degrees, t_data *dt)
{
	t_x_y	result;
	int		index_base;
	int		index_next;
	float	f_index;
	float	t;
	float	cos_theta;
	float	sin_theta;

	// Normalize angle
	while (angle_degrees < 0)
		angle_degrees += 360;
	while (angle_degrees >= 360)
		angle_degrees -= 360;

	// Convert to float index in table
	f_index = angle_degrees * TRIG_PRECISION;
	index_base = (int)f_index;
	t = f_index - index_base;
	index_next = (index_base + 1) % PRECALCULATED_TRIG;

	// Interpolate for smoothness
	cos_theta = (1.0f - t) * dt->cos_table[index_base] + t * dt->cos_table[index_next];
	sin_theta = (1.0f - t) * dt->sin_table[index_base] + t * dt->sin_table[index_next];

	// Rotate vector
	result.x = vec->x * cos_theta - vec->y * sin_theta;
	result.y = vec->x * sin_theta + vec->y * cos_theta;
	return result;
}
