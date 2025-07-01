/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_debug_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:33:06 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:33:07 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_cell_info(t_data *dt, void *mlx, void *win, int *y)
{
	char	buffer[32];
	char	str[2];
	size_t	i;
	int		(*f)(void*, void*, int, int, int, char*);

	f = mlx_string_put;
	if (CASTED_RAYS_COUNT == 1)
		i = 0;
	else
		i = CASTED_RAYS_COUNT / 2;
	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[i].wall_hit.x);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL_2, UI_CLR_1, "Cell hit point X:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[i].wall_hit.y);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1, "Cell hit point Y:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[i].percentage_of_image);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL_2, UI_CLR_1, "Percentage of image:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	str[0] = dt->player.cell_type_ahead;
	str[1] = '\0';
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL_2, UI_CLR_1, "Cell ahead:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, str);
}

void	print_door_hit_stats(t_data *dt, void *mlx, void *win, int *y)
{
	size_t	i;
	char	buffer[32];
	int		(*f)(void*, void*, int, int, int, char*);

	f = mlx_string_put;
	if (CASTED_RAYS_COUNT == 1)
		i = 0;
	else
		i = CASTED_RAYS_COUNT / 2;
	if (dt->door_count > 0 && dt->rays[i].door_hit_coor.x)
	{
		snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[i].door_hit_coor.x);
		f(mlx, win, DBG_1_X, *y += DBG_MN_NL_2, UI_CLR_1, "Door hit point X:");
		f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
		snprintf(buffer, sizeof(buffer), "%.2f", dt->rays[i].door_hit_coor.y);
		f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1, "Door hit point Y:");
		f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
		f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_1, "Door ID:");
		f(mlx, win, DBG_2_X, *y, UI_CLR_1, ft_itoa(dt->rays[i].door->id));
	}
}

void	print_time_stats(t_data *dt, void *mlx, void *win, int *y)
{
	char	buffer[32];
	int		(*f)(void*, void*, int, int, int, char*);

	f = mlx_string_put;
	snprintf(buffer, sizeof(buffer), "%ld", dt->last_time);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL_2, UI_CLR_1, "Current time:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	snprintf(buffer, sizeof(buffer), "%ld",
		(dt->last_time - dt->start_time) / 1000);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL_2, UI_CLR_1, "Elapsed time (s):");
	f(mlx, win, DBG_2_X, *y, UI_CLR_1, buffer);
	f(mlx, win, DBG_1_X, *y += DBG_MN_NL, UI_CLR_2, "Frames drawn:");
	f(mlx, win, DBG_2_X, *y, UI_CLR_2, ft_itoa(dt->frames_drawn));
}

void	show_debug_info(t_data *dt)
{
	int		y;
	void	*mlx;
	void	*win;
	size_t	i;
	int		(*f)(void*, void*, int, int, int, char*);

	f = mlx_string_put;
	if (CASTED_RAYS_COUNT == 1)
		i = 0;
	else
		i = CASTED_RAYS_COUNT / 2;
	y = DBG_FIELD_OFFST_Y;
	mlx = dt->mlx_ptr;
	win = dt->win_ptr;
	print_window_info(dt, mlx, win, &y);
	print_player_position(dt, mlx, win, &y);
	print_obstacle_info(dt, mlx, win, &y);
	print_cell_info(dt, mlx, win, &y);
	print_door_hit_stats(dt, mlx, win, &y);
	f(mlx, win, DBG_1_X, y += DBG_MN_NL_2, UI_CLR_1, "LMB presses:");
	f(mlx, win, DBG_2_X, y, UI_CLR_1, ft_itoa(dt->mouse.lmb_press_count));
	print_time_stats(dt, mlx, win, &y);
}
