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
{'+', "SPRITE_01", 0, 0, {		"./sprites/heart.xpm", "./sprites/heart.xpm"}},
{'$', "SPRITE_02", 0, 0, {		"./sprites/key.xpm", "./sprites/key.xpm"}},
{'#', "SPRITE_02", 0, 0, {		"./sprites/sushi.xpm", "./sprites/sushi.xpm"}},

// decor
{'a', "SPRITE_03", 0, 0, {		"./sprites/plant.xpm", "./sprites/plant.xpm"}},
{'b', "SPRITE_04", 0, 0, {		"./sprites/plant-2-128x128.xpm", "./sprites/plant-2-128x128.xpm"}},

// enemies
{'A', "SPRITE_05", 1, 0.0f, {	"./sprites/yellow_soldier.xpm", "./sprites/yellow_soldier.xpm"}},
{'B', "SPRITE_06", 1, 180.0f, {	"./sprites/yellow_soldier.xpm", "./sprites/yellow_soldier.xpm"}},
{'C', "SPRITE_07", 1, 0, {		"./sprites/soldier-1-sprite-sheet.xpm", "./sprites/soldier-1-sprite-sheet.xpm"}},

// sentinel
{0, NULL, 0, 0, {NULL, NULL}}
};

#endif
