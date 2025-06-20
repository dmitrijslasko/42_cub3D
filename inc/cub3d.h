#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include <stdint.h>

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
	DEFAULT = -1,
	NORTH,
	WEST,
	SOUTH,
	EAST,
	FLOOR,
	CEILING,
	NS_THIN_WALL,
	WE_THIN_WALL,
	DOOR
}	t_type_wall;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		a;
}	t_color;


typedef struct s_coor
{
	size_t	x;
	size_t	y;
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

typedef struct s_texture
{
	void		*texture_img;
	int			*texture_data; // Or char* depending on format
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
	char		*file;
}	t_texture;

typedef struct s_wall_tile
{
	t_type_wall	wall_type;
	t_texture	texture;
	t_color		color;
	bool		is_color;
}	t_wall_tile;

typedef struct s_map
{
	char		**map_data;
	size_t		map_size_rows;
	size_t		map_size_cols;
	t_wall_tile	wall_tile[6];
}	t_map;

typedef struct s_player
{
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
	int		screen_center;
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

typedef struct s_sprite
{
	void	*sprite_img;
	int		*sprite_data; // Or char* depending on format
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	float	x;
	float	y;
	float	distance_to_player;
	int		texture_id;
	char	*filepath;
}	t_sprite;


typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_map		map;
	t_ray		*rays;
	t_player	player;
	t_sprite	*sprites;
	t_view		*view;
	t_mouse		mouse;
	float		sin_table[PRECALCULATED_TRIG];
	float		cos_table[PRECALCULATED_TRIG];
	char		keys[TRACKED_KEYS];
	void		*welcome_img;
}	t_data;




// function prototypes
int			setup_mlx_and_win(t_data *dt);
void		setup_keyboard_and_mouse_hooks(t_data *data);
int			setup_img(t_data *dt);

void		img_pix_put(t_img *img, int x, int y, int clr);

void		setup_keyboard_hooks(t_data *dt);
void		setup_mouse_hooks(t_data *dt);




// void		img_pix_put(t_img *img, int x, int y, int clr);
// void		draw_square(t_data *data, int x, int y, int size, int clr);
// void		draw_circle(t_data *data, int x, int y, int radius, int clr);
// void		draw_background(t_img *img, int clr);
// void		draw_line(t_data *dt, t_coor pt_1, t_coor pt_2, int clr);

// int			draw_player(t_data *dt);
// int			draw_map(t_data *dt);


void		*protected_malloc(size_t size, t_data dt);

int			pixel_is_in_window(int x, int y);

//parsing
char		*free_line_get_next(char *line, int fd);
bool		parsing(t_data *dt, char *file);
bool		check_valid_identifier_texture(char *identifier);
bool		check_only_number(char *str);
bool		check_valid_player(t_map map);
bool		check_valid_color_or_texture(char **info);
bool		is_empty_line(char *line);
// bool		is_delimiter(char c, const char *delimiters);
bool		is_valid_line_texture(char *line);
bool		set_size_map_data(t_map *map, char *file);
bool		check_valid_wall_tile_file(int fd);
bool		create_map_data(t_map *map);
bool		create_double_array(char ***array, size_t max_row, size_t max_col);
bool		check_type_file(char *file, char *type);
void		remove_new_line(char *str);
char		*remove_space_beginner(char *str);
bool		init_value_map_data(char *file, t_map *map);
bool		init_default_map(t_map *map);
int			ft_open(char *file);
t_type_wall	check_valid_identifier_texture_wall(char *identifier);
bool		check_all_wall_tile(t_map map);
bool		get_value_file(t_map *map, char *file);
bool		get_value_file(t_map *map, char *file);
void		get_value_map(char *line, int fd, t_map *map);
void		get_init_position(t_map map, t_player *player);
bool		set_color_or_texture(t_map *map, char *identifier, char **value);
bool		set_texture(char *identifier, char *file_texture, t_map *map);
bool		set_color(char *identifier, char **color, t_map *map);
bool		check_valid_map(t_map map, t_player player);

char		get_cell_type(t_map map, t_coor coord);

// player movements
int 		move_forward_backward(t_data *dt, int direction);
int 		move_sideways(t_data *dt, int direction);
void 		rotate_player(t_data *dt, float d_angle, int direction);

//ray
void	set_wall_dist_and_type(t_ray *ray, char c, t_coor map_coor, t_player player);

//constructor_ray.c
t_ray		*calculate_single_ray(t_data dt, t_x_y direction);
void		update_single_ray(t_data *dt, t_ray *ray);
void		calc_dist_ray(t_data dt, t_ray *ray, t_x_y delta_dist, t_x_y side_dist);

//t_ray		*constructor_ray(float dist, t_type_wall wall);

void		set_delta_dist(t_x_y *delta_dis, t_x_y direction);
bool		initialize_rays(t_data *dt);
void		set_side_dist(t_x_y *side_dist, t_x_y dir_vec, t_x_y pos_player, t_x_y delta_dist);
void		set_step(t_x_y *step, t_x_y dir_vec);

//update_coor_player.c
// t_coor		get_updated_coor_player(t_x_y pos, t_x_y dir, int signal);
void		set_perc_wall(t_x_y pos_player, t_ray *ray);

//type_wall.c
void		set_wall_type(char c, t_ray *ray);
void		print_ray(t_ray ray);

//x_y.c
float		max_float(float a, float b);
void		set_values_size_t(size_t *new_x, size_t *new_y, size_t x, size_t y);
t_x_y		get_values_x_y(float x, float y);
void		set_values_x_y(t_x_y *new, float x, float y);
t_coor		get_values_coor(int x, int y);
void		set_value_coor(t_coor *new, int x, int y);

// basic drawing
void		draw_background(t_img *img, int color);
void		draw_line(t_data *dt, t_coor pt_1, t_coor pt_2, int clr);
void		draw_vertical_line(t_data *data, t_coor pt_1, t_coor pt_2, int color);

void		draw_circle(t_data *dt, int x, int y, int radius, int clr);
void		draw_rectangle(t_data *dt, t_coor top_left, t_coor bottom_right, int clr);

void		draw_square_from_center(t_data *data, int x, int y, int size, int clr);
void		draw_square_from_top_left(t_data *data, int x, int y, int size, int clr);

//
t_map		*load_dummy_map(void);
void		print_level_map(t_map map);

int			render_frame(void *param);
void		add_ui(t_data *dt);

int			init_player(t_data *dt);

int			calculate_all_rays(t_data *dt);

bool		check_hit_wall(t_coor coord, t_map map, t_ray *ray);

void		print_single_ray_info(t_ray ray);

int			error_message(char *msg, int ret);
int			error_message_close_fd(char *msg, int fd, int ret);
int			error_message2(char *msg, char*msg2, int ret);
int			error_message_free(char *msg, char **array, int ret);
int			free_array_return(char **array, int ret);
void		free_array(char **array);

// utils
float		deg_to_rad(float angle);
float		rad_to_deg(float radians);
int			ft_min(int num1, int num2);
int			ft_max(int num1, int num2);
long		get_current_time_in_ms(void);
void		swap(void *a, void *b, size_t size);
void		toggle_setting(char *setting);
int			sign(int x);

// useful functions
void		print_separator(size_t count, char *c);
void		print_separator_default(void);

int			set_coor_values(t_coor *coor, int x, int y);

t_x_y		rotate_vector(t_data data, t_x_y vet, float angle_degrees);

// minimap
int			draw_minimap(t_data *dt);
int			draw_minimap_map(t_data *dt);
void		draw_minimap_grid(t_data *dt);
int			draw_minimap_player(t_data *dt);

void		draw_minimap_ray(t_data *dt, t_coor origin, t_x_y dir, int color);
int			draw_minimap_rays(t_data *dt, int is_direction_vector);


// 3d render
int			draw_ceiling(t_data *dt);
int			draw_floor(t_data *dt);


// int	get_pixel_color(t_img *img, int x, int y);
// int blend_colors(int fg, int bg, float alpha);

int			load_textures(t_data *dt);
int			load_sprites(t_data *dt);
int			precalculate_trig_tables(t_data *dt);

int			render_sprites(t_data *dt);

int			apply_wall_shading_1(t_data *dt, size_t i, int *color);

int			reset_mouse_position(t_data *dt);
void		process_keypresses(t_data *dt);

size_t		count_elements_in_the_map(t_map map, char *element);

int			test_render_sprite(t_data *dt);

int			set_mouse_to_screen_center(t_data *dt);

void		fix_fish_eye(t_ray *ray, t_player player);
#endif
