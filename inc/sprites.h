#ifndef SPRITES_H
# define SPRITES_H

# include "cub3d.h"

typedef struct s_sprite_file
{
	const char	map_char;
	const char	*mapfile_key;
	int			is_sprite_sheet;
	const float	orientation;
	char		*filepath[2];
}				t_sprite_file;


static const t_sprite_file	g_sprites[] = {
// pickups
{'+',	"SPRITE_01", 0, 	0, 		{"./sprites/heart.xpm", "./sprites/heart.xpm"}},
{'$',	"SPRITE_02", 0, 	0, 		{"./sprites/sushi/sushi-12.xpm", "./sprites/sushi/sushi-12.xpm"}},

{'A',	"SPRITE_03", 0, 	0, 		{"./sprites/sushi/sushi-1.xpm", "./sprites/sushi/sushi-1.xpm"}},
{'B',	"SPRITE_04", 0, 	0, 		{"./sprites/sushi/sushi-2.xpm", "./sprites/sushi/sushi-2.xpm"}},
{'C',	"SPRITE_05", 0, 	0, 		{"./sprites/sushi/sushi-3.xpm", "./sprites/sushi/sushi-3.xpm"}},
{'D',	"SPRITE_03", 0, 	0, 		{"./sprites/sushi/sushi-4.xpm", "./sprites/sushi/sushi-4.xpm"}},

{'F',	"SPRITE_04", 0, 	0, 		{"./sprites/sushi/sushi-5.xpm", "./sprites/sushi/sushi-5.xpm"}},
{'G',	"SPRITE_05", 0, 	0, 		{"./sprites/sushi/sushi-6.xpm", "./sprites/sushi/sushi-6.xpm"}},
{'H',	"SPRITE_03", 0, 	0, 		{"./sprites/sushi/sushi-7.xpm", "./sprites/sushi/sushi-7.xpm"}},
{'I',	"SPRITE_04", 0, 	0, 		{"./sprites/sushi/sushi-8.xpm", "./sprites/sushi/sushi-8.xpm"}},

{'J',	"SPRITE_05", 0, 	0, 		{"./sprites/sushi/sushi-9.xpm", "./sprites/sushi/sushi-9.xpm"}},
{'K',	"SPRITE_05", 0, 	0, 		{"./sprites/sushi/sushi-10.xpm", "./sprites/sushi/sushi-10.xpm"}},
{'L',	"SPRITE_05", 0, 	0, 		{"./sprites/sushi/sushi-11.xpm", "./sprites/sushi/sushi-11.xpm"}},
{'M',	"SPRITE_05", 0, 	0, 		{"./sprites/sushi/sushi-12.xpm", "./sprites/sushi/sushi-12.xpm"}},

// decorsss
{'O',	"SPRITE_03", 0, 	0, 		{"./sprites/tree.xpm", "./sprites/tree.xpm"}},
{'P',	"SPRITE_04", 0, 	0, 		{"./sprites/sakura.xpm", "./sprites/sakura.xpm"}},

// enemies
{'a',	"SPRITE_05", 1, 	0.0f, 	{"./sprites/yellow_soldier.xpm", "./sprites/yellow_soldier.xpm"}},
{'b',	"SPRITE_05", 1, 	90.0f, 	{"./sprites/yellow_soldier.xpm", "./sprites/yellow_soldier.xpm"}},
{'c',	"SPRITE_05", 1, 	180.0f, {"./sprites/yellow_soldier.xpm", "./sprites/yellow_soldier.xpm"}},
{'d',	"SPRITE_05", 1, 	270.0f, {"./sprites/yellow_soldier.xpm", "./sprites/yellow_soldier.xpm"}},
{'i',	"SPRITE_06", 1, 	180.0f, {"./sprites/yellow_soldier.xpm", "./sprites/yellow_soldier.xpm"}},
{'q',	"SPRITE_07", 1, 	0, 		{"./sprites/soldier-1-sprite-sheet.xpm", "./sprites/soldier-1-sprite-sheet.xpm"}},

// sentinel
{0, 	NULL, 		0, 		0, 		{NULL, NULL}}
};

#endif
