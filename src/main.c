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
	t_ray	*rays;

	if (dt->win_ptr == NULL)
		return (1);
	draw_background(dt->img, BLACK);
	draw_map(dt);
	draw_grid(dt->img, DEF_GRID_SIZE, DEF_GRID_COLOR);
	draw_player(dt);
	printf(TXT_GREEN "← 1-Direction (-1, 0)\n" TXT_RESET);
	//dt->player->direction_vet = get_values_x_y(-1, 0);
	printf("Player position (X, Y): %f %f\n", dt->player->pos.x, dt->player->pos.y);
	printf("Player orientation (deg): %f\n", dt->player->direction_vector_deg);
	printf("Player direction vector X Y: %f %f\n", dt->player->direction_vet.x, dt->player->direction_vet.y);
	rays = calculate_ray(*dt, dt->player->direction_vet);
	free(rays);
	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->mlx_img, 0, 0);
	add_ui(dt);
	return (0);
}

// TODO: DL: rename curr_col to curr_row BECAUSE IT IS A ROW!
t_map	*load_dummy_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);

	map->map_size_rows = strlen(DUMMY_MAP_TOP);
	map->map_size_cols = strlen(DUMMY_MAP_TOP);

	map->map_data = malloc((map->map_size_cols + 1) * sizeof(char *));
	if (!map->map_data)
		return (NULL);
	map->map_data[map->map_size_cols] = NULL;  // null-terminate row array

	for (size_t curr_col = 0; curr_col < map->map_size_cols; curr_col++)
	{
		map->map_data[curr_col] = malloc((map->map_size_rows + 1) * sizeof(char));  // +1 for '\0'
		if (!map->map_data[curr_col])
			return (NULL); // ideally free previously malloc'd rows
		if (curr_col == 0 || curr_col == map->map_size_rows - 1)
			strcpy(map->map_data[curr_col], DUMMY_MAP_TOP);
		else if (curr_col == 4)
			strcpy(map->map_data[curr_col], DUMMY_MAP_PLAYER);
		else
			strcpy(map->map_data[curr_col], DUMMY_MAP_MID);
	}
	return (map);
}


void	print_map(t_map *map)
{
	if (!map || !map->map_data[0] || !map->map_data[0][0])
		return ;
	for(size_t y = 0; y < map->map_size_cols; y++)
	{
		for (size_t x = 0; x < map->map_size_rows; x++)
			printf("%c ", map->map_data[y][x]);
		printf("\n");
	}
}

void	initialize_player_position(t_player *player,t_map *map)
{
	for (size_t x = 0; x < map->map_size_rows; x++)
	{
		for(size_t y = 0; y < map->map_size_cols; y++)
		{
			if (map->map_data[y][x] == 'N')
			{
				player->pos.x = x + 0.5;
				player->pos.y = y + 0.5;
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
