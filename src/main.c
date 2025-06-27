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

	if (parsing(&dt, argv[1]))
	//	printf(TXT_RED "%s failed\n" TXT_RESET, argv[1]);
	//else
	//	printf(TXT_GREEN "%s successed\n" TXT_RESET, argv[1]);
		exit(1);

	// Load dummy map
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
	init_rays(&dt);

	// VISUAL PART
	// -------------------------------------------------------------------------
	precalculate_trig_tables(&dt);

	setup_mlx_and_win(&dt);

	dt.scene_img = protected_malloc(sizeof(t_img), &dt);
	dt.minimap = protected_malloc(sizeof(t_img), &dt);
	dt.minimap_base_img = protected_malloc(sizeof(t_img), &dt);
	dt.view = protected_malloc(sizeof(t_view), &dt);
	dt.last_time = 0;
	dt.view->door_open = 2.0f;

	load_textures(&dt);
	load_sprites(&dt);
	init_doors(&dt);

	// minimap base image
	setup_img(&dt, dt.minimap_base_img, dt.map.map_size_cols * MINIMAP_GRID_SIZE, dt.map.map_size_rows * MINIMAP_GRID_SIZE);
	draw_minimap_map(&dt);
	printf("Loading sky image...\n");

	dt.sky_image = malloc(sizeof(t_img));
	if (!dt.sky_image)
	{
		fprintf(stderr, "Failed to allocate memory for sky image\n");
		exit(1);
	}

	int w, h;
	dt.sky_image->mlx_img = mlx_xpm_file_to_image(dt.mlx_ptr, "./textures/sky2.xpm", &w, &h);
	if (!dt.sky_image->mlx_img)
	{
		fprintf(stderr, "Failed to load sky texture\n");
		exit(1);
	}

	dt.sky_image->width = w;
	dt.sky_image->height = h;
	dt.sky_image->addr = mlx_get_data_addr(dt.sky_image->mlx_img,
		&dt.sky_image->bpp, &dt.sky_image->line_len, &dt.sky_image->endian);

	printf("Done! Loaded sky texture: %dx%d\n", w, h);



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

