#ifndef WEAPONS_LOOKUP_H
# define WEAPONS_LOOKUP_H

# include "cub3d.h"

typedef enum e_active_item
{
	WEAPON_NO_WEAPON = 0,
	WEAPON_KNIFE,
	WEAPON_PISTOL,
	WEAPON_AUTOMATIC_GUN,
	WEAPON_MACHINE_GUN
}	t_active_item;


typedef struct s_weapon_data
{
	const int 				type;
	const char				*description;
	const int				clip_size;
	const float				shot_speed;
	const float				reload_speed;
	const int				max_distance;
	const float				weight;
}							t_weapon_data;


static const t_weapon_data	g_weapon_lookup[] = {
{WEAPON_NO_WEAPON, 		"NONE", 		0, 		1.0f, 	3.0f, 	0,	 	0.0f},
{WEAPON_KNIFE, 			"KNIFE", 		0, 		1.0f, 	3.0f, 	1, 		1.0f},
{WEAPON_PISTOL, 		"PISTOL", 		9, 		1.0f, 	3.0f, 	30, 	0.0f},
{WEAPON_AUTOMATIC_GUN, 	"AUTOMATIC", 	30, 	1.0f, 	3.0f, 	50, 	0.0f},
{WEAPON_MACHINE_GUN, 	"MACHINE GUN", 	100, 	1.0f, 	3.0f, 	70, 	0.0f},
{-1, 					NULL, 			-1, 	-1, 	-1,		-1, 	-1}
};

#endif
