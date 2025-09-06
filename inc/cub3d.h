/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:35:51 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/23 20:15:33 by dmlasko          ###   ########.fr       */
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
# include "texture_lookup.h"
# include "weapons.h"
# include "sprites.h"
# include "messages.h"
# include "sounds.h"

//# include "sound.h"

// structs

typedef enum e_wall_orientation
{
	DEFAULT_WALL = -1,
	NORTH,
	WEST,
	SOUTH,
	EAST,
}	t_wall_orientation;

typedef enum e_active_message
{
	NO_MESSAGE = 0,
	OPEN_DOOR,
	BE_KIND,
	ENJOY_THE_GAME,
}	t_active_message;

// typedef enum e_sprite_type {
//     SPRITE_ENEMY,
//     SPRITE_HEART,
//     SPRITE_WEAPON,
//     SPRITE_DECOR,
//     // etc
// } t_sprite_type;

typedef enum e_game_status {
	WELCOME_SCREEN = 1,
	MENU_SCREEN,
	PAUSE_SCREEN,
	LEVEL_START,
	LEVEL_GAME,
	LEVEL_FINISH,
	GAME_SCREEN,
	GAME_WON_SCREEN,
}	t_game_status;


typedef struct 		s_weapon
{
	t_active_item 		type;
	char		*description;
	int			bullets_in_clip;
	int			total_ammo;
	int			clip_size;
	float		shot_speed;
	float		reload_speed;
	float		weight;
	int			max_distance;
	int			player_has_it;
}	t_weapon;

// Door structure with animation info
typedef struct s_door
{
	size_t	id;
	int		side_texture_index;
	float	pos_x;
	float	pos_y;
	int		cell_x;
	int		cell_y;
	int		state;
	int		orientation;
	float	open_progress;
	char	is_opening;
	long	opening_finish_time;
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
	t_coor	*map_coor;
	t_coor	*step;
	t_x_y	*delta;
	t_x_y	*side;
	char	*hit_side;
}	t_dda_info;

typedef struct s_mapcell
{
	char		map_char;
	int			is_near_door;
	t_door		*door;
}	t_mapcell;

typedef struct s_ray
{
	int			id;
	float		distance_to_wall;
	float		corrected_distance_to_wall;
	int			wall_height;
	
	float		percentage_of_image;
	t_mapcell	*hit_cell;
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

typedef struct s_map
{
	t_mapcell	**map_data;
	int			map_size_rows;
	int			map_size_cols;
	int			number_of_textures;
	t_wall_tile	textures[NUMBER_TEXTURES];
}	t_map;

typedef struct s_player
{
	t_x_y		pos;
	t_x_y		orientation_vector;
	float		orientation;
	float		plane_x;
	float		plane_y;
	char		cell_type_ahead;
	
	bool		can_move;
	bool		is_moving;

	float		move_speed_multiplier;
	int			health_level;
	// int			ammo_level;
	
	t_weapon	*selected_weapon;

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
	int		active_prompt_message;
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
	char	*filepath;
	int		texture_id;
	char	map_char;
	
	void	*sprite_img[SPRITE_FRAMES];
	int		*sprite_data[SPRITE_FRAMES];

	// void	*sprite_img[NO_OF_ROTATION][NO_OF_ACTION];
	// int		*sprite_data[NO_OF_ROTATION][NO_OF_ACTION];
	
	char	is_sprite_sheet;
	float	orientation;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	
}	t_sprite_texture;

typedef enum e_sprite_type
{
	STATIC,
	DYNAMIC,
	ENEMY,
	PICKUP,
}	t_sprite_type;

typedef enum e_sprite_status
{
	IDLE,
	MOVING,
	SHOOTING,
	HURT,
	DYING
}	t_sprite_state;

typedef struct s_sprite
{
	t_sprite_texture	*texture;

	char				id;
	char				map_char;
	t_sprite_type		type;
	
	int					is_hidden;
	char				is_blocking;
	
	t_x_y				pos;
	t_coor				size;
	float				orientation;
	float				distance_to_player;
	float				orientation_to_player;

	float				speed;
	int					health_level;
	t_sprite_state		state;

	// int				total_frame_count;
	int					starting_frame;
	int					current_frame;
	long				last_frame_time;

	int					start_x;
	int					center_x;
	int					aim;

}	t_sprite;

typedef struct s_gametime
{
	long				last_time;
	long				delta_time;
	long				start_time;
}	t_gametime;


typedef struct s_level
{
	int					id;
	int					level_score;
	int					level_consumable_count;
	int					consumables_collected;
	float				score_combo;
	char				prev_consumable;
	
	t_map				map;

	t_sprite_texture	*sprite_textures;
	size_t				sprite_texture_count;
	t_sprite			*sprites;
	size_t				sprite_count;
	t_sprite			*targeted_sprite;

	char				*sky_pathfile;

	t_door				*doors;
	size_t				door_count;

	float				ambient_light;
}	t_level;

typedef struct s_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	
	float				sin_table[PRECALCULATED_TRIG];
	float				cos_table[PRECALCULATED_TRIG];

	t_player			player;
	float				*ambient_light;

	t_game_status		game_status;

	t_img				*game_menu_img;
	t_img				*game_menu_img2;
	t_img				*game_level_cleared_img;
	t_img				*game_won_img;

	t_img				*raycasting_scene_img;
	t_img				*final_frame_img;

	t_img				*minimap_base_img;
	t_img				*minimap_img;
	t_img				*ui_img;

	t_ray				*rays;

	t_map				*map;
	
	t_view				*view;

	char				keys[TRACKED_KEYS];
	t_mouse				mouse;

	t_sprite			*sprites;
	size_t				*sprite_count;
	t_sprite_texture	*sprite_textures;
	size_t				*sprite_texture_count;

	t_door				*doors;
	size_t				*door_count;
	
	t_sprite			*targeted_sprite;
	t_gametime			time;

	t_img				*sky_image;
	t_img				*message_img;

	void				*background_music;

	int					frames_drawn_count;

	t_weapon			*weapon;
	t_img				*weapon_img;
	int					weapon_current_frame;
	int 				weapon_is_animating;
	long				weapon_last_frame_time;

	t_level				levels[NUMBER_OF_LEVELS];
	int					active_level;

	int					gamescore;
	
	float				test_value_1;
	float				test_value_2;
	float				test_value_3;
	float				test_value_4;

	int					sprite_pulse_coef;
	int					sprite_pulse_step;

}	t_data;

