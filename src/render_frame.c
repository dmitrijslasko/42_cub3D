#include "cub3d.h"

int render_frame(void *param)
{
	t_data *dt = (t_data *)param;
	//t_ray	*rays;

	if (dt->win_ptr == NULL)
		return (1);
	draw_background(dt->img, BLACK);
	draw_map(dt);
	draw_grid(dt->img, DEF_GRID_SIZE, DEF_GRID_COLOR);
	draw_player(dt);
	if (SHOW_RAY_CALCULATION_LOG)
	{
		print_separator(3, "-");
		printf("👤 Player position (X, Y): %f %f\n", dt->player->pos.x, dt->player->pos.y);
		printf("Player orientation (deg): %f\n", dt->player->direction_vet_deg);
		printf("Player direction vector X Y: %f %f\n", dt->player->direction_vet.x, dt->player->direction_vet.y);
		printf("Player FOV (left) X Y: %f %f\n", 0.0, 0.0);
		printf("Player FOV (right) X Y: %f %f\n", 0.0, 0.0);
		print_separator(1, DEF_SEPARATOR_CHAR);
		// Calculate all rays
		calculate_all_rays(dt);
		//render_3d(dt);
	}

	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->mlx_img, 0, 0);
	add_ui(dt);
	return (EXIT_SUCCESS);
}
