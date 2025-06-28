#include "cub3d.h"

// TODO: DL replace with cos/sin lookup tables
t_x_y rotate_vector(t_x_y *vet, float angle_degrees)
{
	float radians;
    float cos_theta;
    float sin_theta;

	t_x_y result;

	radians = deg_to_rad(angle_degrees);
	cos_theta = cosf(radians);
	sin_theta = sinf(radians);

    result.x = vet->x * cos_theta - vet->y * sin_theta;
    result.y = vet->x * sin_theta + vet->y * cos_theta;
    return (result);
}
//t_x_y rotate_vector(t_data dt, t_x_y vet, float angle_degrees)
//{
//	int index;
//	t_x_y result;

//	(void)dt;

//	// Normalize and clamp angle into table range
//	while (angle_degrees < 0)
//		angle_degrees += 360.0;
//	while (angle_degrees >= 360.0)
//		angle_degrees -= 360.0;

//	index = (int)(angle_degrees * PLAYER_ROTATION_STEP);

//	// Use precomputed values
//	float cos_theta = dt.sin_table[index];
//	float sin_theta = dt.cos_table[index];

//	result.x = vet.x * cos_theta - vet.y * sin_theta;
//	result.y = vet.x * sin_theta + vet.y * cos_theta;
//	return result;
//}
