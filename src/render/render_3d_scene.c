#include "cub3d.h"

void render_3d_scene(t_data *dt)
{
	size_t	i;
	float	wall_height;
	int		screen_x;
	int 	top_y;
	int		bottom_y;

	if (SHOW_DEBUG_INFO)
		printf("Rendering 3D scene at %d FPS...\n", FPS);

	draw_ceiling(dt);
	draw_floor(dt);

	i = 0;
	while (i < CASTED_RAYS_COUNT)
	{
		// Distance-based projection
		wall_height = 1.0f / dt->rays[i].corrected_distance_to_wall * SCALING;

		top_y = dt->view->screen_center - wall_height;
		bottom_y = dt->view->screen_center + wall_height;

		 int texture_width = dt->map.wall_tile->texture.width;
		 int texture_height = dt->map.wall_tile->texture.height;

		 size_t texture_x = (dt->rays[i].percentage_of_image * texture_width);

		 if (texture_x >= (size_t)texture_width)
		 	texture_x = texture_width - 1;

		// Horizontal screen position
		int screen_slice_width = WINDOW_W / CASTED_RAYS_COUNT;
		screen_x = i * screen_slice_width;

		// Vertical wall slice drawing
		int y = top_y;
		while (y < ft_min(WINDOW_H, bottom_y))
		{
			// // Relative position on the wall
			int d = y - top_y;
			int texture_y = (d * texture_height) / (2 * wall_height);
			if (texture_y < 0)
			texture_y = 0;
			if (texture_y >= texture_height)
			texture_y = texture_height - 1;

			// Sample color from texture
			int tex_index = texture_y * texture_width + texture_x;

			int color = dt->map.wall_tile[dt->rays[i].wall_type].texture.texture_data[tex_index];

			apply_wall_shading_1(dt, i, &color);

			for (int w = 0; w < screen_slice_width; w++)
			{
				if (pixel_is_in_window(screen_x + w, y))
					img_pix_put(dt->scene_img, screen_x + w, y, color);
			}
			y++;
		}
		i++;
	}
	//print_separator_default();
	// render_sprites(dt);
}
