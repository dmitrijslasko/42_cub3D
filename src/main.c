#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	dt;

	(void)argc;
	(void)argv;

	// Load dummy map
	dt.map = load_dummy_map();
	print_map(dt.map);

	size_t i = 0;
	while (i < TRACKED_KEYS)
	{
		dt.keys[i] = 0;
		i++;
	}
	dt.player = get_player(dt);

	// Initialize ray array. Later the rays get updated in render function.
	initialize_rays(&dt);

	// VISUAL PART
	// -------------------------------------------------------------------------
	setup_mlx_and_win(&dt);
	dt.img = protected_malloc(sizeof(t_img), dt);

	//setup_view(&dt);
	setup_img(&dt);
	setup_hooks(&dt);
	//setup_mouse(&dt.mouse);

	mlx_loop_hook(dt.mlx_ptr, &render_frame, &dt);
	mlx_loop(dt.mlx_ptr);
	return (0);
}
