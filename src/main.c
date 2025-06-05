/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:24:06 by dmlasko           #+#    #+#             */
/*   Updated: 2025/06/05 18:16:33 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_coor_info(t_data *dt)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 15;
	mlx = dt->mlx_ptr;
	win = dt->win_ptr;
	mlx_string_put(mlx, win, 10, y, UI_CLR_1, "Player position: ");
	mlx_string_put(mlx, win, 150, y, UI_CLR_1, "X Y");
	mlx_string_put(mlx, win, 10, y += 10, UI_CLR_1, "Player orientation: ");
	mlx_string_put(mlx, win, 150, y, UI_CLR_1, "deg");
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
	draw_grid(dt->img, DEF_GRID_SIZE, DEF_GRID_COLOR);
	draw_map(dt);
	draw_player(dt);
	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->mlx_img, 0, 0);
	add_ui(dt);
	return (0);
}

t_map	*load_dummy_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);

	map->map_size_rows = 8;
	map->map_size_cols = 8;

	map->map = malloc((map->map_size_rows + 1) * sizeof(char *));
	if (!map->map)
		return (NULL);
	map->map[map->map_size_rows] = NULL;

	char top[8] = "11111111";
	char middle[8] = "10000001";
	char position[8] = "100000N1";

	for (size_t i = 0; i< map->map_size_rows; i++)
	{
		map->map[i] = malloc((map->map_size_cols + 1) * sizeof(char));
		if (!map->map[i])
			return (NULL);
		if (i == 0 || i == map->map_size_cols -1)
			strcpy(map->map[i], top);
		else if (i == 4)
			strcpy(map->map[i], position);
		else
			strcpy(map->map[i], middle);
	}
	return (map);
}

void	print_map(t_map *map)
{
	if (!map || !map->map[0] || !map->map[0][0])
		return ;
	for (size_t i = 0; i < map->map_size_rows; i++)
	{
		for(size_t j = 0; j < map->map_size_cols; j++)
		{
			printf("%c ", map->map[i][j]);
		}
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_data	dt;

	(void)argc;
	(void)argv;
	printf("Hello cub3d!\n");
	setup_mlx_and_win(&dt);
	dt.map = load_dummy_map();
	print_map(dt.map);
	// //dt.needs_update = 1;
	// dt.img = protected_malloc(sizeof(t_img), &dt);
	// dt.player = protected_malloc(sizeof(t_player), &dt);
	// dt.player->player_pos_x = WINDOW_W / 2;
	// dt.player->player_pos_y = WINDOW_H / 2;
	// dt.player->direction_vector_deg = 0;
	// //setup_view(&dt);
	// setup_img(&dt);
	// setup_hooks(&dt);
	// //setup_mouse(&dt.mouse);
	// mlx_loop_hook(dt.mlx_ptr, &render, &dt);
	// mlx_loop(dt.mlx_ptr);
	return (0);
}
