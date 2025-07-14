/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:39:14 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/14 18:41:35 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

// # ifndef M_PI
// #  define M_PI 3.141592
// # endif
#define M_PI 3.14159265358979323846

# ifndef BONUS
#  define BONUS 0
# endif

// window name
# define WINDOW_NAME       "cub3D - fvargas & dmlasko @ 42Berlin"
# define VERSION_INFO      "cub3D project - 42 Berlin - dmlasko, v2.0"

# define SHOW_CALCULATION_LOGS				1
# define SHOW_DEBUG_INFO 					1

# define TILE_SIZE  						64

// bonus part
# define SKY_TXT_PATHFILE	"./textures/sky_1.xpm"

// window size
# define WINDOW_W							640
# define WINDOW_H							360
# define CASTED_RAYS_COUNT					640
# define FPS								60
# define SCALING				            250
# define MIMIC_FULLSCREEN                   1
# define LINUX_22                           0

# define STARTING_AMMO_LEVEL				9
// constants.h or at the top of your .c file
// 10 samples per degree
# define TRIG_PRECISION                      20
# define PRECALCULATED_TRIG                  7200

# define TRACKED_KEYS						70000

// dummy map
# define DUMMY_MAP_TOP						"1111111111111111111111111111111"
# define DUMMY_MAP_MID						"1000001001001000000000001001001"
# define DUMMY_MAP_MID_2					"1000001000000000000000000000001"
# define DUMMY_MAP_PLAYER					"10N0000000000000000000000000001"

// Minimap settings
# define MINIMAP_OFFSET_X					20
# define MINIMAP_OFFSET_Y					20

# define MINIMAP_BACKGROUND_COLOR			ORANGE

# define MINIMAP_STYLE                      0   // 0 - square, 1 - circle
# define MINIMAP_SIZE                       200
# define MINIMAP_GRID_SIZE					20
# define MINIMAP_GRID_COLOR					0xFF8800
# define MINIMAP_GRID_ENABLE				1

# define MINIMAP_WALL_CELL_COLOR			DARKGREY
# define MINIMAP_PLAYER_SPAWN_CELL_COLOR	0xFFBB00
# define MINIMAP_DOOR_COLOR					BLACK
# define MINIMAP_THIN_WALL_COLOR			BLACK
# define MINIMAP_SPRITE_COLOR				RED

# define MINIMAP_DOOR_THICKNESS_PX			3

# define MINIMAP_PLAYER_SIZE_PX 			5
# define MINIMAP_PLAYER_DISPLAY_STYLE 		CIRCLE
# define MINIMAP_PLAYER_COLOR 				WHITE

# define MINIMAP_RAY_LENGTH		            2

# define MINIMAP_DIRECTION_RAY_ENABLE       1
# define MINIMAP_DIRECTION_RAY_COLOR		MAGENTA

# define MINIMAP_RENDER_RAYS_ENABLE         1
# define MINIMAP_RENDER_RAY_COLOR		    YELLOW
# define MINIMAP_DRAW_EVERY_NTH_RENDER_RAY  5
# define MINIMAP_ENABLE_ON_START            0

// gameplay
# define FIELD_OF_VIEW_DEG					60.0f
# define FIELD_OF_VIEW_SCALE				0.5774f //tan(FIELD_OF_VIEW_DEG / 2)

# define DEF_DOOR_OFFSET_X					0.5f
# define DEF_DOOR_OFFSET_Y					0.5f

// colors
# define DEF_BG_COLOR			    		BLACK
# define DEF_CEILING_COLOR					GREEN
# define DEF_FLOOR_COLOR					ORANGE
# define DEF_WALL_COLOR						PINK

# define MIN_DISTANCE_TO_WALL				0.4f
# define DOOR_OPEN_VALUE                    1.0f

// default scale
# define KEYBOARD_PLAYER_STEP_FORWARD		0.05f
# define KEYBOARD_PLAYER_STEP_BACKWARD		0.025f
# define KEYBOARD_PLAYER_STEP_SIDE 			0.025f
# define KEYBOARD_PLAYER_ROTATION_STEP 		2.0f
# define KEYBOARD_VERTICAL_LOOK_STEP        10.0f
# define MOVE_SPEED_MULTIPLIER_SLOW 		2.4f
# define MOVE_SPEED_MULTIPLIER_FAST			1.5f

# define ENABLE_VERTICAL_LOOK				1
# define VERTICAL_LOOK_LOCK_UP				100
# define VERTICAL_LOOK_LOCK_DOWN			100

// mouse sensitivity
# define ENABLE_MOUSE       				1
# define MOUSE_SENS_ROTATE 					2.0f
//# define MOUSE_SENS_DRAG					0.05f
# define MOUSE_SENS_SCROLL 					0.1f
# define MOUSE_CENTER_TOLERANCE_PX			20

# define ENABLE_CROSSHAIR					1
# define DEFAULT_CROSSHAIR_COLOR			WHITE
# define DEFAULT_CROSSHAIR_SIZE				5

// separator
# define DEF_SEPARATOR_CHAR					"-"
# define DEF_SEPARATOR_WIDTH				80
# define DEF_SEPARATOR_COUNT				1

// menu & UI
# define DBG_MN_NL	 					10
# define DBG_MN_NL_2					20
# define UI_CLR_1    	    			WHITE
# define UI_CLR_2    	    			GOLD
# define DBG_1_X						380
# define DBG_2_X						540
# define DBG_FIELD_OFFST_Y				20
# define UI_MESSAGE_OFFSET_Y			700

// welcome screens
# define REQUIRED_MAP_EXTENSION			".cub"

# define WELCOME_IMAGE       				"./assets/images/intro.xpm"
# define SHOW_WELCOME_IMAGE  				0

// all printable ASCII characters + fallback texture
# define NUMBER_TEXTURES    	            20

# define WHITESPACE        	            	" \a\b\t\n\v\f\r"

# define PLAYER_SPAWN_POINT_TYPES			"NSWE"
# define SPRITE_TYPES     	 	            "abcdefghijklmnopqrstuvwxyz"
# define SPRITE_FRAMES						2
# define WALL_TYPES							"123456789"
# define VERTICAL_WALL_TYPES				"v"
# define HORIZONTAL_WALL_TYPES				"h"
# define DOOR_TYPES							"|-"
# define VERTICAL_DOOR_TYPES				"|"
# define HORIZONTAL_DOOR_TYPES				"--"

// shaders
# define ENABLE_SHADERS						1
# define DISTANCE_SHADOW_STRENGTH 			0.2f

# define ENABLE_MOVING_SKY					1
# define ROTATION_SCALE					    1
# define ENABLE_BOBBING                     1

# define RENDER_SPRITES                     1
#endif
