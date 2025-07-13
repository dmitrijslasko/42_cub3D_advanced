/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:35:51 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/12 19:50:48 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # define _POSIX_C_SOURCE 200112L
# define _POSIX_C_SOURCE 200112L
# include <time.h>
# include <unistd.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include <stdint.h>

# include "../lib/libft/inc/libft.h"

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>

# include "colors.h"
# include "errors.h"
# include "keys.h"
# include "settings.h"
//# include "sound.h"

// structs

typedef enum e_wall_orientation
{
	DEFAULT_WALL = -1,
	NORTH,
	WEST,
	SOUTH,
	EAST,
	W_5,
	W_6,
	W_7,
	W_8,
	W_9,
	FLOOR,
	CEILING,
}	t_wall_orientation;

typedef enum e_cell_type
{
	EMPTY_CELL = -1,
	WALL_1,
	WALL_2,
	WALL_3,
	WALL_4,
	WALL_5,
	WALL_6,
	WALL_7,
	WALL_8,
	WALL_9,
	THIN_WALL_VERTICAL_1,
	THIN_WALL_HORIZONTAL_1,
	DOOR_VERTICAL_1,
	DOOR_VERTICAL_2,
	DOOR_HORIZONTAL_1,
	DOOR_HORIZONTAL_2,
	ELEVATOR_VERTICAL_1,
	ELEVATOR_HORIZONTAL_1,
}	t_cell_type;

typedef struct s_texture_match
{
	const char				*str;
	const size_t			length;
	const int				wall_orientation;
	const char				map_file_repr;
}							t_texture_match;

static const t_texture_match	g_texture_lookup[] = {
{"F", 1, FLOOR, ' '},
{"C", 1, CEILING, ' '},
{"W1", 2, WALL_1, '1'},
{"W2", 2, WALL_2, '2'},
{"W3", 2, WALL_3, '3'},
{"W4", 2, WALL_4, '4'},
{"W5", 2, WALL_5, '5'},
{"W6", 2, WALL_6, '6'},
{"W7", 2, WALL_7, '7'},
{"W8", 2, WALL_8, '8'},
{"W9", 2, WALL_9, '9'},
{"DV1", 3, DOOR_VERTICAL_1, '|'},
{NULL, -1, -1, 0}
};

typedef enum e_active_message
{
	NO_MESSAGE = 0,
	OPEN_DOOR,
	BE_KIND,
	ENJOY_THE_GAME,
}	t_active_message;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		a;
}	t_color;

// Door structure with animation info
typedef struct s_door
{
	size_t	id;
	float	pos_x;
	float	pos_y;
	// float	width;
	int		cell_x;
	int		cell_y;
	int		tex_id;
	int		state;
	int		orientation;
	float	open_progress;
	float	speed;
}	t_door;

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef struct s_x_y
{
	float	x;
	float	y;
}	t_x_y;

typedef struct s_dda_info
{
	t_coor	*map;
	t_coor	*step;
	t_x_y	*delta;
	t_x_y	*side;
	char	*hit_side;
}	t_dda_info;

typedef struct s_ray
{
	int			id;
	float		distance_to_wall;
	float		corrected_distance_to_wall;
	int			wall_height;
	float		percentage_of_image;
	int			cell_type;
	int			wall_orientation;
	t_x_y		vector;
	t_x_y		wall_hit;
	char		hit_side;
	char		hit_content;
	t_door		*door;
	t_x_y		door_hit_coor;
	float		distance_to_door;
}	t_ray;

typedef struct s_texture
{
	void		*texture_img;
	int			*texture_data;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
	char		*file;
}	t_texture;

typedef struct s_wall_tile
{
	int			wall_orientation;
	t_texture	texture;
	t_color		color;
	bool		is_color;
}	t_wall_tile;

typedef struct s_map
{
	char		**map_data;
	int			map_size_rows;
	int			map_size_cols;
	t_wall_tile	wall_tile[NUMBER_TEXTURES];
	t_wall_tile	door;
}	t_map;

typedef struct s_player
{
	t_x_y	pos;
	t_x_y	direction_vector;
	float	direction_vector_deg;
	float	plane_x;
	float	plane_y;
	char	cell_type_ahead;
	bool	can_move;
	bool	is_moving;
	float	move_speed_multiplier;
	int		health_level;
	int		ammo_level;
	int		selected_weapon;

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
	int		screen_center_y;
	float	z_plane_height;
	char	show_minimap;
	// int		minimap_color;
	char	show_debug_info;
	char	show_door_open_message;
	float	door_open;
	float	crouch;
}	t_view;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_sprite_texture
{
	int		texture_id;
	void	*sprite_img[SPRITE_FRAMES];
	int		*sprite_data[SPRITE_FRAMES];
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	char	type;
	char	*filepath;
}	t_sprite_texture;

