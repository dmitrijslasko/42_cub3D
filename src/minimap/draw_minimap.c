#include "cub3d.h"

int	draw_minimap_map(t_data *dt)
{
	t_map	*map;
	size_t	curr_row;
	size_t	curr_col;
	int		color;

	t_coor top_left;
	t_coor bottom_right;

	set_coor_values(&top_left, 0, 0);
	set_coor_values(&bottom_right,	dt->minimap_base->width,
									dt->minimap_base->height);
	draw_rectangle(dt->minimap_base, top_left, bottom_right, MINIMAP_BACKGROUND_COLOR);

	map = dt->map;

	curr_row = 0;
	while (curr_row < map->map_size_rows)
	{
		curr_col = 0;
		while (curr_col < map->map_size_cols)
		{
			if (map->map_data[curr_row][curr_col] == '0')
			{
				curr_col++;
				continue ;
			}
			if (ft_strchr("NSWE", dt->map->map_data[curr_row][curr_col]))
				color = MINIMAP_PLAYER_SPAWN_CELL_COLOR;
			else if (ft_strchr("v", dt->map->map_data[curr_row][curr_col]))
				color = MINIMAP_DOOR_COLOR;
			else if (ft_strchr("1", dt->map->map_data[curr_row][curr_col]))
				color = MINIMAP_WALL_CELL_COLOR;

			draw_square_from_top_left(dt->minimap_base,
						curr_col * MINIMAP_GRID_SIZE,
						curr_row * MINIMAP_GRID_SIZE,
						MINIMAP_GRID_SIZE,
						color);
			curr_col++;
		}
		curr_row++;
	}
	if (MINIMAP_GRID_ENABLE)
		draw_minimap_grid(dt);
	printf("Finished doing the minimap!\n");
	return (EXIT_SUCCESS);
}


unsigned int get_pixel(t_img *img, int x, int y)
{
    return *(unsigned int *)(img->addr + (y * img->line_len + x * (img->bpp / 8)));
}

void put_pixel(t_img *img, int x, int y, unsigned int color)
{
    *(unsigned int *)(img->addr + (y * img->line_len + x * (img->bpp / 8))) = color;
}
// void put_img_to_img(t_img *dest, t_img *src, int dx, int dy)
// {
// 	size_t	x;
// 	size_t	y;
// 	unsigned int	color;

// 	printf("SRC W H %zu %zu\n", src->width, src->height);
// 	printf("DEST W H %zu %zu\n", dest->width, dest->height);

// 	y = 0;
//   	while (y < 200)
//     {
//         int dest_y = dy + y;
//         if (dest_y < 0 || dest_y >= (int) dest->height)
//             continue;

// 		x = 0;
//         while (x < 200)
//         {
//             int dest_x = dx + x;
//             if (dest_x < 0 || dest_x >= (int) dest->width)
//                 continue;

//             color = get_pixel(src, x, y);

//             // Optional: skip transparent/black
//             if (color != TRANSPARENT_COLOR)
//                 put_pixel(dest, dest_x, dest_y, color);
// 			x++;
//         }
// 		y++;
//     }
// }

void put_img_to_img(t_img *dest, t_img *src, int dx, int dy)
{
	size_t x;
	size_t y;
	int src_x;
	int src_y;
	unsigned int color;

	y = 0;
	while (y < dest->height)
	{
		x = 0;
		while (x < dest->width)
		{
			src_x = x - dx;
			src_y = y - dy;

			if (src_x >= 0 && src_y >= 0 && src_x <= (int)src->width && src_y <= (int)src->height)
			{
				color = get_pixel(src, src_x, src_y);
				put_pixel(dest, x, y, color);
			}
			x++;
		}
		y++;
	}
}


int update_minimap(t_data *dt)
{
	int 	dx;
	int		dy;

	draw_background(dt->minimap, MINIMAP_WALL_CELL_COLOR);

	// place minimap base into correct position

	dx = MINIMAP_SIZE / 2 - dt->player.pos.x * MINIMAP_GRID_SIZE;
	dy = MINIMAP_SIZE / 2 - dt->player.pos.y * MINIMAP_GRID_SIZE;

	put_img_to_img(dt->minimap, dt->minimap_base, dx, dy);

	// draw player in the ce
	draw_minimap_player(dt);

	// if (MINIMAP_RENDER_RAYS_ENABLE)
	// 	draw_minimap_rays(dt, 0);
	if (MINIMAP_DIRECTION_RAY_ENABLE)
		draw_minimap_rays(dt, 1);
	return (EXIT_SUCCESS);
}
