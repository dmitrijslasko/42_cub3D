#include "cub3d.h"

int	draw_minimap_wall_cell(t_data *dt, size_t curr_col, size_t curr_row)
{
	draw_square_from_top_left(dt->minimap_base_img,
			curr_col * MINIMAP_GRID_SIZE,
			curr_row * MINIMAP_GRID_SIZE,
			MINIMAP_GRID_SIZE,
			MINIMAP_WALL_CELL_COLOR);
}

int	draw_minimap_thin_wall_vertical(t_data *dt, size_t curr_col, size_t curr_row)
{
	t_coor top_left;
	t_coor bottom_right;

	top_left.x = curr_col * MINIMAP_GRID_SIZE;
	top_left.y = curr_row * MINIMAP_GRID_SIZE;

	bottom_right.x = top_left.x + 10;
	bottom_right.y = (curr_row + 1) * MINIMAP_GRID_SIZE;

	draw_rectangle(dt->minimap_base_img, top_left, bottom_right, MINIMAP_THIN_WALL_COLOR);
}

int	draw_minimap_door_vertical(t_data *dt, size_t curr_col, size_t curr_row)
{
	t_coor top_left;
	t_coor bottom_right;

	top_left.x = (curr_col + 0.5f) * MINIMAP_GRID_SIZE;
	top_left.y = curr_row * MINIMAP_GRID_SIZE;

	bottom_right.x = top_left.x + MINIMAP_DOOR_THICKNESS_PX;
	bottom_right.y = (curr_row + 1) * MINIMAP_GRID_SIZE;

	draw_rectangle(dt->minimap_base_img, top_left, bottom_right, MINIMAP_DOOR_COLOR);
}

int	draw_minimap_sprite(t_data *dt, size_t curr_col, size_t curr_row)
{
	t_coor center;

	center.x = (curr_col + 0.5f) * MINIMAP_GRID_SIZE;
	center.y = (curr_row + 0.5f) * MINIMAP_GRID_SIZE;

	draw_circle(dt->minimap_base_img, center.x, center.y, 10, MINIMAP_SPRITE_COLOR);
}

int	draw_minimap_map(t_data *dt)
{
	size_t	curr_row;
	size_t	curr_col;
	int		color;
	t_coor top_left;
	t_coor bottom_right;

	printf(TXT_YELLOW ">>> PREPARING MINIMAP BASE MAP\n" TXT_RESET);
	dt->minimap_base_img = protected_malloc(sizeof(t_img), dt);
	setup_img(dt, dt->minimap_base_img, dt->map.map_size_cols * MINIMAP_GRID_SIZE, dt->map.map_size_rows * MINIMAP_GRID_SIZE);
	set_coor_values(&top_left, 0, 0);
	set_coor_values(&bottom_right,	dt->minimap_base_img->width,
									dt->minimap_base_img->height);
	draw_rectangle(dt->minimap_base_img, top_left, bottom_right, MINIMAP_BACKGROUND_COLOR);

	curr_row = 0;
	while (curr_row < dt->map.map_size_rows)
	{
		curr_col = 0;
		while (curr_col < dt->map.map_size_cols)
		{
			if (dt->map.map_data[curr_row][curr_col] == '0')
			{
				curr_col++;
				continue ;
			}
			if (ft_strchr(PLAYER_SPAWN_POINT_TYPES, dt->map.map_data[curr_row][curr_col]))
				color = MINIMAP_PLAYER_SPAWN_CELL_COLOR;
			else if (ft_strchr("v", dt->map.map_data[curr_row][curr_col]))
			{
				draw_minimap_thin_wall_vertical(dt, curr_col++, curr_row);
				continue ;
			}
			else if (ft_strchr(HORIZONTAL_DOOR_TYPES, dt->map.map_data[curr_row][curr_col]))
				color = BLACK;
			else if (ft_strchr(VERTICAL_DOOR_TYPES, dt->map.map_data[curr_row][curr_col]))
			{
				draw_minimap_door_vertical(dt, curr_col++, curr_row);
				continue ;
			}
			else if (ft_strchr(WALL_TYPES, dt->map.map_data[curr_row][curr_col]))
			{
				draw_minimap_wall_cell(dt, curr_col++, curr_row);
				continue ;
			}
			else if (ft_strchr(SPRITE_TYPES, dt->map.map_data[curr_row][curr_col]))
			{
				draw_minimap_sprite(dt, curr_col++, curr_row);
				continue ;
			}
			else
				color = MINIMAP_BACKGROUND_COLOR;

			draw_square_from_top_left(dt->minimap_base_img,
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
	printf("Finished rendering the minimap base!\n");
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
	size_t			x;
	size_t			y;
	int				src_x;
	int				src_y;
	unsigned int	color;

	y = 0;
	while ((int)y < dest->height)
	{
		x = 0;
		while ((int)x < dest->width)
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

	put_img_to_img(dt->minimap, dt->minimap_base_img, dx, dy);

	// draw player in the ce
	draw_minimap_player(dt);

	 if (MINIMAP_RENDER_RAYS_ENABLE)
	 	draw_minimap_rays(dt, 0);
	if (MINIMAP_DIRECTION_RAY_ENABLE)
		draw_minimap_rays(dt, 1);
	return (EXIT_SUCCESS);
}
