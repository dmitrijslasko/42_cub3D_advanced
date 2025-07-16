#ifndef TEXTURE_LOOKUP_H
# define TEXTURE_LOOKUP_H

# include "cub3d.h"

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		a;
}	t_color;

typedef struct s_texture
{
	char		*xpm_file;
	void		*texture_img;
	int			*texture_data;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
	int			type;
	char 		*mapfile_repr;
}	t_texture;

typedef struct s_wall_tile
{
	t_texture	texture;
	int			wall_orientation;
	t_color		color;
	bool		is_color;
}	t_wall_tile;

typedef enum e_texture_type
{
	DEFAULT = 0,
	FLOOR,
	CEILING,
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
	DOOR_1,
	DOOR_2,
	DOOR_3,
	DOOR_1_SIDES,
	DOOR_2_SIDES,
	DOOR_3_SIDES,
	DOOR_4,
	DOOR_5,
	DOOR_6,
	ELEVATOR_DOOR_1,
	DOOR_HORIZONTAL_1,
	DOOR_HORIZONTAL_2,
	ELEVATOR_VERTICAL_1,
	ELEVATOR_HORIZONTAL_1,
}	t_texture_type;


typedef struct s_texture_match
{
	const char				*mapfile_key;
	const char				*description;
	const int				texture_type;
	const char				map_char;
}							t_texture_match;

static const t_texture_match	g_texture_lookup[] = {
{"DEF", "default fallback texture", DEFAULT, 0},
{"F1", "floor 1 texture", FLOOR, ' '},
{"C1", "ceiling 1 texture", CEILING, ' '},
{"W01", "wall 1 texture", WALL_1, '1'},
{"W02", "wall 2 texture", WALL_2, '2'},
{"W03", "wall 3 texture", WALL_3, '3'},
{"W04", "wall 4 texture", WALL_4, '4'},
{"W05", "wall 5 texture", WALL_5, '5'},
{"W06", "wall 6 texture", WALL_6, '6'},
{"W07", "wall 7 texture", WALL_7, '7'},
{"W08", "wall 8 texture", WALL_8, '8'},
{"W09", "wall 9 texture", WALL_9, '9'},
{"DOOR_01", "door 1 texture", DOOR_1, '|'},
{"DOOR_02", "door 2 texture", DOOR_2, '['},
{"DOOR_03", "door 3 texture", DOOR_3, ']'},
{"DOOR_01_S", "door 1 texture sides", DOOR_1_SIDES, 0},
{"DOOR_02_S", "door 2 texture sides", DOOR_2_SIDES, 0},
{"DOOR_03_S", "door 3 texture sides ", DOOR_3_SIDES, 0},
{"ED1", "elevator door 1 texture", ELEVATOR_DOOR_1, '*'},
{"EH1", "elevator 1 (h) texture", ELEVATOR_HORIZONTAL_1, '*'},
{ NULL, NULL, -1, 0}
};

typedef struct s_sprite_file
{
	const char	map_char;
	const char	*mapfile_key;
	char		*filepath[2];
}				t_sprite_file;

static const t_sprite_file	g_sprites[] = {
{'s', "SPRITE_01", {"./sprites/heart.xpm", "./sprites/heart.xpm"}},
{'d', "SPRITE_02", {"./sprites/chain-link.xpm", "./sprites/chain-link.xpm"}},
{'p', "SPRITE_03", {"./sprites/plant-2-128x128.xpm", "./sprites/plant-2-128x128.xpm"}},
{'h', "SPRITE_04", {"./sprites/sammy1.xpm", "./sprites/sammy2.xpm"}},
{'a', "SPRITE_05", {"./sprites/tommy1.xpm", "./sprites/tommy2.xpm"}},
};

#endif
