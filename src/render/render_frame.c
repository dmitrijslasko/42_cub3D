#include "cub3d.h"

int	render_ui_message(t_data *dt)
{
	for (int row = 0; row < dt->message_img[0].height; row++)
	{
		for (int col = 0; col < dt->message_img[0].width; col++)
		{
			char *src_pixel;

			src_pixel = dt->message_img[0].addr + row * dt->message_img[0].line_len + col * dt->message_img->bpp / 8;
			unsigned int color;

			color = *(unsigned int *)src_pixel;

			int draw_x = ((WINDOW_W - dt->message_img[0].width)/ 2) + col;
			int draw_y = 700 + row;

			if (color != TRANSPARENT_COLOR)
				img_pix_put(dt->scene_img, draw_x, draw_y, color);
		}
	}
	return (EXIT_SUCCESS);
}

int	render_frame(void *param)
{
	long		current_time;
	t_data		*dt;

	dt = (t_data *)param;

	// Render FPS at the predefined FPS
	current_time = get_current_time_in_ms();
	dt->delta_time = current_time - dt->last_time;
	if (dt->delta_time < (1000 / FPS))
		return (EXIT_SUCCESS);
	dt->last_time = current_time;

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

	if (dt->view->show_debug_info)
		show_debug_info(dt);

	if (dt->view->show_door_open_message)
		render_ui_message(dt);

	add_ui(dt);

	return (EXIT_SUCCESS);
}

