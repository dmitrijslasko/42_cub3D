/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:12:07 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 14:44:04 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "sound.h"

static void	check_and_parse_args(t_data *dt, int argc, char **argv)
{
	if (argc != 2)
	{
		error_msg("Try again! Format ./cub3D <name_file>.cub\n", 1);
		exit(1);
	}
	if (parsing(dt, argv[1]))
	{
		free_dt(dt);
		exit(1);
	}
}

static int	setup_controls(t_data *dt)
{
	setup_keyboard_hooks(dt);
	if (BONUS && ENABLE_MOUSE)
		setup_mouse_hooks(dt);
	return (EXIT_SUCCESS);
}

static int	setup_dt(t_data *dt)
{
	init_rays(dt);
	init_keys(dt);
	dt->scene_img = protected_malloc(sizeof(t_img), dt);
	dt->frames_img = protected_malloc(sizeof(t_img), dt);
	dt->minimap = protected_malloc(sizeof(t_img), dt);
	dt->view = protected_malloc(sizeof(t_view), dt);
	load_textures(dt);
	load_sky_image(dt);
	load_messages(dt);
	init_doors(dt);
	// load_sprites(dt);
	setup_view(dt);
	draw_minimap_base_img(dt);
	setup_img(dt, dt->scene_img, WINDOW_W, WINDOW_H);
	setup_img(dt, dt->frames_img, WINDOW_W, WINDOW_H);
	setup_img(dt, dt->minimap, MINIMAP_SIZE, MINIMAP_SIZE);
	if (BONUS)
		dt->background_music = init_audio();
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	dt;

	check_and_parse_args(&dt, argc, argv);
	print_level_map(&dt.map);
	precalculate_trig_tables(&dt);
	setup_mlx_and_win(&dt);
	setup_dt(&dt);
	setup_controls(&dt);
	print_separator(3, DEF_SEPARATOR_CHAR);
	dt.start_time = get_current_time_in_ms();
	dt.last_time = 0;
	mlx_loop_hook(dt.mlx_ptr, &render_frame, &dt);
	mlx_loop(dt.mlx_ptr);
	free_dt(&dt);
	return (EXIT_SUCCESS);
}
