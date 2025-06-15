#include "cub3d.h"

static int	keypress_exit(t_data *dt)
{
	printf("ESC button pressed, closing the window...");
	mlx_destroy_window(dt->mlx_ptr, dt->win_ptr);
	dt->win_ptr = NULL;
	free(dt->rays);
	printf(" Done!\n");
	return (EXIT_SUCCESS);
}

int	close_window(void)
{
	exit(0);
}

// TODO DL: this can be replaced by an already existing function, bool	check_hit_wall(t_coor coord, t_map map)
int	map_position_is_walkable(t_map *map, float row, float col)
{
	if (map->map_data[(size_t)col][(size_t)row] != '1')
		return (1);
	return (0);
}

#define COLLISION_SAMPLES 64 // Increase to 32 or 64 for more accuracy

int is_position_walkable_with_radius(t_map *map, float x, float y)
{
	float radius = MIN_DISTANCE_TO_WALL;
	for (int i = 0; i < COLLISION_SAMPLES; i++)
	{
		float angle = 2 * M_PI * i / COLLISION_SAMPLES;
		float check_x = x + cosf(angle) * radius;
		float check_y = y + sinf(angle) * radius;

		if (!map_position_is_walkable(map, check_x, check_y))
			return 0; // Not walkable at this point
	}
	return 1; // All points are walkable
}


int set_player_position(t_data *dt, float dx, float dy)
{
	t_x_y *player_pos = &(dt->player->pos);
	float new_x = player_pos->x + dx;
	float new_y = player_pos->y + dy;

	int moved = 0;

	// Try full move
	if (is_position_walkable_with_radius(dt->map, new_x, new_y))
	{
		player_pos->x = new_x;
		player_pos->y = new_y;
		moved = 1;
	}
	else
	{
		// Try sliding on X only
		if (is_position_walkable_with_radius(dt->map, new_x, player_pos->y))
		{
			player_pos->x = new_x;
			moved = 1;
		}
		// Try sliding on Y only
		if (is_position_walkable_with_radius(dt->map, player_pos->x, new_y))
		{
			player_pos->y = new_y;
			moved = 1;
		}
	}
	return (moved);
}

int move_forward_backward(t_data *dt, int direction)
{
	float speed;

	speed = KEYBOARD_PLAYER_STEP_FORWARD;
	if (sign(direction))
		speed = KEYBOARD_PLAYER_STEP_BACKWARD;
	speed *= dt->player->move_speed_multiplier;

	float dx = dt->player->direction_vector.x * speed * direction;
	float dy = dt->player->direction_vector.y * speed * direction;

	return set_player_position(dt, dx, dy);
}


int move_sideways(t_data *dt, int direction)
{
	t_x_y rotated_vector = rotate_vector(*dt, dt->player->direction_vector, 90.0f * direction);
	float speed = KEYBOARD_PLAYER_STEP_SIDE * dt->player->move_speed_multiplier;

	float dx = rotated_vector.x * speed;
	float dy = rotated_vector.y * speed;

	return set_player_position(dt, dx, dy);
}


int	handle_keypress(int keycode, t_data *dt)
{
	//printf("Key %d pressed\n", keycode);
	if (keycode == ESC_BUTTON)
	{
		keypress_exit(dt);
		close_window();
	}
	else if (keycode >= 0 && keycode < TRACKED_KEYS)
		dt->keys[keycode] = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_data *dt)
{
	//printf("Key %d released\n", keycode);
	if (keycode == XK_Tab)
		toggle_setting(&dt->view->show_minimap);
	else if (keycode >= 0 && keycode < TRACKED_KEYS)
		dt->keys[keycode] = 0;
	return (EXIT_SUCCESS);
}

// Handle mouse press
int	mouse_press(int button, int x, int y, t_data *dt)
{
	(void)x;
	(void)y;
	//if (dt->view->show_welcome)
	//	return (1);
	//if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	//	mouse_zoom(button, dt);
	if (button == MOUSE_LEFT_BUTTON)
	{
		dt->mouse.lmb_is_pressed = 1;
		dt->mouse.lmb_press_count++;
		system("aplay sounds/shot.wav &");
		printf("🖱️  LMB is pressed! Total press count: %zu\n", dt->mouse.lmb_press_count);
	}
	return (EXIT_SUCCESS);
}

// Handle mouse release
int	mouse_release(int button, int x, int y, t_data *dt)
{
	(void)x;
	(void)y;
	//(void)button;
	//if (dt->view->show_welcome)
	//	return (1);
	if (button == MOUSE_LEFT_BUTTON)
	{
		dt->mouse.lmb_is_pressed = 0;

		//printf("LMB released!\n");
	}
	//if (button == MOUSE_THIRD_BUTTON)
	//	dt->mouse->rmb_is_pressed = FALSE;
	return (0);
}

// Handle mouse move
int	mouse_move(int x, int y, t_data *dt)
{
	//int	dx;
	//int dy;

	dt->mouse.prev_x = dt->mouse.x;
	dt->mouse.prev_y = dt->mouse.y;
	dt->mouse.x = x;
	dt->mouse.y = y;

	if (x > dt->mouse.prev_x)
		rotate_player(dt, MOUSE_SENS_ROTATE, -1);
	else if (x < dt->mouse.prev_x)
		rotate_player(dt, MOUSE_SENS_ROTATE, 1);
	if (ENABLE_VERTICAL_LOOK)
	{
		if (y > dt->mouse.prev_y)
			dt->view->screen_center -= (int)(MOUSE_SENS_ROTATE * 10);
		if (y < dt->mouse.prev_y)
			dt->view->screen_center += (int)(MOUSE_SENS_ROTATE * 10);
	}
	return (0);
}

void	setup_keyboard_hooks(t_data *dt)
{
	printf("Setting up keyboard hooks...");
	mlx_hook(dt->win_ptr, KeyPress, KeyPressMask, handle_keypress, dt);
	mlx_hook(dt->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease, dt);
	mlx_hook(dt->win_ptr, 17, 0, close_window, dt);
	mlx_do_key_autorepeatoff(dt->mlx_ptr);
	mlx_mouse_hide(dt->mlx_ptr, dt->win_ptr);
	printf(" Done!\n");
}


void	setup_mouse_hooks(t_data *dt)
{
	printf("Setting up mouse hooks...");
	mlx_hook(dt->win_ptr, 4, 1L << 2, mouse_press, dt);
	mlx_hook(dt->win_ptr, 5, 1L << 3, mouse_release, dt);
	mlx_hook(dt->win_ptr, 6, 1L << 6, mouse_move, dt);
	dt->mouse.lmb_is_pressed = 0;
	dt->mouse.rmb_is_pressed = 0;
	dt->mouse.prev_x = 0;
	dt->mouse.prev_y = 0;
	printf(" Done!\n");
}

//int	show_welcome_img(t_data *dt)
//{
//	if (dt->win_ptr == NULL)
//		return (1);
//	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->welcome_img, 0, 0);
//	return (0);
//}
