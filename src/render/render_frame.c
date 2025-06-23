#include "cub3d.h"

int clamp(int value, int min, int max) {
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

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
				img_pix_put(dt->scene_img, screen_x + w, y, color);
			y++;
		}
		i++;
	}
	//print_separator_default();
	// render_sprites(dt);
}

int	render_frame(void *param)
{
	static long	last_time = 0;
	long		current_time;
	t_data		*dt;

	dt = (t_data *)param;

	// Render FPS at the predefined FPS
	// usleep(500);
	current_time = get_current_time_in_ms();
	if (current_time - last_time < (1000 / FPS))
	{
		//my_sleep();
		return (EXIT_SUCCESS);
	}
	last_time = current_time;

	if (dt->win_ptr == NULL)
		return (EXIT_FAILURE);

	process_keypresses(dt);

	reset_mouse_position(dt);

	// if (SHOW_CALCULATION_LOGS)
		// print_player_logs(dt);

	calculate_all_rays(dt);
	render_3d_scene(dt);

	update_minimap(dt);

	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->scene_img->mlx_img, 0, 0);

	// minimap base image
	// mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->minimap_base->mlx_img, 600, 600);

	// minimap (open/close with Tab)
	if (dt->view->show_minimap)
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->minimap->mlx_img, MINIMAP_OFFSET_X, MINIMAP_OFFSET_Y);
	add_ui(dt);
	return (EXIT_SUCCESS);
}

