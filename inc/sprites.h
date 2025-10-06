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
{'+',	"SPRITE_01", 0, 	0, 		{"./assets/sprites/heart.xpm", "./assets/sprites/heart.xpm"}},
{'$',	"SPRITE_02", 0, 	0, 		{"./assets/sprites/items/switch-level-2.xpm", "./assets/sprites/items/switch-level-2.xpm"}},

{'A',	"SPRITE_03", 0, 	0, 		{"./assets/sprites/sushi/sushi-1.xpm", "./assets/sprites/sushi/sushi-1.xpm"}},
{'B',	"SPRITE_04", 0, 	0, 		{"./assets/sprites/sushi/sushi-2.xpm", "./assets/sprites/sushi/sushi-2.xpm"}},
{'C',	"SPRITE_05", 0, 	0, 		{"./assets/sprites/sushi/sushi-3.xpm", "./assets/sprites/sushi/sushi-3.xpm"}},
{'D',	"SPRITE_03", 0, 	0, 		{"./assets/sprites/sushi/sushi-4.xpm", "./assets/sprites/sushi/sushi-4.xpm"}},

{'F',	"SPRITE_04", 0, 	0, 		{"./assets/sprites/sushi/sushi-5.xpm", "./assets/sprites/sushi/sushi-5.xpm"}},
{'G',	"SPRITE_05", 0, 	0, 		{"./assets/sprites/sushi/sushi-6.xpm", "./assets/sprites/sushi/sushi-6.xpm"}},
{'H',	"SPRITE_03", 0, 	0, 		{"./assets/sprites/sushi/sushi-7.xpm", "./assets/sprites/sushi/sushi-7.xpm"}},
{'I',	"SPRITE_04", 0, 	0, 		{"./assets/sprites/sushi/sushi-8.xpm", "./assets/sprites/sushi/sushi-8.xpm"}},

{'J',	"SPRITE_05", 0, 	0, 		{"./assets/sprites/sushi/sushi-9.xpm", "./assets/sprites/sushi/sushi-9.xpm"}},
{'K',	"SPRITE_05", 0, 	0, 		{"./assets/sprites/sushi/sushi-10.xpm", "./assets/sprites/sushi/sushi-10.xpm"}},
{'L',	"SPRITE_05", 0, 	0, 		{"./assets/sprites/sushi/sushi-11.xpm", "./assets/sprites/sushi/sushi-11.xpm"}},
{'M',	"SPRITE_05", 0, 	0, 		{"./assets/sprites/test-texture.xpm", "./assets/sprites/test-texture.xpm"}},

// decors / furniture / static sprites
{'O',	"SPRITE_03", 0, 	0, 		{"./assets/sprites/tree.xpm", "./assets/sprites/tree.xpm"}},
{'P',	"SPRITE_04", 0, 	0, 		{"./assets/sprites/sakura.xpm", "./assets/sprites/sakura.xpm"}},
{'Q',	"SPRITE_04", 0, 	0, 		{"./assets/sprites/items/table-empty.xpm", "./assets/sprites/items/table-empty.xpm"}},
{'R',	"SPRITE_04", 0, 	0, 		{"./assets/sprites/items/table-fritz.xpm", "./assets/sprites/items/table-fritz.xpm"}},
{'T',	"SPRITE_04", 0, 	0, 		{"./assets/sprites/items/table-mate.xpm", "./assets/sprites/items/table-mate.xpm"}},
{'U',	"SPRITE_04", 0, 	0, 		{"./assets/sprites/items/lucky-cat.xpm", "./assets/sprites/items/lucky-cat.xpm"}},
{'V',	"SPRITE_04", 0, 	0, 		{"./assets/sprites/sakura.xpm", "./assets/sprites/sakura.xpm"}},
{'X',	"SPRITE_04", 0, 	0, 		{"./assets/sprites/sakura.xpm", "./assets/sprites/sakura.xpm"}},
{'Y',	"SPRITE_04", 0, 	0, 		{"./assets/sprites/sakura.xpm", "./assets/sprites/sakura.xpm"}},
{'Z',	"SPRITE_04", 0, 	0, 		{"./assets/sprites/items/lantern_1.xpm", "./assets/sprites/items/lantern_1.xpm"}},

// enemies
{'a',	"SPRITE_05", 1, 	0.0f, 	{"./assets/sprites/yellow_soldier.xpm", "./assets/sprites/yellow_soldier.xpm"}},
{'b',	"SPRITE_05", 1, 	90.0f, 	{"./assets/sprites/yellow_soldier.xpm", "./assets/sprites/yellow_soldier.xpm"}},
{'c',	"SPRITE_05", 1, 	180.0f, {"./assets/sprites/yellow_soldier.xpm", "./assets/sprites/yellow_soldier.xpm"}},
{'d',	"SPRITE_05", 1, 	270.0f, {"./assets/sprites/yellow_soldier.xpm", "./assets/sprites/yellow_soldier.xpm"}},

{'e',	"SPRITE_05", 1, 	0.0f, 	{"./assets/sprites/pink_soldier.xpm", "./assets/sprites/pink_soldier.xpm"}},
{'f',	"SPRITE_05", 1, 	90.0f, 	{"./assets/sprites/pink_soldier.xpm", "./assets/sprites/pink_soldier.xpm"}},
{'g',	"SPRITE_05", 1, 	180.0f, {"./assets/sprites/pink_soldier.xpm", "./assets/sprites/pink_soldier.xpm"}},
{'h',	"SPRITE_05", 1, 	270.0f, {"./assets/sprites/pink_soldier.xpm", "./assets/sprites/pink_soldier.xpm"}},

{'i',	"SPRITE_06", 1, 	180.0f, {"./assets/sprites/yellow_soldier.xpm", "./assets/sprites/yellow_soldier.xpm"}},
{'q',	"SPRITE_07", 1, 	0, 		{"./assets/sprites/soldier-1-sprite-sheet.xpm", "./assets/sprites/soldier-1-sprite-sheet.xpm"}},

// sentinel
{0, 	NULL, 		0, 		0, 		{NULL, NULL}}
};

#endif
