/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:10 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:09:11 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_texture_coor(t_data *dt, float screen_x, int *texture_x, \
							float angle_offset)
{
	float	rotation_scale;
	float	view_ratio;
	float	tex_ratio;

	view_ratio = screen_x / (float)WINDOW_W;
	tex_ratio = fmodf(view_ratio + angle_offset, 1.0f);
	*texture_x = (int)(tex_ratio * dt->sky_image->width);
}

float	calculate_angle_offset(t_data *dt)
{
	float	angle_offset;
	float	angle_rad;

	angle_rad = dt->player.direction_vector_deg * (M_PI / 180.0f);
	angle_offset = fmodf((angle_rad * 6.0f) / (2 * M_PI), 1.0f);
	if (angle_offset < 0)
		angle_offset += 1.0f;
	return (angle_offset);
}

int	calculate_t_start_y(t_data *dt)
{
	int	delta;
	int	texture_start_y;

	delta = (int)(-(dt->view->screen_center_y - (WINDOW_H / 2)) * 1.0f);
	texture_start_y = (dt->sky_image->height / 3) - (WINDOW_H / 20) + delta;
	return (texture_start_y);
}

int	draw_sky1(t_data *dt, float angle_offset, int txt_start_y)
{
	t_coor		screen;
	int			texture_x;
	uint32_t	color;
	char		*pixel;

	screen.y = txt_start_y;
	while (screen.y < dt->view->screen_center_y + txt_start_y)
	{
		screen.x = 0;
		while (screen.x < WINDOW_W)
		{
			ft_texture_coor(dt, screen.x, &texture_x, angle_offset);
			pixel = dt->sky_image->addr + (screen.y - txt_start_y) * \
				dt->sky_image->line_len + texture_x * (dt->sky_image->bpp / 8);
			color = *(uint32_t *)pixel;
			img_pix_put(dt->scene_img, screen.x, screen.y - txt_start_y, color);
			screen.x++;
		}
		screen.y++;
	}
	return (EXIT_SUCCESS);
}

int	draw_sky(t_data *dt)
{
	float	angle_offset;
	int		texture_start_y;

	angle_offset = calculate_angle_offset(dt);
	texture_start_y = calculate_t_start_y(dt);
	draw_sky1(dt, angle_offset, texture_start_y);
}
