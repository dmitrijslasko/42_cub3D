#include "cub3d.h"

int	precalculate_sin_table(t_data *dt)
{
	size_t	angle;

	printf("Precalculating sin table...");
	angle = 0;
	while (angle < 360)
	{
    	dt->sin_table[angle] = sinf(angle * M_PI / 180);
		angle++;
	}
	printf(" Done!\n");
	return (EXIT_SUCCESS);
}

int	precalculate_cos_table(t_data *dt)
{
	size_t	angle;

	printf("Precalculating cos table...");
	angle = 0;
	while (angle < 360)
	{
    	dt->cos_table[angle] = cosf(angle * M_PI / 180);
		angle++;
	}
	printf(" Done!\n");
	return (EXIT_SUCCESS);
}

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

	precalculate_sin_table(&dt);
	precalculate_cos_table(&dt);
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
