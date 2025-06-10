/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2025/06/10 16:48:25 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int	map_position_is_walkable(t_map *map, size_t row, size_t col)
{
	// printf("Checking r_c: %ld %ld = %c\n", row, col, map->map_data[row][col]);
	if (map->map_data[col][row] != '1')
		return (1);
	return (0);
}

int set_player_position(t_data *dt, double dx, double dy)
{
	t_x_y *player_pos;
	double new_x;
	double new_y;

	//printf("Setting player position...\n");
	player_pos = &(dt->player->pos);
	new_x = player_pos->x + dx;
	new_y = player_pos->y + dy;

	if (map_position_is_walkable(dt->map, new_x + MIN_DISTANCE_TO_WALL, new_y + MIN_DISTANCE_TO_WALL) &&
		map_position_is_walkable(dt->map, new_x - MIN_DISTANCE_TO_WALL, new_y - MIN_DISTANCE_TO_WALL))
	{
		player_pos->x = new_x;
		player_pos->y = new_y;
	}
	return (0);
}

int move_forward_backward(t_data *dt, int direction)
{
	t_x_y *player_pos;
	double new_x;
	double new_y;
	double speed;

	player_pos = &(dt->player->pos);

	//printf("Setting player position...\n");
	//printf("Player orientation vector: %f %f\n",
	//	dt->player->direction_vector.x,
	//	dt->player->direction_vector.y);

	// Calculate new position
	speed = KEYBOARD_PLAYER_STEP_FORWARD;
	if (direction == -1)
		speed = KEYBOARD_PLAYER_STEP_BACKWARD;
	new_x = player_pos->x + dt->player->direction_vector.x * speed * direction;
	new_y = player_pos->y + dt->player->direction_vector.y * speed * direction;

	// TODO DL: allow wall sliding
	if (map_position_is_walkable(dt->map, new_x, new_y))
	{
		player_pos->x = new_x;
		player_pos->y = new_y;
	}

	//printf("New player position: %f %f\n", player_pos->x, player_pos->y);
	return (EXIT_SUCCESS);
}

int move_sideways(t_data *dt, int direction)
{
	t_x_y *player_pos;
	double new_x;
	double new_y;
	t_x_y	rotated_vector;

	player_pos = &(dt->player->pos);

	//printf("Setting player position...\n");
	//printf("Player orientation vector: %f %f\n",
	//	dt->player->direction_vector.x,
	//	dt->player->direction_vector.y);

	rotated_vector = rotate_vector(*dt, dt->player->direction_vector, 90.0f * direction);

	// Calculate new position
	new_x = player_pos->x + rotated_vector.x * KEYBOARD_PLAYER_STEP_SIDE;
	new_y = player_pos->y + rotated_vector.y * KEYBOARD_PLAYER_STEP_SIDE;

	if (map_position_is_walkable(dt->map, new_x, new_y))
	{
		player_pos->x = new_x;
		player_pos->y = new_y;
	}

	//printf("New player position: %f %f\n", player_pos->x, player_pos->y);

	return (EXIT_SUCCESS);
}

int	handle_keypress(int keycode, t_data *dt)
{
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
		toggle(&dt->view->show_minimap);
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
	dt->mouse.prev_x = dt->mouse.x;
	dt->mouse.prev_y = dt->mouse.y;
	dt->mouse.x = x;
	dt->mouse.y = y;

	if (x > dt->mouse.prev_x)
	{
		rotate_player(dt, MOUSE_SENS_ROTATE, -1);
	}
	else if (x < dt->mouse.prev_x)
	{
		rotate_player(dt, MOUSE_SENS_ROTATE, 1);
	}
	return (0);
}


void	setup_keyboard_and_mouse_hooks(t_data *dt)
{
	printf("Setting up keyboard and mouse hooks...");
	mlx_hook(dt->win_ptr, KeyPress, KeyPressMask, handle_keypress, dt);
	mlx_hook(dt->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease, dt);
	mlx_hook(dt->win_ptr, 17, 0, close_window, dt);
	mlx_do_key_autorepeatoff(dt->mlx_ptr);

	mlx_hook(dt->win_ptr, 4, 1L << 2, mouse_press, dt);
	mlx_hook(dt->win_ptr, 5, 1L << 3, mouse_release, dt);
	mlx_mouse_hide(dt->mlx_ptr, dt->win_ptr);
	mlx_hook(dt->win_ptr, 6, 1L << 6, mouse_move, dt);
	dt->mouse.lmb_is_pressed = 0;
	dt->mouse.rmb_is_pressed = 0;
	printf(" Done!\n");
}

//int	show_welcome_img(t_data *dt)
//{
//	if (dt->win_ptr == NULL)
//		return (1);
//	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->welcome_img, 0, 0);
//	return (0);
//}