typedef struct s_sprite
{
	size_t				id;
	t_x_y				pos;
	float				distance_to_player;
	char				type;
	int					time;
	t_sprite_texture	*texture;
}	t_sprite;

typedef struct s_gametime
{
	long				last_time;
	long				delta_time;
	long				start_time;
}	t_gametime;

// typedef struct s_item
// {
// 	int	is_weapon;
// 	int ammo_level;
// 	int frame_count;
// }	t_item;

typedef struct s_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_img				*raycasting_scene_img;
	t_img				*final_frame_img;
	t_img				*minimap_base_img;
	t_img				*minimap_img;
	t_img				*ui_img;
	t_map				map;
	t_door				*doors;
	size_t				door_count;
	t_ray				*rays;
	t_player			player;
	t_sprite			*sprites;
	t_sprite_texture	*sprite_textures;
	size_t				sprite_count;
	size_t				sprite_texture_count;
	t_view				*view;
	t_mouse				mouse;
	float				sin_table[PRECALCULATED_TRIG];
	float				cos_table[PRECALCULATED_TRIG];
	char				keys[TRACKED_KEYS];
	void				*welcome_img;
	t_gametime			time;
	t_img				*sky_image;
	t_img				*message_img;
	t_img				*weapon_img;
	float				ambient_light;
	void				*background_music;
	int					has_changed;
	int					frames_drawn_count;
	int					weapon_current_frame;
	int 				weapon_is_animating;
	long				weapon_last_frame_time;
	float				test_value_1;
	float				test_value_2;
	float				test_value_3;
	float				test_value_4;
}	t_data;

static inline int	pixel_is_in_window(int x, int y)
{
	return (x >= 0 && x < WINDOW_W && y >= 0 && y < WINDOW_H);
}

