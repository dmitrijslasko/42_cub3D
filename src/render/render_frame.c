#include "cub3d.h"

int	render_frame(void *param)
{
	static long	last_time = 0;
	long		current_time;
	t_data		*dt;

	dt = (t_data *)param;

	// Render FPS at the predefined FPS
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


	calculate_all_rays(dt);

	render_3d_scene(dt);

	update_minimap(dt);

	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->scene_img->mlx_img, 0, 0);

	// minimap base image
	//mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->minimap_base_img->mlx_img, 600, 600);

	// minimap (open/close with Tab)
	if (dt->view->show_minimap)
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->minimap->mlx_img, MINIMAP_OFFSET_X, MINIMAP_OFFSET_Y);
	add_ui(dt);
	return (EXIT_SUCCESS);
}

