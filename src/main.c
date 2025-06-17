#include "cub3d.h"

void	setup_view(t_data *dt)
{
	dt->view->screen_center = WINDOW_H / 2;
	dt->view->show_minimap = 0;
}

int	main(int argc, char **argv)
{
	t_data	dt;

	(void)argc;
	(void)argv;

	// Load dummy map
	dt.map = load_dummy_map();
	print_level_map(dt.map);

	size_t i = 0;
	while (i < TRACKED_KEYS)
	{
		dt.keys[i] = 0;
		i++;
	}
	init_player(&dt);

	// Initialize ray array. Later the rays get updated in render function.
	initialize_rays(&dt);

	// VISUAL PART
	// -------------------------------------------------------------------------
	precalculate_trig_tables(&dt);

	setup_mlx_and_win(&dt);

	dt.img = protected_malloc(sizeof(t_img), dt);
	dt.view = protected_malloc(sizeof(t_view), dt);

	load_textures(&dt);
	load_sprites(&dt);

	setup_view(&dt);
	setup_img(&dt);
	setup_keyboard_hooks(&dt);
	setup_mouse_hooks(&dt);

	print_separator_default();
	mlx_loop_hook(dt.mlx_ptr, &render_frame, &dt);
	mlx_loop(dt.mlx_ptr);

	return (EXIT_SUCCESS);
}

