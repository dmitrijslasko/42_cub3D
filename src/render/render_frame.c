/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:21 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/10 20:14:04 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_prompt_message(t_data *dt)
{
	t_coor	cell_ahead;

	cell_ahead = get_cell_ahead(dt);
	dt->player.cell_type_ahead = get_cell_type(&dt->map, &cell_ahead);
	if (ft_strchr(DOOR_TYPES, dt->player.cell_type_ahead))
		dt->view->show_door_open_message = 1;
	else
		dt->view->show_door_open_message = 0;
	return (EXIT_SUCCESS);
}

static int	render_minimap_and_ui(t_data *dt)
{
	if (dt->view->show_minimap)
		put_img_to_img(dt->final_frame_img, dt->minimap_img, MINIMAP_OFFSET_X, MINIMAP_OFFSET_Y);
	render_ui(dt);
	return (EXIT_SUCCESS);
}

int	render_frame(void *param)
{
	t_data		*dt;
	long		current_time;

	dt = (t_data *)param;
	current_time = get_current_time_in_ms();
	dt->time.delta_time = current_time - dt->time.last_time;
	if (dt->time.delta_time < (1000 / FPS))
	{
		my_sleep();
		return (0);
	}
	dt->time.last_time = current_time;
	//if (BONUS)
	reset_mouse_position(dt);
	process_keypresses(dt);
	calculate_all_rays(dt);
	render_3d_scene(dt);
	put_img_to_img(dt->final_frame_img, dt->raycasting_scene_img, 0, 0);
	if (RENDER_SPRITES)
		render_all_sprites(dt);
	if (dt->view->show_minimap)
		update_minimap(dt);
	update_prompt_message(dt);
	// put_img_to_img(dt->final_frame_img, dt->ui_img, 100, 100);
	render_minimap_and_ui(dt);
	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr,dt->final_frame_img->mlx_img, 0, 0);
	if (dt->view->show_debug_info)
		 show_debug_info(dt);
 	show_player_info(dt);
	if (dt->view->show_door_open_message)
	{
		mlx_string_put(dt->mlx_ptr, dt->win_ptr, 240, 300, WHITE, "Press [ / ] to open the door");
		// render_ui_message(dt);
	}
		float speed;
		speed = 0.004f; // higher = faster oscillation (tweak to taste)
		int amplitude;
		if (dt->player.move_speed_multiplier == 1)
			amplitude = 20;
		else
			amplitude = 2;
		int y_offset = amplitude * sin((dt->time.last_time - dt->time.start_time) * speed); // total_time in seconds, or use a step counter

		put_img_to_img(dt->final_frame_img, &dt->weapon_img[dt->weapon_current_frame], (WINDOW_W - 360) / 2 + y_offset / 4, 20 + y_offset);
	dt->frames_drawn_count++;
	return (EXIT_SUCCESS);
}
