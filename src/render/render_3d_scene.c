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

// void render_3d_scene(t_data *dt)
// {
// 	size_t	i;
// 	float	wall_height;
// 	int		screen_x;
// 	int 	top_y;
// 	int		bottom_y;
// 	int 	w;
// 	int		tex_index;
// 	int		color;
// 	size_t	texture_x;
// 	int		screen_slice_width;
// 	int		y;
// 	int 	texture_y;

// 	render_floor_and_ceiling(dt);

// 	i = 0;
// 	while (i < CASTED_RAYS_COUNT)
// 	{
// 		// Distance-based projection
// 		wall_height = 1.0f / dt->rays[i].corrected_distance_to_wall * SCALING;

// 		top_y = dt->view->screen_center_y - wall_height;
// 		bottom_y = dt->view->screen_center_y + wall_height;

// 		 int texture_width = dt->map.wall_tile->texture.width;
// 		 int texture_height = dt->map.wall_tile->texture.height;

// 		 texture_x = (dt->rays[i].percentage_of_image * texture_width);

// 		 if (texture_x >= (size_t)texture_width)
// 		 	texture_x = texture_width - 1;

// 		// Horizontal screen position
// 		screen_slice_width = WINDOW_W / CASTED_RAYS_COUNT;
// 		screen_x = i * screen_slice_width;

// 		// Vertical wall slice drawing
// 		y = ft_max(top_y, 0);
// 		while (y < ft_min(WINDOW_H, bottom_y))
// 		{
// 			// // Relative position on the wall
// 			int d = y - top_y;
// 			texture_y = fmax((d * texture_height) / (2 * wall_height), 0);
// 			if (texture_y >= texture_height)
// 				texture_y = texture_height - 1;

// 			if (dt->rays[i].cell_type == DOOR_VERTICAL)
// 			{
// 				if (dt->rays[i].vector.x > 0)
// 					tex_index = texture_y * 64 + (64 * (dt->rays[i].percentage_of_image - dt->rays[i].door->open_progress));
// 				else
// 					tex_index = texture_y * 64 + (64 * (1.0f - dt->rays[i].percentage_of_image - dt->rays[i].door->open_progress));
// 				color = dt->map.door.texture.texture_data[tex_index];
// 			}
// 			else
// 			{
// 				tex_index = texture_y * texture_width + texture_x;
// 				color = dt->map.wall_tile[dt->rays[i].wall_type].texture.texture_data[tex_index];
// 			}

// 			if (ENABLE_SHADERS)
// 				apply_distance_shadow(dt, i, &color, DISTANCE_SHADOW_STRENGTH);

// 			w = ft_max(screen_x, 0);
// 			while (w < screen_slice_width + screen_x && w < WINDOW_W)
// 			{
// 				// if (pixel_is_in_window(w, y))
// 				img_pix_put(dt->scene_img, w, y, color);
// 				w++;
// 			}
// 			y++;
// 		}
// 		i++;
// 	}
// 	render_all_sprites(dt);
// }


// void render_3d_scene1(t_data *dt, t_ray *ray)
// {
// 	float	wall_height;
// 	int		screen_x;
// 	int 	top_y;
// 	int		bottom_y;
// 	int 	w;

// 	size_t	texture_x;
// 	int		screen_slice_width;
// 	int		y;
// 	int 	texture_y;

// 	// Distance-based projection
// 	wall_height = 1.0f / ray->corrected_distance_to_wall * SCALING;

// 	top_y = dt->view->screen_center_y - wall_height;
// 	bottom_y = dt->view->screen_center_y + wall_height;

// 	int texture_width = dt->map.wall_tile->texture.width;
// 	int texture_height = dt->map.wall_tile->texture.height;

// 	// Horizontal screen position
// 	screen_slice_width = WINDOW_W / CASTED_RAYS_COUNT;
// 	screen_x = ray->id * screen_slice_width;

