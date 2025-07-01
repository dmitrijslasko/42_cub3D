#include "cub3d.h"

void	put_pix_img(t_data *dt, t_ray *ray, t_coor *texture, t_coor *coor)
{
	int		color;

	color = get_color_render3d(dt, ray, texture);
	img_pix_put(dt->scene_img, coor->x, coor->y, color);
}

void	render_3d_each_ray(t_data *dt, t_ray *ray, int screen_slice_width)
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
