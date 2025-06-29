#include "cub3d.h"

void	setup_view(t_data *dt)
{
	dt->view->screen_center_y = WINDOW_H / 2;
	dt->view->show_minimap = 0;
	dt->view->show_debug_info = 0;
	dt->view->show_door_open_message = 0;
}

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

Mix_Music *init_audio(void)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music *bgm = Mix_LoadMUS("./sounds/music.wav");
    Mix_PlayMusic(bgm, -1); // Loop
    return bgm;
}


int init_keys(t_data *dt)
{
	size_t i;

	i = 0;
	while (i < TRACKED_KEYS)
	{
		dt->keys[i] = 0;
		i++;
	}
}

int load_sky_image(t_data *dt)
{
	int w;
	int h;

	print_separator_default();
	printf(TXT_YELLOW ">>> LOADING SKY IMAGE\n" TXT_RESET);
	dt->sky_image = malloc(sizeof(t_img));
	if (!dt->sky_image)
	{
		fprintf(stderr, "Failed to allocate memory for sky image\n");
		return (EXIT_FAILURE);
	}
	dt->sky_image->mlx_img = mlx_xpm_file_to_image(dt->mlx_ptr, "./textures/sky_2.xpm", &w, &h);
	if (!dt->sky_image->mlx_img)
	{
		fprintf(stderr, "Failed to load sky texture\n");
		return (EXIT_FAILURE);
	}
	dt->sky_image->width = w;
	dt->sky_image->height = h;
	dt->sky_image->addr = mlx_get_data_addr(dt->sky_image->mlx_img,
		&dt->sky_image->bpp, &dt->sky_image->line_len, &dt->sky_image->endian);

	printf("Loaded sky texture: %d x %d px\n", w, h);
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	return (EXIT_SUCCESS);
}

int load_messages(t_data *dt)
{
	int w;
	int h;

	print_separator_default();
	printf(TXT_YELLOW ">>> LOADING UI MESSAGES\n" TXT_RESET);
	dt->message_img = malloc(sizeof(t_img));
	if (!dt->message_img)
	{
		fprintf(stderr, "Failed to allocate memory\n");
		return (EXIT_FAILURE);
	}
	dt->message_img->mlx_img = mlx_xpm_file_to_image(dt->mlx_ptr, "./ui/open-close-door.xpm", &w, &h);
	if (!dt->message_img->mlx_img)
	{
		fprintf(stderr, "Failed to load message_img\n");
		return (EXIT_FAILURE);
	}
	dt->message_img->width = w;
	dt->message_img->height = h;
	dt->message_img->addr = mlx_get_data_addr(dt->message_img->mlx_img,
		&dt->message_img->bpp, &dt->message_img->line_len, &dt->message_img->endian);

	printf("Loaded message: %d x %d px\n", w, h);
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	dt;

	if (argc != 2)
		return (error_message("Try again! Format ./cub3D <name_file>.cub\n", 1));

	if (parsing(&dt, argv[1]))
	// 	printf(TXT_RED "%s failed\n" TXT_RESET, argv[1]);
	// else
	// 	printf(TXT_GREEN "%s successed\n" TXT_RESET, argv[1]);
	// free_dt(&dt);
		exit(1);

	// Load dummy map
	// dt.map = load_dummy_map();
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

	dt.view->door_open = 2.0f;

	load_textures(&dt);
	load_sky_image(&dt);
	load_messages(&dt);
	init_doors(&dt);
	load_sprites(&dt);

	// minimap base image
	setup_view(&dt);

	draw_minimap_map(&dt);
	setup_img(&dt, dt.scene_img, WINDOW_W, WINDOW_H);
	setup_img(&dt, dt.minimap, MINIMAP_SIZE, MINIMAP_SIZE);

	setup_keyboard_hooks(&dt);
	if (ENABLE_MOUSE)
		setup_mouse_hooks(&dt);

	print_separator_default();

	Mix_Music *bgm = init_audio();
	mlx_loop_hook(dt.mlx_ptr, &render_frame, &dt);
	mlx_loop(dt.mlx_ptr);

	return (EXIT_SUCCESS);
}

