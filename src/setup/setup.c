#include "cub3d.h"

// TODO DL: this can be replaced by an already existing function, bool	check_hit_wall(t_coor coord, t_map map)
int	map_position_is_walkable(t_map *map, size_t row, size_t col)
{
	// printf("Checking r_c: %ld %ld = %c\n", row, col, map->map_data[row][col]);
	if (map->map_data[col][row] != '1')
		return (1);
	return (0);
}

int set_player_position(t_data *dt, float dx, float dy)
{
	t_x_y *player_pos;
	float new_x;
	float new_y;

	player_pos = &(dt->player->pos);

	new_x = player_pos->x + dx;
	new_y = player_pos->y + dy;

	if (map_position_is_walkable(dt->map, new_x + MIN_DISTANCE_TO_WALL, new_y + MIN_DISTANCE_TO_WALL) &&
		map_position_is_walkable(dt->map, new_x - MIN_DISTANCE_TO_WALL, new_y - MIN_DISTANCE_TO_WALL))
	{
		player_pos->x = new_x;
		player_pos->y = new_y;
	}
	return (EXIT_SUCCESS);
}

int move_forward_backward(t_data *dt, int direction)
{
	t_x_y *player_pos;
	float new_x;
	float new_y;
	float speed;

	player_pos = &(dt->player->pos);

	// Calculate new position
	speed = KEYBOARD_PLAYER_STEP_FORWARD;
	if (direction == -1)
		speed = KEYBOARD_PLAYER_STEP_BACKWARD;
	speed *= dt->player->move_speed_multiplier;

	new_x = player_pos->x + dt->player->direction_vector.x * speed * direction;
	new_y = player_pos->y + dt->player->direction_vector.y * speed * direction;

	// TODO DL: enable wall sliding
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
	float new_x;
	float new_y;
	t_x_y	rotated_vector;

	player_pos = &(dt->player->pos);

	rotated_vector = rotate_vector(*dt, dt->player->direction_vector, 90.0f * direction);

	// Calculate new position
	new_x = player_pos->x + rotated_vector.x * KEYBOARD_PLAYER_STEP_SIDE * dt->player->move_speed_multiplier;
	new_y = player_pos->y + rotated_vector.y * KEYBOARD_PLAYER_STEP_SIDE * dt->player->move_speed_multiplier;

	if (map_position_is_walkable(dt->map, new_x, new_y))
	{
		player_pos->x = new_x;
		player_pos->y = new_y;
	}
	//printf("New player position: %f %f\n", player_pos->x, player_pos->y);
	return (EXIT_SUCCESS);
}

//int	show_welcome_img(t_data *dt)
//{
//	if (dt->win_ptr == NULL)
//		return (1);
//	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->welcome_img, 0, 0);
//	return (0);
//}
