/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2025/06/08 20:26:24 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	keypress_exit(int key, t_data *dt)
{
	if (key == ESC_BUTTON)
	{
		printf("ESC button pressed, closing the window...\n");
		mlx_destroy_window(dt->mlx_ptr, dt->win_ptr);
		dt->win_ptr = NULL;
		free(dt->rays);
	}
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

// Rotate both direction and camera plane
double	deg_to_rad(double angle)
{
	return (angle * M_PI / 180.0);
}
void rotate_player(t_data *dt, double d_angle)
{
    double angle_rad = deg_to_rad(d_angle * PLAYER_ROTATION_STEP);
    double old_dir_x = dt->player->direction_vector.x;
    double old_dir_y = dt->player->direction_vector.y;

    // Rotate direction vector using rotation matrix
    dt->player->direction_vector.x = old_dir_x * cos(angle_rad) - old_dir_y * sin(angle_rad);
    dt->player->direction_vector.y = old_dir_x * sin(angle_rad) + old_dir_y * cos(angle_rad);

	// Optional: also rotate camera plane vector if you're using raycasting
    // (same matrix applied to plane_x, plane_y if they exist)

    // Update stored angle, keeping it between 0 and 359
    dt->player->direction_vector_deg += d_angle;
    if (dt->player->direction_vector_deg >= 360.0)
        dt->player->direction_vector_deg -= 360.0;
    else if (dt->player->direction_vector_deg < 0.0)
        dt->player->direction_vector_deg += 360.0;
}

int move_forward_backward(t_data *dt, int direction)
{
	t_x_y *player_pos;
	double new_x;
	double new_y;

	player_pos = &(dt->player->pos);

	printf("Setting player position...\n");
	printf("Player orientation vector: %f %f\n",
		dt->player->direction_vector.x,
		dt->player->direction_vector.y);

	// Calculate new position
	new_x = player_pos->x + dt->player->direction_vector.x * PLAYER_STEP * direction;
	new_y = player_pos->y + dt->player->direction_vector.y * PLAYER_STEP * direction;

	if (map_position_is_walkable(dt->map, new_x, new_y))
	{
		player_pos->x = new_x;
		player_pos->y = new_y;
	}

	printf("New player position: %f %f\n", player_pos->x, player_pos->y);

	return (EXIT_SUCCESS);
}

int move_sideways(t_data *dt, int direction)
{
	t_x_y *player_pos;
	double new_x;
	double new_y;
	t_x_y	rotated_vector;

	player_pos = &(dt->player->pos);

	printf("Setting player position...\n");
	printf("Player orientation vector: %f %f\n",
		dt->player->direction_vector.x,
		dt->player->direction_vector.y);

	rotated_vector = rotate_vector(dt->player->direction_vector, 90.0f * direction);
	// Calculate new position
	new_x = player_pos->x + rotated_vector.x * PLAYER_STEP;
	new_y = player_pos->y + rotated_vector.y * PLAYER_STEP;

	if (map_position_is_walkable(dt->map, new_x, new_y))
	{
		player_pos->x = new_x;
		player_pos->y = new_y;
	}

	printf("New player position: %f %f\n", player_pos->x, player_pos->y);

	return (EXIT_SUCCESS);
}

int	handle_keypress(int keycode, t_data *dt)
{
	if (keycode == ESC_BUTTON)
	{
		keypress_exit(keycode, dt);
		close_window();
	}
	printf("Pressed keycode: %d\n", keycode);
	if (keycode >= 0 && keycode < TRACKED_KEYS)
		dt->keys[keycode] = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_data *dt)
{
	if (keycode >= 0 && keycode < TRACKED_KEYS)
		dt->keys[keycode] = 0;
	return (0);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	//mlx_hook(data->win_ptr, 4, 1L << 2, mouse_press, data);
	//mlx_hook(data->win_ptr, 5, 1L << 3, mouse_release, data);
	//mlx_hook(data->win_ptr, 6, 1L << 6, mouse_move, data);
}

//int	show_welcome_img(t_data *dt)
//{
//	if (dt->win_ptr == NULL)
//		return (1);
//	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->welcome_img, 0, 0);
//	return (0);
//}

void	setup_mouse(t_mouse *mouse)
{
	mouse->lmb_is_pressed = 0;
	mouse->rmb_is_pressed = 0;
}
