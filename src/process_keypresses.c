#include "cub3d.h"

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
	if (dt.keys[65362]) // Up
		dt.view->screen_center += 10;
	if (dt.keys[65364]) // Down
		dt.view->screen_center -= 10;
	if (dt.keys[65505])
		dt.player->move_speed_multiplier = MOVE_SPEED_MULTIPLIER_SLOW;
	else
		dt.player->move_speed_multiplier = 1;
}
