#include "cub3d.h"
#include "sound.h"

int	main(int argc, char **argv)
{
	t_data	dt;

	if (argc != 2)
		return (error_message("Try again! Format ./cub3D <name_file>.cub\n", 1));

	if (parsing(&dt, argv[1]))
	{
		free_dt(&dt);
		return (EXIT_FAILURE);
	}

	print_level_map(&dt.map);

	// Initialize ray array. Later the rays get updated in render function.
	init_rays(&dt);
	init_keys(&dt);

	precalculate_trig_tables(&dt);

	// VISUAL PART
	// -------------------------------------------------------------------------
	dt.start_time = get_current_time_in_ms();
	setup_mlx_and_win(&dt);

	dt.scene_img = protected_malloc(sizeof(t_img), &dt);
	dt.minimap = protected_malloc(sizeof(t_img), &dt);
	dt.minimap_base_img = protected_malloc(sizeof(t_img), &dt);
	dt.view = protected_malloc(sizeof(t_view), &dt);
	dt.last_time = 0;

	load_textures(&dt);
	load_sky_image(&dt);
	load_messages(&dt);
	init_doors(&dt);
	load_sprites(&dt);

	setup_view(&dt);

	draw_minimap_base_img(&dt);
	setup_img(&dt, dt.scene_img, WINDOW_W, WINDOW_H);
	setup_img(&dt, dt.minimap, MINIMAP_SIZE, MINIMAP_SIZE);

	setup_keyboard_hooks(&dt);
	if (ENABLE_MOUSE)
		setup_mouse_hooks(&dt);

	dt.background_music = init_audio();
	print_separator(3, DEF_SEPARATOR_CHAR);
	mlx_loop_hook(dt.mlx_ptr, &render_frame, &dt);
	mlx_loop(dt.mlx_ptr);

	free_dt(&dt);
	return (EXIT_SUCCESS);
}