static inline float	clampf(float value, float min, float max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

// function prototypes
int			setup_mlx_and_win(t_data *dt);
void		setup_keyboard_and_mouse_hooks(t_data *dt);

int			setup_img(t_data *dt, t_img *img, size_t width, size_t height);

void		img_pix_put(t_img *img, int x, int y, int clr);

void		setup_keyboard_hooks(t_data *dt);
void		setup_mouse_hooks(t_data *dt);

void		*protected_malloc(size_t size, t_data *dt);
void		free_dt(t_data *dt);
void		free_audio(void *ptr);

void		put_img_to_img(t_img *dest, t_img *src, int dx, int dy);
void		put_img_to_img_circle(t_img *dest, t_img *src, int dx, int dy);
//parsing
char		*free_line_get_next(char *line, int fd);
bool		parsing(t_data *dt, char *file);
bool		check_valid_identifier_texture(char *identifier);
bool		check_color(char *one_color);
bool		check_valid_color(char **color);
bool		check_only_number(char *str);
bool		check_valid_player(t_map *map);
bool		check_valid_color_or_texture(char **info);
bool		is_empty_line(char *line);
void		init_dt(t_data *dt);
bool		is_valid_line_texture(char *line);
bool		set_size_map_data(t_map *map, char *file);
bool		check_valid_wall_tile_file(char *file);
bool		create_map_data(t_map *map, t_data *dt);
bool		create_double_array(char ***array, size_t max_row,
						size_t max_col, t_data *dt);
bool		check_type_file(char *file, char *type);
void		remove_new_line(char *str);
char		*remove_space_beginner(char *str);
bool		init_value_map_data(char *file, t_data *dt);
bool		init_default_map(t_map *map);
bool		init_value_player(t_map *map, t_player *player);
int			ft_open(char *file);
t_wall_orientation	check_valid_identifier_texture_wall(char *identifier);
bool		check_all_wall_tile(t_map *map);
bool		get_value_file(t_map *map, char *file);
bool		get_value_file(t_map *map, char *file);
void		get_value_map(char *line, int fd, t_map *map);
void		get_init_position(t_map *map, t_player *player);
bool		set_color_or_texture(t_map *map, char *identifier, char **value);
bool		set_texture(char *identifier, char *file_texture, t_map *map);
bool		set_color(char *identifier, char **color, t_map *map);
bool		check_valid_map(t_map *map, t_player *player, t_data *dt);
char		get_cell_type(t_map *map, t_coor *coord);
char		get_cell_type_by_coordinates(t_map *map, size_t y, size_t x);
char		**ft_split_special(const char *s, char *c);

// player movements
int			move_sideways(t_data *dt, int is_to_the_right);
int			move_forward_backward(t_data *dt, int direction);
void		rotate_player(t_data *dt, float d_angle, int direction);

//ray
void		update_ray_distance_to_cell_edge(t_data *dt, t_ray *ray, \
												t_coor *map_coor);
void		step_and_set_side(t_dda_info *info);
int			check_door_hit(t_data *dt, t_ray *ray, t_coor *map);
void		finish_ray_casting(t_data *dt, t_ray *ray, t_coor *map_coor, \
																int door_hit);
void		update_ray_hit_point(t_data *dt, t_ray *ray);
int			check_door_hit(t_data *dt, t_ray *ray, t_coor *map);

//constructor_ray.c
void		update_single_ray(t_data *dt, t_ray *ray);
void		calculate_ray_distance(t_data *dt, t_ray *ray, \
									t_x_y *delta_dist, t_x_y *side_dist);

void		set_delta_dist(t_x_y *delta_dis, t_x_y direction);
bool		init_rays(t_data *dt);
void		set_side_dist(t_x_y *side_dist, t_x_y *dir_vec,
						t_x_y *pos_player, t_x_y *delta_dist);
void		set_step(t_coor *step, t_x_y *dir_vec);

//update_coor_player->c
void		set_perc_wall(t_x_y *pos_player, t_ray *ray);

//wall_orientation.c
void		set_wall_orientation(t_ray *ray);
void		print_ray(t_ray ray);

//x_y.c
void		set_values_size_t(int *new_x, int *new_y, int x, int y);
t_x_y		get_values_x_y(float x, float y);
void		set_values_x_y(t_x_y *new, float x, float y);
t_coor		get_values_coor(int x, int y);
void		set_value_coor(t_coor *new, int x, int y);

// basic drawing
void		draw_background(t_img *img, int color);

void		draw_line(t_img *img, t_coor pt_1, t_coor pt_2, int clr);
void		draw_vertical_line(t_img *img, t_coor pt_1, t_coor pt_2, int color);

void		draw_circle(t_img *img, t_coor *coor, int radius, int clr);
void		draw_rectangle(t_img *img, t_coor top_left,
						t_coor bottom_right, int clr);

void		draw_square_from_center(t_img *img, t_coor *coor,
						int size, int clr);
void		draw_square_from_top_left(t_img *img, t_coor coor,
						int size, int clr);

t_map		*load_dummy_map(void);
void		print_level_map(t_map *map);

int			render_frame(void *param);
void		render_ui(t_data *dt);

int			init_player(t_data *dt);

int			calculate_all_rays(t_data *dt);

bool		check_hit_wall(t_coor *coord, t_map *map, t_ray *ray, char side);

void		print_single_ray_info(t_ray ray);

int			error_msg(char *msg, int ret);
int			error_message_close_fd(char *msg, int fd, int ret);
int			error_message2(char *msg, char*msg2, int ret);
int			error_message_free(char *msg, char **array, int ret);
int			free_array_return(char **array, int ret);
int			error_free_char_return(char *msg, char *str, int ret);
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
int			clamp(int value, int min, int max);

// useful functions
void		print_separator(size_t count, char *c);
void		print_separator_default(void);

int			set_coor_values(t_coor *coor, int x, int y);

t_x_y		rotate_vector(t_x_y *vec, float angle_degrees, t_data *dt);

// minimap
int			update_minimap(t_data *dt);
int			draw_minimap_base_img(t_data *dt);
void		draw_minimap_grid(t_data *dt);
int			draw_minimap_player(t_data *dt);
void		draw_minimap_ray(t_data *dt, t_coor origin, t_x_y dir, int color);
int			draw_minimap_rays(t_data *dt, int is_direction_vector);
int			draw_minimap_THIN_WALL_VERTICAL_1(t_data *dt,
						size_t curr_col, size_t curr_row);
int			draw_minimap_door_vertical(t_data *dt,
						size_t curr_col, size_t curr_row);
int			draw_minimap_sprite(t_data *dt, size_t curr_col, size_t curr_row);
int			draw_minimap_wall_cell(t_data *dt, size_t curr_col,
						size_t curr_row);

// 3d render
int			load_sky_image(t_data *dt);
int			draw_sky(t_data *dt);
void		render_3d_scene(t_data *dt);
int			draw_ceiling(t_data *dt);
int			draw_floor(t_data *dt);
int	draw_textured_floor(t_data *dt);
int	draw_textured_floor2(t_data *dt);
int draw_textured_ceiling(t_data *dt);
int			render_sprite(t_data *dt, t_sprite *sprite, t_coor *offset,
						t_coor *sprite_size);
float		fix_fish_eye(t_ray *ray, t_player *player);
int			fix_fish_eye_2(t_ray *ray, t_player *player, float *distance);
int			load_sprite_textures(t_data *dt);
int			load_textures(t_data *dt);
int			load_sprites(t_data *dt);
int			precalculate_trig_tables(t_data *dt);

int			render_all_sprites(t_data *dt);
void		render_3d_each_ray(t_data *dt, t_ray *ray, int screen_slice_width);

int			apply_distance_shadow(t_ray *ray, int *color);

int			reset_mouse_position(t_data *dt);
void		process_keypresses(t_data *dt);
int			get_color_render3d(t_data *dt, t_ray *ray, t_coor *tex_coor);
void		calc_texture_coor(t_data *dt, int *texture_y, \
							float *distance_to_wall, int d);

// inits
void		init_doors(t_data *dt);

// controls
int			set_mouse_to_screen_center(t_data *dt);

// working with the map
size_t		count_elements_in_the_map(t_map *map, char *element);
size_t		count_types_elements_in_the_map(t_map *map, char *element);

size_t		size_array(char **array);
void		free_array(char **array);
void		update_value_max(int *count, char *line);

int			my_sleep(void);

t_coor		get_cell_ahead(t_data *dt);
void		set_cell_type(t_data *dt, t_ray *ray, t_coor *map_coor);

int			ray_hits_door(t_data *dt, t_coor *map_coor, t_ray *ray);
t_door		*find_door_at(t_data *dt, int x, int y);

//sprites
void		find_all_sprites(t_data *dt);
void		sort_sprites(t_sprite *sprites, size_t num_sprites);
void		sort_sprites_by_distance(t_data *dt);
void		sort_sprites(t_sprite *sprites, size_t num_sprites);
int			render_all_sprites(t_data *dt);
int			get_position_and_render_sprite(t_data *dt, t_sprite *sprite);
bool		set_texture_sprites(t_data *dt);
void		sprite_put_color(t_data *dt, t_sprite *sprite, \
										t_coor *coor, t_coor *tex_coor);
t_coor		calculate_tex_x_y(t_sprite_texture *texture, t_coor *coor, \
									t_coor *offset, t_coor *sprite_size);
bool		check_sprite_closer_than_wall(t_data *dt, t_coor *coor, \
															t_sprite *spr);
int			init_keys(t_data *dt);
void		init_graphic(t_data *dt);
void		init_text_sprites(t_sprite_texture *texture);
int			load_messages(t_data *dt);
void		setup_view(t_data *dt);

int			create_color_rgba(int r, int g, int b, int a);
int			create_color_rgb(int r, int g, int b);

void		show_debug_info(t_data *dt);

int			move_sideways(t_data *dt, int to_the_right);
int			move_forward_backward(t_data *dt, int direction);
int			map_position_is_walkable(t_data *dt, float *new_x, float *new_y);

int			render_ui_message(t_data *dt);
void		free_graphic(t_data *dt);
void		free_wall_tile_texture(t_data *dt);
void		free_texture(t_data *dt, t_texture *texture);
void		free_img(t_img *img, void *mlx_ptr);
void		free_texture_sprite(t_data *dt);
void		ft_free(void *ptr);
int			count_sprite_textures(t_data *dt);
size_t		count_if_there_is_others_elements(t_map *map, char *element);

//dda
void		step_and_set_side(t_dda_info *info);
void		update_ray_hit_point(t_data *dt, t_ray *ray);
int			check_door_hit(t_data *dt, t_ray *ray, t_coor *map);
int			check_hit_door_cell(t_coor *map, t_data *dt);
void		init_raycasting(t_coor *step, t_coor *map_coor, \
						t_data *dt, t_ray *ray);
void		finish_ray_casting(t_data *dt, t_ray *ray, \
						t_coor *map_coor, int door_hit);
void		calculate_ray_distance(t_data *dt, t_ray *ray, \
						t_x_y *delta_dist, t_x_y *side_dist);
void		finish_ray_casting(t_data *dt, t_ray *ray, \
						t_coor *map_coor, int door_hit);
void		update_ray_hit_point(t_data *dt, t_ray *ray);
int			run_dda_loop(t_data *dt, t_ray *ray, t_dda_info *info);

// debug
void		show_debug_info(t_data *dt);
void		print_time_stats(t_data *dt, void *mlx, void *win, int *y);
void		print_cell_info(t_data *dt, void *mlx, void *win, int *y);
void		print_door_hit_stats(t_data *dt, void *mlx, void *win, int *y);
void		print_window_info(t_data *dt, void *mlx, void *win, int *y);
void		print_obstacle_info(t_data *dt, void *mlx, void *win, int *y);
void		print_player_position(t_data *dt, void *mlx, void *win, int *y);

int			load_sprite_images(t_data *dt);
int			load_weapons(t_data *dt);

void		show_player_info(t_data *dt);

int	apply_distance_shadow_distance(int distance, int *color);

#endif
