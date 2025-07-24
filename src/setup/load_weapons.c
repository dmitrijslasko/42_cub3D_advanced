/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_weapons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:10 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/24 18:44:52 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_weapon_frame(t_data *dt, int i, const char* filename)
{
	int	w;
	int	h;

	dt->weapon_img[i].mlx_img = mlx_xpm_file_to_image(dt->mlx_ptr,
			filename, &w, &h);
	if (!dt->weapon_img[i].mlx_img)
	{
		fprintf(stderr, "Failed to load weapon_img\n");
		return (EXIT_FAILURE);
	}
	dt->weapon_img[i].width = w;
	dt->weapon_img[i].height = h;
	dt->weapon_img[i].addr = mlx_get_data_addr(dt->weapon_img[i].mlx_img,
			&dt->weapon_img[i].bpp, &dt->weapon_img[i].line_len,
			&dt->weapon_img[i].endian);
	printf(TXT_GREEN "Loaded frame: %s\n" TXT_RESET, filename);
}

typedef struct s_weapon_data
{
	const int 				type;
	const char				*description;
	const int				clip_size;
	const float				shot_speed;
	const float				reload_speed;
	const float				weight;
}							t_weapon_data;

static const t_weapon_data	g_weapon_lookup[] = {
{WEAPON_NO_WEAPON, "NONE", 0, 1.0f, 3.0f, 0.0f},
{WEAPON_KNIFE, "KNIFE", 0, 1.0f, 3.0f, 0.0f},
{WEAPON_PISTOL, "PISTOL", 9, 1.0f, 3.0f, 0.0f},
{WEAPON_AUTOMATIC_GUN, "AUTOMATIC", 30, 1.0f, 3.0f, 0.0f},
{WEAPON_MACHINE_GUN, "MACHINE GUN", 100, 1.0f, 3.0f, 0.0f},
{-1, NULL, -1, -1, -1, -1}
};


int	load_weapons(t_data *dt)
{
	size_t	i;

	print_separator_default();
	printf(TXT_YELLOW ">>> LOADING WEAPONS\n" TXT_RESET);
	dt->weapon_img = protected_malloc(sizeof(t_img) * 5, dt);

	dt->weapon = malloc(sizeof(t_weapon) * 5);
	i = 0;
	while (g_weapon_lookup[i].type != -1)
	{
		dt->weapon[i].type = g_weapon_lookup[i].type;
		dt->weapon[i].description = g_weapon_lookup[i].description;
		dt->weapon[i].clip_size = g_weapon_lookup[i].clip_size;
		dt->weapon[i].reload_speed = g_weapon_lookup[i].reload_speed;
		dt->weapon[i].shot_speed = g_weapon_lookup[i].shot_speed;
		dt->weapon[i].weight = g_weapon_lookup[i].weight;
		dt->weapon[i].total_ammo = STARTING_AMMO_LEVEL;
		dt->weapon[i].bullets_in_clip = 0;
		dt->weapon[i].player_has_it = 1;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		char path[64];
		snprintf(path, sizeof(path), "./ui/pistol/frame%d.xpm", i);
		// snprintf(path, sizeof(path), "./ui/hands/frame.xpm", i);
		load_weapon_frame(dt, i, path);
		i++;
	}
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	return (EXIT_SUCCESS);
}
