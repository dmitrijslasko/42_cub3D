/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:25:10 by dmlasko           #+#    #+#             */
/*   Updated: 2025/06/05 19:34:09 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>

# include "colors.h"
# include "errors.h"
# include "keys.h"
# include "settings.h"

// structs

typedef enum e_type_wall
{
	NORTH = 1,
	WEST,
	SOUTH,
	EAST
}	t_type_wall;

typedef struct s_coor
{
	int		x;
	int		y;
}	t_coor;

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_ray
{
	double	dist;
	
}	t_ray;

typedef struct s_map
{
	char 	**map_data;
	size_t	map_size_rows;
	size_t	map_size_cols;
}	t_map;

typedef struct s_player
{
	size_t	player_pos_x;
	size_t	player_pos_y;
	t_pos	*pos;
	t_pos	*direction_vet;
	size_t	direction_vector_deg;
}	t_player;

typedef struct s_mouse
{
	char	lmb_is_pressed;
	char	rmb_is_pressed;
	int		x;
	int		y;
	int		previous_x;
	int		previous_y;
}	t_mouse;

typedef struct s_view
{
	int		show_admin;
}	t_view;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_map		*map;
	t_player	*player;
	t_view		*view;
	t_mouse		*mouse;
	//int		needs_update;
	void		*welcome_img;

}	t_data;

// prototypes
int		setup_mlx_and_win(t_data *dt);
void	setup_hooks(t_data *data);
void	setup_mouse(t_mouse *mouse);
int		setup_img(t_data *dt);

void	img_pix_put(t_img *img, int x, int y, int clr);
void	draw_square(t_data *data, int x, int y, int size, int clr);
void	draw_background(t_img *img, int clr);
void	draw_sloped_line(t_data *dt, t_coor pt_1, t_coor pt_2);

int		draw_player(t_data *dt);
int		draw_map(t_data *dt);

void	*protected_malloc(size_t size, t_data *dt);

void	swap(void *a, void *b, size_t size);
int		pixel_is_in_window(int x, int y);

void	draw_grid(t_img *img, int grid_size, int grid_color);

//ray
// bool    create_array_ray(t_map *map, t_player *player);

#endif
