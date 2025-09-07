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
	char		*xpm_file_pathfile;
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
	SKY,
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
	DOOR_1_SIDES,
	DOOR_2,
	DOOR_2_SIDES,
	DOOR_3,
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
	const char				*map_char;
}							t_texture_match;

static const t_texture_match	g_texture_lookup[] = {
{"DEF", "default fallback texture", 	DEFAULT, 				NULL},

{"SKY", "sky texture", 					SKY, 					NULL},

// floor / ceiling
{"F1", "floor 1 texture", 				FLOOR, 					" "},
{"C1", "ceiling 1 texture", 			CEILING, 				" "},

// regular cells
{"W01", "wall 1 texture", 				WALL_1, 				"1"},
{"W02", "wall 2 texture", 				WALL_2, 				"2"},
{"W03", "wall 3 texture", 				WALL_3, 				"3"},
{"W04", "wall 4 texture", 				WALL_4, 				"4"},
{"W05", "wall 5 texture", 				WALL_5, 				"5"},
{"W06", "wall 6 texture", 				WALL_6, 				"6"},
{"W07", "wall 7 texture", 				WALL_7, 				"7"},
{"W08", "wall 8 texture", 				WALL_8, 				"8"},
{"W09", "wall 9 texture", 				WALL_9, 				"9"},

// thin walls
{"TWV01", "thin v wall 1 texture", 		THIN_WALL_VERTICAL_1, 	"v"},
{"TWH01", "thin h wall 1 texture", 		THIN_WALL_HORIZONTAL_1, "h"},

// doors
{"DOOR_01", "door 1 texture", 			DOOR_1, 				"|-"},
{"DOOR_01_S", "door 1 texture sides", 	DOOR_1_SIDES, 			NULL},
{"DOOR_02", "door 2 texture", 			DOOR_2, 				"[="},
{"DOOR_02_S", "door 2 texture sides",	DOOR_2_SIDES, 			NULL},
{"DOOR_03", "door 3 texture", 			DOOR_3, 				"]_"},
{"DOOR_03_S", "door 3 texture sides ", 	DOOR_3_SIDES,			 NULL},

// elevator
{"ED1", "elevator door 1 texture", 		ELEVATOR_DOOR_1, 		"*"},
{"EH1", "elevator 1 (h) texture", 		ELEVATOR_HORIZONTAL_1, 	"*"},

// sentinel
{ NULL, NULL, -1, NULL}
};

#endif
