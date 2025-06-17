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
