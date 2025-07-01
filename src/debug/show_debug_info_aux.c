/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_debug_info_aux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:33:03 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:33:04 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_window_info(t_data *dt, void *mlx, void *win, int *y)
{
	int		(*f)(void*, void*, int, int, int, char*);

	(void) dt;
	f = mlx_string_put;
	f(mlx, win, DBG_1_X, *y, UI_CLR_1, "Frames per second (FPS):");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, ft_itoa(FPS));
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1, "Window W:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, ft_itoa(WINDOW_W));
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1, "Window H:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, ft_itoa(WINDOW_H));
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_2, "Casted ra*ys:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_2, ft_itoa(CASTED_RAYS_COUNT));
}

void	print_player_position(t_data *dt, void *mlx, void *win, int *y)
{
	char	buffer[32];
	int		(*f)(void*, void*, int, int, int, char*);

	f = mlx_string_put;
	snprintf(buffer, sizeof(buffer), "%.2f", dt->player.pos.x);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL_2, UI_CLR_1, "Player position X:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	snprintf(buffer, sizeof(buffer), "%.2f", dt->player.pos.y);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1, "Player position Y:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	snprintf(buffer, sizeof(buffer), "%.2f", dt->player.direction_vector_deg);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1,
		"Player orientation (deg):");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
}

void	print_obstacle_info(t_data *dt, void *mlx, void *win, int *y)
{
	char	buffer[32];
	size_t	i;
	int		(*f)(void*, void*, int, int, int, char*);

	f = mlx_string_put;
	if (CASTED_RAYS_COUNT == 1)
		i = 0;
	else
		i = CASTED_RAYS_COUNT / 2;
	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[i].distance_to_wall);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL_2, UI_CLR_1, "Distance to obstacle:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1, "Obstacle type:");
	if (dt->rays[i].cell_type == DOOR_VERTICAL)
		f(mlx, win, DBG_2_X, *y, UI_CLR_1, "DOOR");
	else if (dt->rays[i].cell_type == SOLID_WALL)
		f(mlx, win, DBG_2_X, *y, UI_CLR_1, "WALL");
	else if (dt->rays[i].cell_type == THIN_WALL_VERTICAL)
		f(mlx, win, DBG_2_X, *y, UI_CLR_1, "THIN (V)");
	else
		f(mlx, win, DBG_2_X, *y, UI_CLR_1, "N/D");
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1, "Wall type:");
	if (dt->rays[i].cell_type == SOLID_WALL)
		f(mlx, win, DBG_2_X, *y, UI_CLR_1, ft_itoa(dt->rays[i].wall_type));
}
