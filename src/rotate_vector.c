#include "cub3d.h"

t_x_y rotate_vector(t_x_y vet, float angle_degrees)
{
	float radians;
    float cos_theta;
    float sin_theta;
	t_x_y result;

	radians = deg_to_rad(angle_degrees);
	cos_theta = cosf(radians);
	sin_theta = sinf(radians);

    result.x = vet.x * cos_theta - vet.y * sin_theta;
    result.y = vet.x * sin_theta + vet.y * cos_theta;
    return (result);
}
