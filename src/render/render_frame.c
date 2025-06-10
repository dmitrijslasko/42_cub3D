#include "cub3d.h"

long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
void render_3d(t_data *dt)
{
	size_t	i;
	double	height;
	t_coor	start;
	t_coor	end;
	int		color;
	int		screen_x;

	if (SHOW_DEBUG_INFO)
		printf("Rendering 3D scene at %d FPS...\n", FPS);

	draw_ceiling(dt);
	draw_floor(dt);

	i = 0;
	while (i < CASTED_RAYS_COUNT)
	{
		height = 1 / dt->rays[i].distance_to_wall;

		int wall_height = height * SCALING; // Adjust scaling as needed

		int top_y = WINDOW_H / 2 - wall_height;
		int bottom_y = WINDOW_H / 2 + wall_height;

		screen_x = i * (WINDOW_W / CASTED_RAYS_COUNT);

		if (dt->rays[i].wall_type == NORTH)
			color = DARKGREY;
		else if (dt->rays[i].wall_type == SOUTH)
			color = PURPLE;
		else if (dt->rays[i].wall_type == EAST)
			color = GOLD;
		else
			color = BROWN;

		// Draw a 2-pixel wide wall slice (as vertical bars)
		for (int w = 0; w < (WINDOW_W / CASTED_RAYS_COUNT); w++)
		{
			set_coor_values(&start, screen_x + w, ft_max(0, top_y));
			set_coor_values(&end, screen_x + w, ft_min(WINDOW_W, bottom_y));
			draw_vertical_line(dt, start, end, color);
		}
		i++;
	}
}

void	print_player_logs(t_data *dt)
{
	if (SHOW_DEBUG_INFO)
	{
		print_separator(3, "-");
		printf("👤 Player position (X, Y): %f %f\n", dt->player->pos.x, dt->player->pos.y);
		printf("Player orientation (deg): %f\n", dt->player->direction_vector_deg);
		printf("Player direction vector X Y: %f %f\n", dt->player->direction_vector.x, dt->player->direction_vector.y);
		printf("Player FOV (left) X Y: %f %f\n", 0.0, 0.0);
		printf("Player FOV (right) X Y: %f %f\n", 0.0, 0.0);
		print_separator(1, DEF_SEPARATOR_CHAR);
	}
}
void	toggle(char *setting)
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
}

int	render_frame(void *param)
{
	static long	last_time = 0;
	long		current_time;
	t_data		*dt;

	dt = (t_data *)param;

	// render FPS at the predefined FPS
	current_time = get_time_in_ms();
	//printf("ms: %ld", current_time);
	if (current_time - last_time < (1000 / FPS))
	{
		//printf(" >>> skipping frame...\n");
		//usleep(5000);
		return (EXIT_SUCCESS);
	}

	last_time = current_time;

	if (dt->win_ptr == NULL)
		return (EXIT_FAILURE);

	process_keypresses(*dt);
	mlx_mouse_move(dt->mlx_ptr, dt->win_ptr, WINDOW_W / 2, WINDOW_H / 2);

	if (SHOW_CALCULATION_LOGS)
		print_player_logs(dt);

	calculate_all_rays(dt);
	render_3d(dt);
	if (dt->view->show_minimap)
		draw_minimap(dt);

	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->mlx_img, 0, 0);
	add_ui(dt);
	return (EXIT_SUCCESS);
}

