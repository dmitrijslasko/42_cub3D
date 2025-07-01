#include "cub3d.h"

static void	process_vertical_look(t_data *dt)
{
	if (!ENABLE_VERTICAL_LOOK)
		return ;
	if (dt->keys[XK_Up])
	{
		dt->has_changed = 1;
		dt->view->screen_center_y = ft_min(
				dt->view->screen_center_y + KEYBOARD_VERTICAL_LOOK_STEP,
				WINDOW_H / 2 + VERTICAL_LOOK_LOCK_UP);
	}
	if (dt->keys[XK_Down])
	{
		dt->has_changed = 1;
		dt->view->screen_center_y = ft_max(
				dt->view->screen_center_y - KEYBOARD_VERTICAL_LOOK_STEP,
				WINDOW_H / 2 - VERTICAL_LOOK_LOCK_DOWN);
	}
}

void	maneger_door_open_close(t_data *dt, int dir)
{
	t_coor	cell_ahead;
	t_door	*door;

	dt->has_changed = 1;
	cell_ahead = get_cell_ahead(dt);
	if (get_cell_type(&dt->map, &cell_ahead) == '|')
	{
		dt->view->show_door_open_message = 1;
		door = find_door_at(dt, cell_ahead.x, cell_ahead.y);
		if (dir == 1)
			door->open_progress = fmax(0.0f, door->open_progress - door->speed);
		else
			door->open_progress = fmin(1.0f, door->open_progress + door->speed);
	}
}

static void	process_door(t_data *dt)
{
	if (dt->keys[XK_bracketleft])
		maneger_door_open_close(dt, -1);
	if (dt->keys[XK_bracketright])
		maneger_door_open_close(dt, 1);
}

void	process_keypresses(t_data *dt)
{
	if (dt->keys[XK_w])
		move_forward_backward(dt, 1);
	if (dt->keys[XK_s])
		move_forward_backward(dt, -1);
	if (dt->keys[XK_a])
		move_sideways(dt, -1);
	if (dt->keys[XK_d])
		move_sideways(dt, 1);
	if (dt->keys[XK_Left])
		rotate_player(dt, KEYBOARD_PLAYER_ROTATION_STEP, 1);
	if (dt->keys[XK_Right])
		rotate_player(dt, KEYBOARD_PLAYER_ROTATION_STEP, -1);
	if (dt->keys[XK_Shift_L])
		dt->player.move_speed_multiplier = MOVE_SPEED_MULTIPLIER_SLOW;
	else
		dt->player.move_speed_multiplier = 1;
	process_door(dt);
	process_vertical_look(dt);
}