// 	// Vertical wall slice drawing
// 	y = ft_max(top_y, 0);
// 	while (y < ft_min(WINDOW_H, bottom_y))
// 	{
// 		// // Relative position on the wall
// 		int d = y - top_y;
// 		texture_y = fmax((d * texture_height) / (2 * wall_height), 0);
// 		if (texture_y >= texture_height)
// 			texture_y = texture_height - 1;

// 		// if (ray->cell_type == DOOR_VERTICAL)
// 		// {
// 		// 	if (ray->vector.x > 0)
// 		// 		tex_index = 64 * (texture_y + (ray->percentage_of_image - ray->door->open_progress));
// 		// 	else
// 		// 		tex_index = 64 * (texture_y + (1.0f - ray->percentage_of_image - ray->door->open_progress));
// 		// 	color = dt->map.door.texture.texture_data[tex_index];
// 		// }
// 		// else
// 		// {
// 		// 	texture_x = (ray->percentage_of_image * texture_width);
// 		// 	tex_index = texture_y * texture_width + texture_x;
// 		// 	color = dt->map.wall_tile[ray->wall_type].texture.texture_data[tex_index];
// 		// }

// 		if (ENABLE_SHADERS)
// 			apply_distance_shadow(ray, &color);

// 		w = ft_max(screen_x, 0);
// 		while (w < screen_slice_width + screen_x && w < WINDOW_W)
// 		{
// 			img_pix_put(dt->scene_img, w, y, color);
// 			w++;
// 		}
// 		y++;
// 	}
// }

int	get_color_render3d(t_data *dt, t_ray *ray, t_coor *texture, int *texture_width)
{
	int		color;
	int		tex_index;

	if (ray->cell_type == DOOR_VERTICAL)
	{
		if (ray->vector.x > 0)
			tex_index = 64 * (texture->y + (ray->percentage_of_image - ray->door->open_progress));
		else
			tex_index = 64 * (texture->y + (1.0f - ray->percentage_of_image - ray->door->open_progress));
		color = dt->map.door.texture.texture_data[tex_index];
	}
	else
	{
		texture->x = ( *texture_width * ray->percentage_of_image);
		tex_index = *texture_width * texture->y  + texture->x;
		color = dt->map.wall_tile[ray->wall_type].texture.texture_data[tex_index];
	}
	if (ENABLE_SHADERS)
		apply_distance_shadow(ray, &color);
	return (color);
}

void render_3d_scene1(t_data *dt, t_ray *ray)
{
	float	wall_height;
	int		screen_x;
	int 	top_y;
	int		bottom_y;
	int 	w;
	t_coor	texture;
	t_coor	tex_size;
	int		screen_slice_width;
	int		y;
	int		color;

	// Distance-based projection
	wall_height = 1.0f / ray->corrected_distance_to_wall * SCALING;

	top_y = dt->view->screen_center_y - wall_height;
	bottom_y = dt->view->screen_center_y + wall_height;

	tex_size.y = dt->map.wall_tile->texture.height;

	// Horizontal screen position
	screen_slice_width = WINDOW_W / CASTED_RAYS_COUNT;
	screen_x = ray->id * screen_slice_width;

	// Vertical wall slice drawing
	y = ft_max(top_y, 0);
	while (y < ft_min(WINDOW_H, bottom_y))
	{
		// // Relative position on the wall
		int d = y - top_y;
		texture.y = fmax((d * tex_size.y) / (2 * wall_height), 0);
		if (texture.y >= tex_size.y)
			texture.y = tex_size.y - 1;

		w = ft_max(screen_x, 0);
		while (w < screen_slice_width + screen_x && w < WINDOW_W)
		{
			tex_size.x = dt->map.wall_tile->texture.width;
			color = get_color_render3d(dt, ray, &texture, &tex_size.x);
			img_pix_put(dt->scene_img, w, y, color);
			w++;
		}
		y++;
	}
}

void	render_3d_scene(t_data *dt)
{
	size_t	i;

	i = 0;
	render_floor_and_ceiling(dt);
	while (i < CASTED_RAYS_COUNT)
	{
		dt->rays[i].id = i;
		render_3d_scene1(dt, &dt->rays[i++]);
	}
	render_all_sprites(dt);
}
