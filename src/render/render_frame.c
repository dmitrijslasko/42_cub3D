#include "cub3d.h"

int	apply_wall_shading_1(t_data *dt, size_t i, int *color)
{
	// Apply shading
	float distance = dt->rays[i].distance_to_wall;
	float shade = 1.0f / (1.0f + distance * 0.2f);
	if (shade < 0.1f) shade = 0.1f;

	int r = ((*color >> 16) & 0xFF) * shade;
	int g = ((*color >> 8) & 0xFF) * shade;
	int b = (*color & 0xFF) * shade;
	*color = (r << 16) | (g << 8) | b;
	return (EXIT_SUCCESS);
}


void render_3d_scene(t_data *dt)
{
	size_t	i;
	float	height;
	int		screen_x;

	if (SHOW_DEBUG_INFO)
		printf("Rendering 3D scene at %d FPS...\n", FPS);

	draw_ceiling(dt);
	draw_floor(dt);

	for (i = 0; i < CASTED_RAYS_COUNT; i++)
	{
		// Distance-based projection
		height = 1.0f / dt->rays[i].distance_to_wall * SCALING;

		int top_y = dt->view->screen_center - height * 1;
		int bottom_y = dt->view->screen_center + height;

		int texture_width = dt->textures->width;
		int texture_height = dt->textures->height;

		size_t texture_x = (dt->rays[i].percentage_of_image * texture_width);

		if (texture_x >= (size_t)texture_width)
			texture_x = texture_width - 1;

		// Horizontal screen position
		int screen_slice_width = WINDOW_W / CASTED_RAYS_COUNT;
		screen_x = i * screen_slice_width;

		// Vertical wall slice drawing
		int y;

		y = ft_max(0, top_y);
		while (y < ft_min(WINDOW_H, bottom_y))
		{
			// Relative position on the wall
			int d = y - top_y;
			int texture_y = (d * texture_height) / (2 * height);
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
}

void	toggle_setting(char *setting)
{
	*setting ^= 1;
}

void	process_keypresses(t_data dt)
{
	if (dt.keys[119])  // W
		move_forward_backward(&dt, 1);
	if (dt.keys[115])  // S
		move_forward_backward(&dt, -1);
	if (dt.keys[97])   // A
		move_sideways(&dt, -1);
	if (dt.keys[100])  // D
		move_sideways(&dt, 1);
	if (dt.keys[65361]) // Left arrow
		rotate_player(&dt, KEYBOARD_PLAYER_ROTATION_STEP, 1);
	if (dt.keys[65363]) // Right arrow
		rotate_player(&dt, KEYBOARD_PLAYER_ROTATION_STEP, -1);
	if (dt.keys[65362]) // Up
		dt.view->screen_center += 10;
	if (dt.keys[65364]) // Down
		dt.view->screen_center -= 10;
	if (dt.keys[65505])
		dt.player->move_speed_multiplier = MOVE_SPEED_MULTIPLIER_SLOW;
	else
		dt.player->move_speed_multiplier = 1;
}



int sign(int x)
{
	return (x > 0) - (x < 0);
}

//Make sure you're not rotating the player based on movement during suppression (i.e., ignore dx/dy for input when suppress_mouse_frames > 0 too).

# define CENTER_TOLERANCE	25

int	reset_mouse_position(t_data *dt)
{
	int dx = dt->mouse.x - WINDOW_W / 2;
	int dy = dt->mouse.y - WINDOW_H / 2;

	if (dt->mouse.suppress_mouse_frames > 0)
	{
		dt->mouse.suppress_mouse_frames--;
		return (EXIT_SUCCESS);
	}

	if (abs(dx) > CENTER_TOLERANCE || abs(dy) > CENTER_TOLERANCE)
	{
		int new_x = dt->mouse.x;
		int new_y = dt->mouse.y;

		if (abs(dx) > CENTER_TOLERANCE)
				new_x = WINDOW_W / 2 + sign(dx) * CENTER_TOLERANCE;
		if (abs(dy) > CENTER_TOLERANCE)
				new_y = WINDOW_H / 2 + sign(dy) * CENTER_TOLERANCE;

		dt->mouse.suppress_mouse_frames = 2;
		mlx_mouse_move(dt->mlx_ptr, dt->win_ptr, new_x, new_y);
	}
	//mlx_mouse_move(dt->mlx_ptr, dt->win_ptr, WINDOW_W / 2, dt->mouse.y);

	return (EXIT_SUCCESS);
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

	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->mlx_img, 0, 0);
	add_ui(dt);
	return (EXIT_SUCCESS);
}

