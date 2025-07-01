/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keyboard_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:04:26 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:04:27 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	keypress_exit(t_data *dt)
{
	printf("ESC button pressed, closing the window...");
	free_dt(dt);
	printf(" Done!\n");
	exit(0);
	return (EXIT_SUCCESS);
}

int	handle_keypress(int keycode, t_data *dt)
{
	if (keycode == ESC_BUTTON)
		keypress_exit(dt);
	if (keycode == XK_e)
		printf("Door triggered!\n");
	else if (keycode >= 0 && keycode < TRACKED_KEYS)
		dt->keys[keycode] = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_data *dt)
{
	if (keycode == XK_Tab)
		toggle_setting(&dt->view->show_minimap);
	if (keycode == XK_F12)
		toggle_setting(&dt->view->show_debug_info);
	else if (keycode >= 0 && keycode < TRACKED_KEYS)
		dt->keys[keycode] = 0;
	dt->has_changed = 1;
	return (EXIT_SUCCESS);
}

void	setup_keyboard_hooks(t_data *dt)
{
	printf("Setting up keyboard hooks...");
	mlx_hook(dt->win_ptr, KeyPress, KeyPressMask, handle_keypress, dt);
	mlx_hook(dt->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease, dt);
	mlx_hook(dt->win_ptr, 17, 0, keypress_exit, dt);
	mlx_do_key_autorepeatoff(dt->mlx_ptr);
	if (BONUS && ENABLE_MOUSE)
		mlx_mouse_hide(dt->mlx_ptr, dt->win_ptr);
	printf(" Done!\n");
}
