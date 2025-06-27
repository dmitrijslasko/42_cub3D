#include "cub3d.h"

// Full RGBA version
#include <stdint.h>

int create_color_rgba(int r, int g, int b, int a) {
    return (a << 24) | (r << 16) | (g << 8) | b;
}

// RGB version (alpha = 255)
int create_color_rgb(int r, int g, int b) {
    return create_color_rgba(r, g, b, 255);
}

int	draw_ceiling(t_data *dt)
{
	int			color;
	t_coor		top_left;
	t_coor		bottom_right;

	set_coor_values(&top_left, 0, 0);
	set_coor_values(&bottom_right, WINDOW_W, dt->view->screen_center);
	// if (dt->map->wall_tile[CEILING].is_color)
	color = create_color_rgb(dt->map.wall_tile[CEILING].color.r, dt->map.wall_tile[CEILING].color.g, dt->map.wall_tile[CEILING].color.b);
	draw_rectangle(dt->scene_img, top_left, bottom_right, color);

	return (EXIT_SUCCESS);
}

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
	int delta = (int)(-(dt->view->screen_center - (WINDOW_H / 2)) * vertical_sensitivity);

	// Where to start sampling vertically from sky texture
	int texture_start_y = (dt->sky_image->height / 2) - (WINDOW_H / 10) + delta;

	for (screen_y = 0; screen_y < dt->view->screen_center; screen_y++)
	{
		for (screen_x = 0; screen_x < WINDOW_W; screen_x++)
		{
			// Horizontal wrapping based on angle
			float view_ratio = (float)screen_x / (float)WINDOW_W;
			float tex_ratio = fmodf(view_ratio + angle_offset, 1.0f);
			texture_x = (int)(tex_ratio * dt->sky_image->width);

			// Vertical sampling without stretching
			texture_y = texture_start_y + screen_y;

			// Clamp to texture bounds
			if (texture_y < 0) texture_y = 0;
			if (texture_y >= dt->sky_image->height) texture_y = dt->sky_image->height - 1;

			char *pixel = dt->sky_image->addr
				+ texture_y * dt->sky_image->line_len
				+ texture_x * (dt->sky_image->bpp / 8);

			color = *(uint32_t *)pixel;

			img_pix_put(dt->scene_img, screen_x, screen_y, color);
		}
	}
	return (EXIT_SUCCESS);
}



int	draw_floor(t_data *dt)
{
	int		color;
	t_coor	top_left;
	t_coor	bottom_right;

	set_coor_values(&top_left, 0, dt->view->screen_center);
	set_coor_values(&bottom_right, WINDOW_W, WINDOW_H);

	color = create_color_rgb(dt->map.wall_tile[FLOOR].color.r, dt->map.wall_tile[FLOOR].color.g, dt->map.wall_tile[FLOOR].color.b);
	draw_rectangle(dt->scene_img, top_left, bottom_right, color);
	return (EXIT_SUCCESS);
}
