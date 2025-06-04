/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:24:06 by dmlasko           #+#    #+#             */
/*   Updated: 2025/06/04 18:58:06 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_coor_info(t_data *dt)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 10;
	mlx = dt->mlx_ptr;
	win = dt->win_ptr;
	mlx_string_put(mlx, win, 10, y, UI_CLR_1, "Player position: ");
	mlx_string_put(mlx, win, 10, y += 10, UI_CLR_1, "Player orientation: ");
}

void	add_ui(t_data *dt)
{
		add_coor_info(dt);
}

int render(void *param)
{
	t_data *dt = (t_data *)param;

	if (dt->win_ptr == NULL)
		return (1);
	draw_background(dt->img, BLACK);
	draw_map(dt);
	draw_player(dt);
	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->mlx_img, 0, 0);
	add_ui(dt);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	dt;

	(void)argc;
	(void)argv;
	printf("Hello cub3d!\n");
	setup_mlx_and_win(&dt);
	dt.img = protected_malloc(sizeof(t_img), &dt);
	dt.player = protected_malloc(sizeof(t_player), &dt);
	dt.player->player_pos_x = WINDOW_W / 2;
	dt.player->player_pos_y = WINDOW_H / 2;
	//setup_view(&dt);
	setup_img(&dt);
	setup_hooks(&dt);
	//setup_mouse(&dt.mouse);
	mlx_loop_hook(dt.mlx_ptr, &render, &dt);
	mlx_loop(dt.mlx_ptr);
	return (0);
}
