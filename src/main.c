#include "cub3d.h"

int	precalculate_trig_tables(t_data *dt)
{
	size_t	angle_index;

	printf("Precalculating sin and cos tables...");
	angle_index = 0;
	while (angle_index < PRECALCULATED_TRIG)
	{
    	dt->sin_table[angle_index] = sinf(angle_index * M_PI / 180);
		dt->cos_table[angle_index] = cosf(angle_index * M_PI / 180);
		angle_index++;
	}
	printf(" Done!\n");
	return (EXIT_SUCCESS);
}

void start_music(void)
{
    system("(while true; do aplay sounds/shot.wav; done) &");
    // or use ffplay if available
    // system("ffplay -nodisp -autoexit -loglevel quiet -loop 0 sounds/music.wav &");
}

void stop_music(void)
{
    system("killall aplay");
    // or killall ffplay
}

void	setup_view(t_data *dt)
{
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
	dt.player = get_player(dt);

	// Initialize ray array. Later the rays get updated in render function.
	initialize_rays(&dt);

	// VISUAL PART

	precalculate_trig_tables(&dt);
	// -------------------------------------------------------------------------
	setup_mlx_and_win(&dt);

	dt.img = protected_malloc(sizeof(t_img), dt);

	dt.view = protected_malloc(sizeof(t_view), dt);
	setup_view(&dt);
	setup_img(&dt);
	setup_keyboard_and_mouse_hooks(&dt);

	print_separator(1, DEF_SEPARATOR_CHAR);
	mlx_loop_hook(dt.mlx_ptr, &render_frame, &dt);
	mlx_loop(dt.mlx_ptr);

	return (EXIT_SUCCESS);
}
