
#include "cub3d.h"

// TODO DL: this can be replaced by an already existing function, bool	check_hit_wall(t_coor coord, t_map map)
int	map_position_is_walkable(t_data *dt, float *new_x, float *new_y)
{
	size_t min_x = (size_t)(*new_x - MIN_DISTANCE_TO_WALL);
	size_t max_x = (size_t)(*new_x + MIN_DISTANCE_TO_WALL);
	size_t min_y = (size_t)(*new_y - MIN_DISTANCE_TO_WALL);
	size_t max_y = (size_t)(*new_y + MIN_DISTANCE_TO_WALL);
	t_door *door;

	t_coor cell_ahead;
	cell_ahead = get_cell_ahead(dt);

	// NOTE DL: Should not be here probably!
	dt->player.cell_type_ahead = get_cell_type(&dt->map, &cell_ahead);
	if (dt->player.cell_type_ahead == '|')
		dt->view->show_door_open_message = 1;
	else
		dt->view->show_door_open_message = 0;
	// Check for out-of-bounds access
	if (max_x >= dt->map.map_size_cols || max_y >= dt->map.map_size_rows)
		return (0);

		// printf("%s\n", "Door not found!");

	// Check four corners of bounding box
	if (ft_strchr("1v", dt->map.map_data[min_y][min_x]) ||
		ft_strchr("1v", dt->map.map_data[min_y][max_x]) ||
		ft_strchr("1v", dt->map.map_data[max_y][min_x]) ||
		ft_strchr("1v", dt->map.map_data[max_y][max_x]))
	{
		return (0);
	}
	if (ft_strchr("|", dt->map.map_data[min_y][min_x]) ||
		ft_strchr("|", dt->map.map_data[min_y][max_x]) ||
		ft_strchr("|", dt->map.map_data[max_y][min_x]) ||
		ft_strchr("|", dt->map.map_data[max_y][max_x]))
	{
		door = find_door_at(dt, cell_ahead.x, cell_ahead.y);
		if (door && door->open_progress < DOOR_OPEN_VALUE)
			return (0);
	}
	return (1);
}

int	move_forward_backward(t_data *dt, int direction)
{
	t_x_y *player_pos;
	float new_x;
	float new_y;
	float speed;

	// Get current player position
	player_pos = &dt->player.pos;

	// Determine movement direction and adjust speed if needed
	speed = KEYBOARD_PLAYER_STEP_FORWARD;
	if (direction == -1)
		speed = KEYBOARD_PLAYER_STEP_BACKWARD;
	speed *= dt->player.move_speed_multiplier;

	// Calculate new player position
	new_x = player_pos->x + dt->player.direction_vector.x * speed * direction;
	new_y = player_pos->y + dt->player.direction_vector.y * speed * direction;

	if (map_position_is_walkable(dt, &new_x, &new_y))
	{
		player_pos->x = new_x;
		player_pos->y = new_y;
	}
	else if (map_position_is_walkable(dt, &new_x, &player_pos->y))
		player_pos->x = new_x;
	else if (map_position_is_walkable(dt, &player_pos->x, &new_y))
		player_pos->y = new_y;
	return (EXIT_SUCCESS);
}

// TODO DL: rewrite this to reuse what we have in forward/backward move
int move_sideways(t_data *dt, int is_to_the_right)
{
	t_x_y *player_pos;
	float new_x;
	float new_y;
	t_x_y	rotated_vector;

	player_pos = &(dt->player.pos);

	rotated_vector = rotate_vector(&dt->player.direction_vector, 90.0f * is_to_the_right);

	// Calculate new position
	new_x = player_pos->x + rotated_vector.x * KEYBOARD_PLAYER_STEP_SIDE * dt->player.move_speed_multiplier;
	new_y = player_pos->y + rotated_vector.y * KEYBOARD_PLAYER_STEP_SIDE * dt->player.move_speed_multiplier;

	if (map_position_is_walkable(dt, &new_x, &new_y))
	{
		player_pos->x = new_x;
		player_pos->y = new_y;
	}
	else if (map_position_is_walkable(dt, &new_x, &player_pos->y))
		player_pos->x = new_x;
	else if (map_position_is_walkable(dt, &player_pos->x, &new_y))
		player_pos->y = new_y;
	return (EXIT_SUCCESS);
}

