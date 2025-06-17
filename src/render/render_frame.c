#include "cub3d.h"

void render_3d_scene(t_data *dt)
{
	size_t	i;
	float	wall_height;
	int		screen_x;

	if (SHOW_DEBUG_INFO)
		printf("Rendering 3D scene at %d FPS...\n", FPS);

	draw_ceiling(dt);
	draw_floor(dt);

	for (i = 0; i < CASTED_RAYS_COUNT; i++)
	{
		// Distance-based projection
		wall_height = 1.0f / dt->rays[i].distance_to_wall * SCALING;

		int top_y = dt->view->screen_center - wall_height * 1;
		int bottom_y = dt->view->screen_center + wall_height * 1;
		//printf("top bottom %d %d\n", top_y, bottom_y);

		int texture_width = dt->textures->width;
		int texture_height = dt->textures->height;

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
			// Relative position on the wall
			int d = y - top_y;
			int texture_y = (d * texture_height) / (2 * wall_height);
			if (texture_y < 0)
				texture_y = 0;
			if (texture_y >= texture_height)
				texture_y = texture_height - 1;

			// Sample color from texture
			int tex_index = texture_y * texture_width + texture_x;
			int color = dt->textures[dt->rays[i].wall_type - 1].texture_data[tex_index];

			apply_wall_shading_1(dt, i, &color);

			for (int w = 0; w < screen_slice_width; w++)
				img_pix_put(dt->img, screen_x + w, y, color);
			y++;
		}
	}
	//print_separator_default();
	//render_sprites(dt);
}

int	render_frame(void *param)
{
	static long	last_time = 0;
	long		current_time;
	t_data		*dt;

	dt = (t_data *)param;

	// render FPS at the predefined FPS
	current_time = get_current_time_in_ms();
	//printf("ms: %ld", current_time);
	if (current_time - last_time < (1000 / FPS))
	{
		//usleep(5000);
		return (EXIT_SUCCESS);
	}

	last_time = current_time;

	if (dt->win_ptr == NULL)
		return (EXIT_FAILURE);

	process_keypresses(*dt);

	reset_mouse_position(dt);

	// if (SHOW_CALCULATION_LOGS)
	// 	print_player_logs(dt);

	calculate_all_rays(dt);
	render_3d_scene(dt);
	if (dt->view->show_minimap)
		draw_minimap(dt);

	dt->player->player_pos_x = GRID_SIZE * dt->player->pos.x;
	dt->player->player_pos_y = GRID_SIZE * dt->player->pos.y;
	// printf("Player position X Y: %zu %zu\n", dt->player->player_pos_x, dt->player->player_pos_y);

	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->mlx_img, 0, 0);
	add_ui(dt);
	return (EXIT_SUCCESS);
}

