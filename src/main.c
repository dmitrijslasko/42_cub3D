/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:24:06 by dmlasko           #+#    #+#             */
/*   Updated: 2025/06/06 18:51:49 by dmlasko          ###   ########.fr       */
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
	draw_map(dt);
	draw_grid(dt->img, DEF_GRID_SIZE, DEF_GRID_COLOR);
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

	map->map_size_rows = strlen(DUMMY_MAP_TOP);
	map->map_size_cols = strlen(DUMMY_MAP_TOP);

	map->map_data = malloc((map->map_size_rows + 1) * sizeof(char *));
	if (!map->map_data)
		return (NULL);
	map->map_data[map->map_size_rows] = NULL;  // null-terminate row array

	for (size_t i = 0; i < map->map_size_rows; i++)
	{
		map->map_data[i] = malloc((map->map_size_cols + 1) * sizeof(char));  // +1 for '\0'
		if (!map->map_data[i])
			return (NULL); // ideally free previously malloc'd rows

		if (i == 0 || i == map->map_size_rows - 1)
			strcpy(map->map_data[i], DUMMY_MAP_TOP);
		else if (i == 4)
			strcpy(map->map_data[i], DUMMY_MAP_PLAYER);
		else
			strcpy(map->map_data[i], DUMMY_MAP_MID);
	}
	return (map);
}


void	print_map(t_map *map)
{
	if (!map || !map->map_data[0] || !map->map_data[0][0])
		return ;
	for (size_t i = 0; i < map->map_size_rows; i++)
	{
		for(size_t j = 0; j < map->map_size_cols; j++)
			printf("%c ", map->map_data[i][j]);
		printf("\n");
	}
}

void	initialize_player_position(t_player *player,t_map *map)
{
	for (size_t curr_row = 0; curr_row < map->map_size_rows; curr_row++)
	{
		for(size_t curr_col = 0; curr_col < map->map_size_cols; curr_col++)
		{
			if (map->map_data[curr_row][curr_col] == 'N')
			{
				player->pos.x = curr_col + 0.5;
				player->pos.y = curr_row + 0.5;
				player->direction_vet.x = -1;
				player->direction_vet.y = 0;
			}
		}
	}
}

t_player *get_player(t_data dt)
{
	t_player	*player;

	player = protected_malloc(sizeof(t_player), dt);
	initialize_player_position(player, dt.map);
	return (player);
}

int	main(int argc, char **argv)
{
	t_data	dt;

	(void)argc;
	(void)argv;
	dt.map = load_dummy_map();
	print_map(dt.map);
	dt.player = get_player(dt);
	// initialize_player_position(dt.player, dt.map); // talk about this option!
	create_array_ray(dt);

	// VISUAL PART
	 setup_mlx_and_win(&dt);
	 dt.img = protected_malloc(sizeof(t_img), dt);
	 dt.player->direction_vector_deg = 0;
	 //setup_view(&dt);
	 setup_img(&dt);
	 setup_hooks(&dt);
	 //setup_mouse(&dt.mouse);
	 mlx_loop_hook(dt.mlx_ptr, &render, &dt);
	 mlx_loop(dt.mlx_ptr);
	return (0);
}
