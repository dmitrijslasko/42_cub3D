/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:25:10 by dmlasko           #+#    #+#             */
/*   Updated: 2025/06/06 18:35:18 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

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

typedef struct s_x_y
{
	double	x;
	double	y;
}	t_x_y;

typedef struct s_ray
{
	double		dist;
	double		perc_img;
	t_type_wall	type_wall;
}	t_ray;

typedef struct s_map
{
	char	**map_data;
	size_t	map_size_rows;
	size_t	map_size_cols;
}	t_map;

typedef struct s_player
{
	size_t	player_pos_x;
	size_t	player_pos_y;
	t_x_y	pos;
	t_x_y	direction_vet;
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

void	*protected_malloc(size_t size, t_data dt);

void	swap(void *a, void *b, size_t size);
int		pixel_is_in_window(int x, int y);

void	draw_grid(t_img *img, int grid_size, int grid_color);

//ray

//constructor_ray.c
t_ray	*constructor_ray(double dist, t_type_wall wall);

void	set_delta_dist(t_x_y *delta_dis, t_x_y direction);
bool	create_array_ray(t_data dt);
void	set_side_dist(t_x_y *side_dist, t_x_y dir_vec, \
					t_x_y pos_player, t_x_y delta_dist);

//calculate_var.c
void	set_step(t_x_y *step, t_x_y dir_vec);

//update_coor_player.c
// t_coor	get_updated_coor_player(t_x_y pos, t_x_y dir);
t_coor	get_updated_coor_player_(t_coor coor, t_x_y dir, int signal);
t_coor	get_updated_coor_player(t_x_y pos, t_x_y dir, int signal);

//percentage
double	get_perc_wall(t_x_y pos_player, t_x_y direction, double dist_ray, \
							t_type_wall type_wall);

//x_y.c
double	max_double(double a, double b);
t_x_y	get_values_x_y(double x, double y);
void	set_values_x_y(t_x_y *new, double x, double y);
t_coor	get_values_coor(int x, int y);
void	set_value_coor(t_coor *new, int x, int y);

#endif
