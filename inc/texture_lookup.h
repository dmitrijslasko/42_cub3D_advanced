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
	DOOR_VERTICAL_1,
	DOOR_VERTICAL_2,
	ELEVATOR_DOOR_1,
	DOOR_HORIZONTAL_1,
	DOOR_HORIZONTAL_2,
	ELEVATOR_VERTICAL_1,
	ELEVATOR_HORIZONTAL_1,
}	t_texture_type;


typedef struct s_texture_match
{
	const int				texture_id;
	const char				*mapfile_id;
	const char				*description;
	const int				texture_type;
	const char				map_repr;
}							t_texture_match;

static const t_texture_match	g_texture_lookup[] = {
{0, "DEF", "default fallback texture", DEFAULT, 0},
{1, "F1", "floor 1 texture", FLOOR, ' '},
{2, "C1", "ceiling 1 texture", CEILING, ' '},
{3, "W01", "wall 1 texture", WALL_1, '1'},
{4, "W02", "wall 2 texture", WALL_2, '2'},
{5, "W03", "wall 3 texture", WALL_3, '3'},
{6, "W04", "wall 4 texture", WALL_4, '4'},
{7, "W05", "wall 5 texture", WALL_5, '5'},
{8, "W06", "wall 6 texture", WALL_6, '6'},
{9, "W07", "wall 7 texture", WALL_7, '7'},
{10, "W08", "wall 8 texture", WALL_8, '8'},
{11, "W09", "wall 9 texture", WALL_9, '9'},
{12, "D01", "door 1 texture", DOOR_1, '|'},
{12, "D02", "door 2 texture", DOOR_2, '['},
{14, "ED1", "elevator door 1 texture", ELEVATOR_DOOR_1, '*'},
{15, "EH1", "elevator 1 (h) texture", ELEVATOR_HORIZONTAL_1, '*'},
{-1, NULL, NULL, -1, 0}
};

#endif
