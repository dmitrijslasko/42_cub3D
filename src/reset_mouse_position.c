#include "cub3d.h"

# define CENTER_TOLERANCE	25

int	reset_mouse_position(t_data *dt)
{
	int dx = dt->mouse.x - WINDOW_W / 2;
	int dy = dt->mouse.y - WINDOW_H / 2;

	if (dt->mouse.suppress_mouse_frames > 0)
	{
		dt->mouse.suppress_mouse_frames--;
		return (EXIT_SUCCESS);
	}

	if (abs(dx) > CENTER_TOLERANCE || abs(dy) > CENTER_TOLERANCE)
	{
		int new_x = dt->mouse.x;
		int new_y = dt->mouse.y;

		if (abs(dx) > CENTER_TOLERANCE)
				new_x = WINDOW_W / 2 + sign(dx) * CENTER_TOLERANCE;
		if (abs(dy) > CENTER_TOLERANCE)
				new_y = WINDOW_H / 2 + sign(dy) * CENTER_TOLERANCE;

		dt->mouse.suppress_mouse_frames = 2;
		mlx_mouse_move(dt->mlx_ptr, dt->win_ptr, new_x, new_y);
	}
	//mlx_mouse_move(dt->mlx_ptr, dt->win_ptr, WINDOW_W / 2, dt->mouse.y);

	return (EXIT_SUCCESS);
}
