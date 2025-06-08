#include "cub3d.h"

int	draw_ceiling(dt)
{
	(void)dt;
	return (EXIT_SUCCESS);
}

void render_3d(t_data *dt)
{
	printf("Rendering 3D scene...\n");
	size_t	i;
	double	height;
	t_coor	start;
	t_coor	end;
	int		center_y = WINDOW_H / 2;
	int color;

	draw_background(dt->img, C_COLOR);
	draw_square(dt, WINDOW_W/2, WINDOW_H + 200, WINDOW_W, F_COLOR);

	i = 0;
	while (i < WINDOW_W)
	{
		height = 1 / dt->rays[i].distance_to_wall;
		int wall_height = height * 400; // Tune this value as needed

		int top_y = center_y - wall_height;
		int bottom_y = center_y + wall_height;

		// Draw the wall segment (centered vertically)
		set_coor_values(&start, i, top_y);
		set_coor_values(&end, i, bottom_y);
		if (dt->rays[i].wall_type == NORTH)
			color = NAVY;
		else if (dt->rays[i].wall_type == SOUTH)
			color = PURPLE;
		else if (dt->rays[i].wall_type == EAST)
			color = GOLD;
		else
			color = BROWN;
		draw_vertical_line(dt, start, end, color);

		i++;
	}
}

int render_frame(void *param)
{
	t_data *dt = (t_data *)param;

	if (dt->win_ptr == NULL)
		return (1);
	draw_background(dt->img, BLACK);
	draw_grid(dt->img, DEF_GRID_SIZE, DEF_GRID_COLOR);
	if (SHOW_RAY_CALCULATION_LOG)
	{
		print_separator(3, "-");
		printf("👤 Player position (X, Y): %f %f\n", dt->player->pos.x, dt->player->pos.y);
		printf("Player orientation (deg): %f\n", dt->player->direction_vector_deg);
		printf("Player direction vector X Y: %f %f\n", dt->player->direction_vector.x, dt->player->direction_vector.y);
		printf("Player FOV (left) X Y: %f %f\n", 0.0, 0.0);
		printf("Player FOV (right) X Y: %f %f\n", 0.0, 0.0);
		print_separator(1, DEF_SEPARATOR_CHAR);
		// Calculate all rays
		calculate_all_rays(dt);
	}
	render_3d(dt);
	draw_minimap(dt);
	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->mlx_img, 0, 0);
	add_ui(dt);
	return (EXIT_SUCCESS);
}
