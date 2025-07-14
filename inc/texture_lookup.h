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
	DOOR_VERTICAL_1,
	DOOR_VERTICAL_2,
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
	const size_t			mapfile_len;
	const int				texture_type;
	const char				map_repr;
}							t_texture_match;

static const t_texture_match	g_texture_lookup[] = {
{0, "DEF", "default fallback texture", 3, DEFAULT, 0},
{1, "F1", "floor 1 texture", 2, FLOOR, ' '},
{2, "C1", "ceiling 1 texture", 2, CEILING, ' '},
{3, "W1", "wall 1 texture", 2, WALL_1, '1'},
{4, "W2", "wall 2 texture", 2, WALL_2, '2'},
{5, "W3", "wall 3 texture", 2, WALL_3, '3'},
{6, "W4", "wall 4 texture", 2, WALL_4, '4'},
{7, "W5", "wall 5 texture", 2, WALL_5, '5'},
{8, "W6", "wall 6 texture", 2, WALL_6, '6'},
{9, "W7", "wall 7 texture", 2, WALL_7, '7'},
{10, "W8", "wall 8 texture", 2, WALL_8, '8'},
{11, "W9", "wall 9 texture", 2, WALL_9, '9'},
{12, "D1", "door 1 texture", 2, DOOR_1, '|'},
{14, "EV1", "elevator 1 (v) texture", 3, ELEVATOR_VERTICAL_1, '^'},
{15, "EH1", "elevator 1 (h) texture", 3, ELEVATOR_HORIZONTAL_1, '*'},
{-1, NULL, NULL, -1, -1, 0}
};

#endif
