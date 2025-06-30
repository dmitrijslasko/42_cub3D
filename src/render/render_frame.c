#include "cub3d.h"

int update_prompt_message(t_data *dt)
{
	t_coor cell_ahead;

	cell_ahead = get_cell_ahead(dt);
	dt->player.cell_type_ahead = get_cell_type(&dt->map, &cell_ahead);
	if (dt->player.cell_type_ahead == '|')
		dt->view->show_door_open_message = 1;
	else
		dt->view->show_door_open_message = 0;
	return (EXIT_SUCCESS);
}

int	render_frame(void *param)
{
	t_data		*dt;
	long		current_time;

	dt = (t_data *)param;
	current_time = get_current_time_in_ms();
	dt->delta_time = current_time - dt->last_time;
	if (dt->delta_time < (1000 / FPS))
		return (0);
	dt->last_time = current_time;
	reset_mouse_position(dt);
	process_keypresses(dt);
	calculate_all_rays(dt);
	update_prompt_message(dt);
	render_3d_scene(dt);
	update_minimap(dt);
	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->scene_img->mlx_img, 0, 0);
	if (dt->view->show_minimap)
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->minimap->mlx_img, MINIMAP_OFFSET_X, MINIMAP_OFFSET_Y);
	if (dt->view->show_debug_info)
		show_debug_info(dt);
	if (dt->view->show_door_open_message)
		render_ui_message(dt);
	add_ui(dt);
	return (EXIT_SUCCESS);
}

