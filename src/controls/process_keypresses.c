#include "cub3d.h"

// TODO DL: This currently only works with vertical cells / movement
t_coor 	get_cell_ahead(t_data *dt)
{
	t_coor player_pos;
	t_coor cell_ahead;
	t_coor step;

	player_pos.x = (size_t)dt->player.pos.x;
	player_pos.y = (size_t)dt->player.pos.y;
	set_step(&step, &dt->player.direction_vector);
	cell_ahead.x = player_pos.x + step.x;
	cell_ahead.y = player_pos.y + 0;
	return (cell_ahead);
}

void	process_keypresses(t_data *dt)
{
	if (dt->keys[119])  // W
		move_forward_backward(dt, 1);
	if (dt->keys[115])  // S
		move_forward_backward(dt, -1);
	if (dt->keys[97])   // A
		move_sideways(dt, -1);
	if (dt->keys[100])  // D
		move_sideways(dt, 1);
	if (dt->keys[65361]) // Left arrow
		rotate_player(dt, KEYBOARD_PLAYER_ROTATION_STEP, 1);
	if (dt->keys[65363]) // Right arrow
		rotate_player(dt, KEYBOARD_PLAYER_ROTATION_STEP, -1);
	if (ENABLE_VERTICAL_LOOK)
	{
		if (dt->keys[65362]) // Up
			dt->view->screen_center_y = ft_min(
							dt->view->screen_center_y + KEYBOARD_PLAYER_VERTICAL_LOOK_STEP,
							WINDOW_H / 2 + LOCK_VERTICAL_LOOK_UP );
		if (dt->keys[65364]) // Down
			dt->view->screen_center_y = ft_max(
							dt->view->screen_center_y - KEYBOARD_PLAYER_VERTICAL_LOOK_STEP,
							WINDOW_H / 2 - LOCK_VERTICAL_LOOK_DOWN);
	}
	if (dt->keys[65505])
		dt->player.move_speed_multiplier = MOVE_SPEED_MULTIPLIER_SLOW;
	else
		dt->player.move_speed_multiplier = 1;
	t_coor	cell_ahead;
	t_door	*door;
	if (dt->keys[91])
	{
		cell_ahead = get_cell_ahead(dt);
		if (get_cell_type(&dt->map, &cell_ahead) == '|')
		{
			dt->view->show_door_open_message = 1;
			door = find_door_at(dt, cell_ahead.x, cell_ahead.y);
			door->open_progress = fmax(0.0f, door->open_progress - door->speed);
		}
	}
	if (dt->keys[93])
	{
		cell_ahead = get_cell_ahead(dt);
		if (get_cell_type(&dt->map, &cell_ahead) == '|')
		{
			dt->view->show_door_open_message = 1;
			door = find_door_at(dt, cell_ahead.x, cell_ahead.y);
			door->open_progress = fmin(1.0f, door->open_progress + door->speed);
		}
	}
}
