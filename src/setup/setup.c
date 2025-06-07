/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2025/06/06 23:52:08 by dmlasko          ###   ########.fr       */
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
	}
	return (0);
}

int	close_window(void)
{
	exit(0);
}

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

	player_pos = &(dt->player->pos);
	new_x = player_pos->x + dx;
	new_y = player_pos->y + dy;
	// puts("Setting player position...");
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
    double angle_rad = deg_to_rad(d_angle);
    double old_dir_x = dt->player->direction_vet.x;
    double old_dir_y = dt->player->direction_vet.y;

    // Rotate direction vector using rotation matrix
    dt->player->direction_vet.x = old_dir_x * cos(angle_rad) - old_dir_y * sin(angle_rad);
    dt->player->direction_vet.y = old_dir_x * sin(angle_rad) + old_dir_y * cos(angle_rad);

	// Optional: also rotate camera plane vector if you're using raycasting
    // (same matrix applied to plane_x, plane_y if they exist)

    // Update stored angle, keeping it between 0 and 359
    dt->player->direction_vet_deg += d_angle;
    if (dt->player->direction_vet_deg >= 360.0)
        dt->player->direction_vet_deg -= 360.0;
    else if (dt->player->direction_vet_deg < 0.0)
        dt->player->direction_vet_deg += 360.0;
}

int	handle_keypress(int key, t_data *dt)
{
	if (key == ESC_BUTTON)
	{
		keypress_exit(key, dt);
		close_window();
	}
	if (key == XK_w)
		set_player_position(dt, 0, -PLAYER_STEP);
	if (key == XK_a)
		set_player_position(dt, -PLAYER_STEP, 0);
	if (key == XK_s)
		set_player_position(dt, 0, PLAYER_STEP);
	if (key == XK_d)
		set_player_position(dt, PLAYER_STEP, 0);
	if (key == XK_Left)
		rotate_player(dt, -PLAYER_ROTATION_STEP);
	if (key == XK_Right)
		rotate_player(dt, PLAYER_ROTATION_STEP);
	return (0);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
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