int	debug_print(char *str);

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
bool	check_and_parse_mapfile(t_data *dt, char *map_file, int map_index);

void	check_and_parse_all_maps(t_data *dt, int argc, char *mapfiles[]);

bool		check_valid_identifier_texture(char *identifier);
bool		check_color(char *one_color);
bool		check_valid_color(char **color);
bool		check_only_number(char *str);
bool		check_valid_player(t_map *map);
bool		check_valid_color_or_texture(char **info);
bool		line_is_empty(char *line);
void		init_dt(t_data *dt);
bool		is_valid_line_texture(char *line);
bool		set_map_size_data(t_map *map, char *file);
bool		check_textures_are_valid(char *file);
bool		init_map_data(t_map *map, t_data *dt);
bool		init_2d_map(char ***array, size_t max_row,
						size_t max_col, t_data *dt);
bool		check_mapfile_extension(char *file, char *type);
void		remove_new_line(char *str);
char		*remove_space_beginner(char *str);
bool		parse_mapfile(char *file, t_data *dt, int i);
bool		init_default_map(t_map *map);
bool		init_player(t_map *map, t_player *player);
int			ft_open(char *file);
t_wall_orientation	check_valid_texture_identifier(char *identifier);
bool		check_all_textures(t_map *map);
bool		parse_mapfile_values(t_map *map, char *file);
void		parse_map(t_map *map, int fd, char **line);
void		get_init_player_position(t_map *map, t_player *player);
bool		set_color_or_texture(t_map *map, char *identifier, char **value);
bool		set_color(char *identifier, char **color, t_map *map);
bool		check_map_is_closed(t_map *map, t_player *player, t_data *dt);

char		get_cell_type(t_map *map, t_coor *coord);
t_mapcell	*get_cell_by_coordinates(t_map *map, size_t y, size_t x);
t_mapcell	*get_cell_by_coordinates_float(t_map *map, float y, float x);


char		**ft_split_by_multiple_delimiters(const char *s, char *c);

// player movements
int			move_forward_backward(t_data *dt, int direction);
int			move_sideways(t_data *dt, int is_to_the_right);
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
void	draw_lighter_circle(t_img *img, t_coor *coor, int radius, int clr);
void		draw_rectangle(t_img *img, t_coor top_left,
						t_coor bottom_right, int clr);

void		draw_square_from_center(t_img *img, t_coor *coor,
						int size, int clr);
void		draw_square_from_top_left(t_img *img, t_coor coor,
						int size, int clr);

void		print_level_map(t_map *map);

int			render_frame(void *param);
void		render_ui(t_data *dt);

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
int			draw_minimap_thin_wall_vertical(t_data *dt,
						size_t curr_col, size_t curr_row);
int			draw_minimap_door_vertical(t_data *dt,
						size_t curr_col, size_t curr_row);
int			draw_minimap_door_horizontal(t_data *dt, size_t curr_col, size_t curr_row);
int			draw_minimap_sprite(t_data *dt, size_t curr_col, size_t curr_row);
int			draw_minimap_wall_cell(t_data *dt, size_t curr_col,
						size_t curr_row);

