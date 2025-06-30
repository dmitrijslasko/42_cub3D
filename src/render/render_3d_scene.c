#include "cub3d.h"

static int	render_floor_and_ceiling(t_data *dt)
{
	if (BONUS)
		draw_sky(dt);
	else
		draw_ceiling(dt);
	draw_floor(dt);
	return (EXIT_SUCCESS);
}

void	calc_texture_coor(t_data *dt, int *texture_y, \
							float *distance_to_wall, int d)
{
	float	wall_height;
	t_coor	tex_size;

	tex_size.y = dt->map.wall_tile->texture.height;
	wall_height = 1.0f / *distance_to_wall * SCALING;
	*texture_y = (d * tex_size.y) / (2 * wall_height);
	if (*texture_y >= tex_size.y)
		*texture_y = tex_size.y - 1;
}

int	get_color_render3d(t_data *dt, t_ray *ray, t_coor *tex_coor)
{
	int			color;
	int			tex_index;
	t_texture	texture;

	texture = dt->map.wall_tile[ray->wall_type].texture;
	tex_coor->x = (texture.width * ray->percentage_of_image);
	tex_index = texture.width * tex_coor->y + tex_coor->x;
	if (ray->cell_type == DOOR_VERTICAL)
	{
		texture = dt->map.door.texture;
		if (ray->vector.x > 0)
			tex_index = texture.width * (tex_coor->y + \
						(ray->percentage_of_image - ray->door->open_progress));
		else
			tex_index = texture.width * (tex_coor->y + \
				(1.0f - ray->percentage_of_image - ray->door->open_progress));
	}
	color = texture.texture_data[tex_index];
	if (ENABLE_SHADERS)
		apply_distance_shadow(ray, &color);
	return (color);
}

void	put_pix_img(t_data *dt, t_ray *ray, t_coor *texture, t_coor *coor)
{
	int		color;

	color = get_color_render3d(dt, ray, texture);
	img_pix_put(dt->scene_img, coor->x, coor->y, color);
}

void	render_3d_scene1(t_data *dt, t_ray *ray, int screen_slice_width)
{
	float	wall_height;
	int		top_y;
	t_coor	coor;
	t_coor	texture;
	t_coor	tex_size;

	wall_height = 1.0f / ray->corrected_distance_to_wall * SCALING;
	top_y = dt->view->screen_center_y - wall_height;
	tex_size.y = dt->map.wall_tile->texture.height;
	coor.y = ft_max(top_y, 0);
	while (coor.y < ft_min(WINDOW_H, dt->view->screen_center_y + wall_height))
	{
		calc_texture_coor(dt, &texture.y, &ray->corrected_distance_to_wall, \
																coor.y - top_y);
		coor.x = ft_max(ray->id * screen_slice_width, 0);
		while (coor.x < (ray->id + 1) * screen_slice_width && coor.x < WINDOW_W)
		{
			put_pix_img(dt, ray, &texture, &coor);
			coor.x++;
		}
		coor.y++;
	}
}

void	render_3d_scene(t_data *dt)
{
	int	i;
	int	screen_slice_width;

	i = 0;
	screen_slice_width = WINDOW_W / CASTED_RAYS_COUNT;
	render_floor_and_ceiling(dt);
	while (i < CASTED_RAYS_COUNT)
	{
		dt->rays[i].id = i;
		render_3d_scene1(dt, &dt->rays[i++], screen_slice_width);
	}
	render_all_sprites(dt);
}
