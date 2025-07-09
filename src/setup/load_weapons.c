/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_messages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:10 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:10:11 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_weapons(t_data *dt)
{
	int	w;
	int	h;

	print_separator_default();
	printf(TXT_YELLOW ">>> LOADING UI MESSAGES\n" TXT_RESET);
	dt->weapon_img = protected_malloc(sizeof(t_img), dt);
	dt->weapon_img->mlx_img = mlx_xpm_file_to_image(dt->mlx_ptr,
			"./ui/weapon.xpm", &w, &h);
	if (!dt->weapon_img->mlx_img)
	{
		fprintf(stderr, "Failed to load weapon_img\n");
		return (EXIT_FAILURE);
	}
	dt->weapon_img->width = w;
	dt->weapon_img->height = h;
	dt->weapon_img->addr = mlx_get_data_addr(dt->weapon_img->mlx_img,
			&dt->weapon_img->bpp, &dt->weapon_img->line_len,
			&dt->weapon_img->endian);
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	return (EXIT_SUCCESS);
}