// 3d render
int			load_image(t_data *dt, t_img *img, char *filepath);
int			draw_sky(t_data *dt);
void		render_3d_scene(t_data *dt);
int			draw_ceiling(t_data *dt);
int			draw_floor(t_data *dt);
int			draw_textured_floor(t_data *dt);
// int			draw_textured_floor2(t_data *dt);
int 		draw_textured_ceiling(t_data *dt);
int			render_sprite(t_data *dt, t_sprite *sprite, t_coor *offset,
						t_coor *sprite_size);
float		fix_fish_eye(t_ray *ray, t_player *player);
int			fix_fish_eye_2(t_ray *ray, t_player *player, float *distance);
int			load_sprite_textures(t_data *dt, int i);
int			load_textures(t_data *dt, t_level *level);
int			load_sprites(t_data *dt, t_level *level, t_map *map, int i);
int			precalculate_trig_tables(t_data *dt);

void		render_3d_each_ray(t_data *dt, t_ray *ray, int screen_slice_width);

int			apply_distance_shadow(t_ray *ray, int *color);
int			apply_shadow(t_ray *ray, int *color, float strength);

int			reset_mouse_position(t_data *dt);
void		process_keyboard_keypresses(t_data *dt);
int			get_color_render3d(t_data *dt, t_ray *ray, t_coor *tex_coor);
void		calc_texture_coor(t_data *dt, int *texture_y, \
							float *distance_to_wall, int d);

// inits
void		init_doors(t_data *dt, t_level *level, t_map *map);

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
t_sprite	*find_sprite_at(t_data *dt, int x, int y);

//sprites
void		find_all_sprites(t_data *dt, t_map *map, int i);
void		sort_sprites(t_sprite *sprites, size_t num_sprites);
void		sort_sprites_by_distance(t_data *dt);
void		sort_sprites(t_sprite *sprites, size_t num_sprites);
int			render_all_sprites(t_data *dt);
int			get_position_and_render_sprite(t_data *dt, t_sprite *sprite);
bool		set_sprite_textures(t_data *dt, int i);
void		sprite_put_color(t_data *dt, t_sprite *sprite, \
										t_coor *coor, t_coor *tex_coor);
t_coor		calculate_tex_x_y(t_sprite_texture *texture, t_coor *coor, \
									t_coor *offset, t_sprite *sprite, int row, int col);
bool		sprite_is_closer_than_wall(t_data *dt, t_coor *coor, \
															t_sprite *spr);
int			init_keys(t_data *dt);
void		init_graphic(t_data *dt);
void		init_text_sprites(t_sprite_texture *texture);
int			load_ui_messages(t_data *dt);
void		setup_view(t_data *dt);

int			create_color_rgba(int r, int g, int b, int a);
int			create_color_rgb(int r, int g, int b);

int			move_sideways(t_data *dt, int to_the_right);
int			move_forward_backward(t_data *dt, int direction);
int			map_position_is_walkable(t_data *dt, float *new_x, float *new_y);

int			render_ui_message(t_data *dt);
void		free_graphic_images(t_data *dt);
void	free_mlx(t_data *dt);
void		free_wall_tile_texture(t_data *dt);
void		free_texture(t_data *dt, t_texture *texture);
void		free_img(t_img *img, void *mlx_ptr);
void		free_sprites(t_data *dt);
void		ft_free(void *ptr);
// int			count_sprite_textures(t_data *dt);
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
void		print_enemy_info(t_data *dt, void *mlx, void *win, int *y);

int	load_sprite_images(t_data *dt, int i);
int			load_weapons(t_data *dt);

void		show_player_info(t_data *dt);

int	apply_ambient_light_shading(int distance, int *color);

int	mimic_fullscreen(void);

void	check_and_parse_args(t_data *dt, int argc, char **argv);

int		init_default_textures(t_map *map);

int print_out_texture_lookup_table(t_data *dt);

int		get_lookup_table_index(char *str);
int		get_lookup_table_index_cell_type(int cell_type);
int		get_lookup_table_index_cell_type_by_map_char(int map_char);

int mark_all_cells_that_neighbour_doors(t_data *dt);

int is_in_list(char *str, char *list);

int		fire_gun(t_data *dt);

int		print_out_texture_lookup_table(t_data *dt);

int		setup_dt(t_data *dt);

void	draw_flashlight(t_data *dt, t_img *img, int radius, int clr);

void	show_level_info(t_data *dt);

int		keypress_exit(t_data *dt);

t_level *get_curr_level(t_data *dt);

int				debug_print(char *str);
unsigned long	get_focused_window_id(void);;
int				move_active_window_to_mouse_position_with_xdotool(void);
int				move_mouse_to_center_of_active_window(void);
int				setup_keyboard_and_mouse_controls(t_data *dt);

int 		process_sprite_pickups(t_data *dt);
int process_game_status(t_data *dt);
int	bob_weapon(t_data *dt);
void	bob_walls(t_data *dt);
int	update_prompt_message(t_data *dt);

int update_current_level_pointers(t_data *dt);

int play_sound(char *system_call);

int flash_color(t_data *dt, int color);


#endif
