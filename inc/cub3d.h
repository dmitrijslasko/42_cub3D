#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

# include "../lib/libft/inc/libft.h"

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>

# include "colors.h"
# include "errors.h"
# include "keys.h"
# include "settings.h"

#include <sys/time.h>
#include <unistd.h>

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
	float	x;
	float	y;
}	t_x_y;

typedef struct s_ray
{
	float		distance_to_wall;
	float		percentage_of_image;
	t_type_wall	wall_type;
	t_x_y		vector;
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
	t_x_y	direction_vector;
	float	direction_vector_deg;
	float	move_speed_multiplier;
	bool	can_move;
}	t_player;

typedef struct s_mouse
{
	char	lmb_is_pressed;
	char	rmb_is_pressed;
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
	size_t	lmb_press_count;
	int		suppress_mouse_frames;
}	t_mouse;

typedef struct s_view
{
	size_t	screen_center;
	char	show_minimap;
}	t_view;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_texture
{
	void    *texture_img;
	int     *texture_data; // Or char* depending on format
	int     width, height;
	int     bpp, size_line, endian;
}	t_texture;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_map		*map;
	t_ray		*rays;
	t_player	*player;
	t_texture	*textures;
	t_view		*view;
	t_mouse		mouse;
	float		sin_table[PRECALCULATED_TRIG];
	float		cos_table[PRECALCULATED_TRIG];
	char 		keys[TRACKED_KEYS];
	void		*welcome_img;
}	t_data;


// function prototypes
int			setup_mlx_and_win(t_data *dt);
void		setup_keyboard_and_mouse_hooks(t_data *data);
int			setup_img(t_data *dt);

void	img_pix_put(t_img *img, int x, int y, int clr);






// void		img_pix_put(t_img *img, int x, int y, int clr);
// void		draw_square(t_data *data, int x, int y, int size, int clr);
// void		draw_circle(t_data *data, int x, int y, int radius, int clr);
// void		draw_background(t_img *img, int clr);
// void		draw_line(t_data *dt, t_coor pt_1, t_coor pt_2, int clr);

// int			draw_player(t_data *dt);
// int			draw_map(t_data *dt);


void		*protected_malloc(size_t size, t_data dt);

int			pixel_is_in_window(int x, int y);

// player movements
int 	move_forward_backward(t_data *dt, int direction);
int 	move_sideways(t_data *dt, int direction);
void 	rotate_player(t_data *dt, float d_angle, int direction);

//ray

//constructor_ray.c
t_ray	*constructor_ray(float dist, t_type_wall wall);
t_ray	*calculate_single_ray(t_data dt, t_x_y direction);

void	set_delta_dist(t_x_y *delta_dis, t_x_y direction);
bool	initialize_rays(t_data *dt);
void	set_side_dist(t_x_y *side_dist, t_x_y dir_vec, t_x_y pos_player, t_x_y delta_dist);
void	set_step(t_x_y *step, t_x_y dir_vec);

//update_coor_player.c
t_coor		get_updated_coor_player(t_x_y pos, t_x_y dir, int signal);

//percentage_wall.c
float		get_perc_wall(t_x_y pos_player, t_x_y direction, float dist_ray, \
							t_type_wall type_wall);

//type_wall.c
t_type_wall	get_type_wall(char c, t_x_y direction);
void		print_ray(t_ray ray);

//x_y.c
float		max_float(float a, float b);
t_x_y		get_values_x_y(float x, float y);
void		set_values_x_y(t_x_y *new, float x, float y);
t_coor		get_values_coor(int x, int y);
void		set_value_coor(t_coor *new, int x, int y);

// basic drawing
void	draw_background(t_img *img, int clr);
void	draw_line(t_data *dt, t_coor pt_1, t_coor pt_2, int clr);
void	draw_vertical_line(t_data *data, t_coor pt_1, t_coor pt_2, int color);

void	draw_circle(t_data *dt, int x, int y, int radius, int clr);
void	draw_rectangle(t_data *dt, t_coor top_left, t_coor bottom_right, int clr);

void	draw_square_from_center(t_data *data, int x, int y, int size, int clr);
void	draw_square_from_top_left(t_data *data, int x, int y, int size, int clr);



// utils

t_map	*load_dummy_map(void);
void	print_level_map(t_map *map);

int		render_frame(void *param);
void	add_ui(t_data *dt);

int		init_player(t_data *dt);

int		calculate_all_rays(t_data *dt);

bool	check_hit_wall(t_coor coord, t_map map);

void	print_single_ray_info(t_ray ray);

// utils
float	deg_to_rad(float angle);
int		ft_min(int	num1, int num2);
int		ft_max(int	num1, int num2);
long	get_current_time_in_ms(void);
void	swap(void *a, void *b, size_t size);

// useful functions
void	print_separator(size_t count, char *c);

int	set_coor_values(t_coor *coor, int x, int y);

t_x_y rotate_vector(t_data data, t_x_y vet, float angle_degrees);

// minimap
int		draw_minimap(t_data *dt);
int		draw_minimap_map(t_data *dt);
void	draw_minimap_grid(t_data *dt);
int		draw_minimap_player(t_data *dt);

void	draw_minimap_ray(t_data *dt, t_coor origin, t_x_y dir, int stop_at_wall);
int		draw_minimap_rays(t_data *dt, int is_direction_vector);


// 3d render
int		draw_ceiling(t_data *dt);
int		draw_floor(t_data *dt);

// utils

void	toggle_setting(char *setting);



#endif
