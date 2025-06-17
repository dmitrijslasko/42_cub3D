#include "cub3d.h"

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

void	setup_mouse_hooks(t_data *dt)
{
	printf("Setting up mouse hooks...");
	mlx_hook(dt->win_ptr, 4, 1L << 2, mouse_press, dt);
	mlx_hook(dt->win_ptr, 5, 1L << 3, mouse_release, dt);
	mlx_hook(dt->win_ptr, 6, 1L << 6, mouse_move, dt);
	dt->mouse.lmb_is_pressed = 0;
	dt->mouse.rmb_is_pressed = 0;
	set_mouse_to_screen_center(dt);
	dt->mouse.prev_y = 0;
	printf(" Done!\n");
}
