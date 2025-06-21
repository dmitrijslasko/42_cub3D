#include "cub3d.h"

void	setup_view(t_data *dt)
{
	dt->view->screen_center = WINDOW_H / 2;
	dt->view->show_minimap = 0;
}

int	main(int argc, char **argv)
{
	t_data	dt;

	if (argc != 2)
		return (error_message("Try again! Format ./cub3D <name_file>.cub\n", 1));

	// Load dummy map
	if (parsing(&dt, argv[1]))
		exit(1);
	// dt.map = load_dummy_map();
	print_level_map(&dt.map);

	size_t i = 0;
	while (i < TRACKED_KEYS)
	{
		dt.keys[i] = 0;
		i++;
	}
	// init_player(&dt);

	// Initialize ray array. Later the rays get updated in render function.
	initialize_rays(&dt);

	// VISUAL PART
	// -------------------------------------------------------------------------
	precalculate_trig_tables(&dt);

	setup_mlx_and_win(&dt);

	dt.scene_img = protected_malloc(sizeof(t_img), dt);
	dt.minimap = protected_malloc(sizeof(t_img), dt);
	dt.minimap_base = protected_malloc(sizeof(t_img), dt);
	dt.view = protected_malloc(sizeof(t_view), dt);

	setup_img(&dt, dt.minimap_base, dt.map.map_size_cols * MINIMAP_GRID_SIZE, dt.map.map_size_rows * MINIMAP_GRID_SIZE);
	draw_minimap_map(&dt);

	load_textures(&dt);
	// load_sprites(&dt);

	setup_view(&dt);

	setup_img(&dt, dt.scene_img, WINDOW_W, WINDOW_H);
	setup_img(&dt, dt.minimap, MINIMAP_SIZE, MINIMAP_SIZE);

	setup_keyboard_hooks(&dt);
	if (ENABLE_MOUSE)
		setup_mouse_hooks(&dt);

	print_separator_default();

	mlx_loop_hook(dt.mlx_ptr, &render_frame, &dt);
	mlx_loop(dt.mlx_ptr);

	return (EXIT_SUCCESS);
}

