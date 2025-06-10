#include "cub3d.h"

// Rotate both direction and camera plane
void rotate_player(t_data *dt, double d_angle, int direction)
{
    double angle_rad = deg_to_rad(d_angle * -direction);
    double old_dir_x = dt->player->direction_vector.x;
    double old_dir_y = dt->player->direction_vector.y;

    // Rotate direction vector using rotation matrix
    dt->player->direction_vector.x = old_dir_x * cosf(angle_rad) - old_dir_y * sinf(angle_rad);
    dt->player->direction_vector.y = old_dir_x * sinf(angle_rad) + old_dir_y * cosf(angle_rad);

	// Optional: also rotate camera plane vector if you're using raycasting
    // (same matrix applied to plane_x, plane_y if they exist)

    // Update stored angle, keeping it between 0 and 359
    dt->player->direction_vector_deg += d_angle;
    if (dt->player->direction_vector_deg >= 360.0f)
        dt->player->direction_vector_deg -= 360.0f;
    else if (dt->player->direction_vector_deg < 0.0f)
        dt->player->direction_vector_deg += 360.0f;
}
