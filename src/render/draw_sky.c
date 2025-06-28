#include "cub3d.h"

int draw_sky(t_data *dt)
{
	int screen_x;
	int screen_y;
	int texture_x;
	int	texture_y;
	uint32_t color;

	// Player angle in radians
	float angle_rad = dt->player.direction_vector_deg * (M_PI / 180.0f);

	// Controls how fast the sky scrolls horizontally
	float rotation_scale = 6.0f;
	float angle_offset = fmodf((angle_rad * rotation_scale) / (2 * M_PI), 1.0f);
	if (angle_offset < 0)
		angle_offset += 1.0f;

	// Vertical camera pitch adjustment
	float vertical_sensitivity = 1.0f; // 0.1–0.3 is good range
	int delta = (int)(-(dt->view->screen_center_y - (WINDOW_H / 2)) * vertical_sensitivity);

	// Where to start sampling vertically from sky texture
	int texture_start_y = (dt->sky_image->height / 3) - (WINDOW_H / 20) + delta;

	screen_y = 0;
	while (screen_y < dt->view->screen_center_y)
	{
		screen_x = 0;
		while (screen_x < WINDOW_W)
		{
			// Horizontal wrapping based on angle
			float view_ratio = (float)screen_x / (float)WINDOW_W;
			float tex_ratio = fmodf(view_ratio + angle_offset, 1.0f);
			texture_x = (int)(tex_ratio * dt->sky_image->width);
			if (ENABLE_MOVING_SKY)
				texture_x += (dt->last_time - dt->start_time) / 100;

			// Vertical sampling without stretching
			texture_y = texture_start_y + screen_y;

			// Clamp to texture bounds
			if (texture_y < 0)
				texture_y = 0;
			if (texture_y > dt->sky_image->height)
				texture_y = dt->sky_image->height;

			char *pixel = dt->sky_image->addr
				+ texture_y * dt->sky_image->line_len
				+ texture_x * (dt->sky_image->bpp / 8);

			color = *(uint32_t *)pixel;

			img_pix_put(dt->scene_img, screen_x, screen_y, color);
			screen_x++;
		}
		screen_y++;
	}
	return (EXIT_SUCCESS);
}
