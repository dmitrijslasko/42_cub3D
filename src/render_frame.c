#include "cub3d.h"

int	draw_ceiling(t_data *dt)
{
	t_coor	top_left;
	t_coor	bottom_right;

	set_coor_values(&top_left, 0, 0);
	set_coor_values(&bottom_right, WINDOW_W, WINDOW_H / 2);

	draw_rectangle(dt, top_left, bottom_right, DEF_CEILING_COLOR);
	return (EXIT_SUCCESS);
}

int	draw_floor(t_data *dt)
{
	t_coor	top_left;
	t_coor	bottom_right;

	set_coor_values(&top_left, 0, WINDOW_H / 2);
	set_coor_values(&bottom_right, WINDOW_W, WINDOW_H);

	draw_rectangle(dt, top_left, bottom_right, DEF_FLOOR_COLOR);
	return (EXIT_SUCCESS);
}

long	get_time_in_ms(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void render_3d(t_data *dt)
{
	printf("Rendering 3D scene at %d FPS...\n", FPS);
	size_t	i;
	float	height;
	t_coor	start;
	t_coor	end;
	int		center_y = WINDOW_H / 2;
	int		color;
	int		screen_x;

	draw_ceiling(dt);
	draw_floor(dt);

	i = 0;
	while (i < CASTED_RAYS_COUNT)
	{
		height = 1 / dt->rays[i].distance_to_wall;
		int wall_height = height * 400; // Adjust scaling as needed

		int top_y = center_y - wall_height;
		int bottom_y = center_y + wall_height;

		screen_x = i * (WINDOW_W / CASTED_RAYS_COUNT);

		if (dt->rays[i].wall_type == NORTH)
			color = NAVY;
		else if (dt->rays[i].wall_type == SOUTH)
			color = PURPLE;
		else if (dt->rays[i].wall_type == EAST)
			color = GOLD;
		else
			color = BROWN;

		// Draw a 2-pixel wide wall slice (as vertical bars)
		for (int w = 0; w < (WINDOW_W / CASTED_RAYS_COUNT); w++)
		{
			set_coor_values(&start, screen_x + w, top_y);
			set_coor_values(&end, screen_x + w, bottom_y);
			draw_vertical_line(dt, start, end, color);
		}
		i++;
	}
}


void	print_player_logs(t_data *dt)
{
	print_separator(3, "-");
	printf("👤 Player position (X, Y): %f %f\n", dt->player->pos.x, dt->player->pos.y);
	printf("Player orientation (deg): %f\n", dt->player->direction_vector_deg);
	printf("Player direction vector X Y: %f %f\n", dt->player->direction_vector.x, dt->player->direction_vector.y);
	printf("Player FOV (left) X Y: %f %f\n", 0.0, 0.0);
	printf("Player FOV (right) X Y: %f %f\n", 0.0, 0.0);
	print_separator(1, DEF_SEPARATOR_CHAR);
}

int	render_frame(void *param)
{
	static long	last_time = 0;
	long		current_time;
	t_data		*dt = (t_data *)param;

	current_time = get_time_in_ms();
	if (current_time - last_time < 1000 / FPS)
		return (0);
	last_time = current_time;

	if (dt->win_ptr == NULL)
		return (1);

	if (dt->keys[119])  // W
		move_forward_backward(dt, 1);
	if (dt->keys[115])  // S
		move_forward_backward(dt, -1);
	if (dt->keys[97])   // A
		move_sideways(dt, -1);
	if (dt->keys[100])  // D
		move_sideways(dt, 1);
	if (dt->keys[65361]) // Left arrow
		rotate_player(dt, -1);
	if (dt->keys[65363]) // Right arrow
		rotate_player(dt, 1);

	if (SHOW_RAY_CALCULATION_LOG)
		print_player_logs(dt);

	calculate_all_rays(dt);
	render_3d(dt);
	draw_minimap(dt);
	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->mlx_img, 0, 0);
	add_ui(dt);
	return (EXIT_SUCCESS);
}

