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

int	load_weapons(t_data *dt)
{
	size_t	i;
	size_t	j;

	print_separator_default();
	printf(TXT_YELLOW ">>> LOADING WEAPONS\n" TXT_RESET);

	// dt->weapon_img = protected_malloc(sizeof(t_img) * 5, dt);
	dt->weapon = malloc(sizeof(t_weapon) * 5);
	
	i = 0;
	while (g_weapon_lookup[i].type != -1)
	{
		dt->weapon[i].type = g_weapon_lookup[i].type;
		dt->weapon[i].description = g_weapon_lookup[i].description;
		dt->weapon[i].clip_size = g_weapon_lookup[i].clip_size;
		dt->weapon[i].reload_speed = g_weapon_lookup[i].reload_speed;
		dt->weapon[i].shot_speed = g_weapon_lookup[i].shot_speed;
		dt->weapon[i].rounds_fired = g_weapon_lookup[i].rounds_fired;
		dt->weapon[i].weight = g_weapon_lookup[i].weight;
		dt->weapon[i].total_ammo = STARTING_AMMO_LEVEL;
		dt->weapon[i].max_distance = g_weapon_lookup[i].max_distance;
		dt->weapon[i].bullets_in_clip = 0;
		dt->weapon[i].player_has_it = 1;
		dt->weapon[i].frames = protected_malloc(sizeof(t_img) * 5, dt);
		j = 0;
		while (j < 5)
		{
			char path[64];
			g_weapon_lookup[i].max_distance;
			// snprintf(path, sizeof(path), "%s%s%d%s", g_weapon_lookup[i].frames_path, "frame", j, ".xpm");
			snprintf(path, sizeof(path), "%sframe%d.xpm", g_weapon_lookup[i].frames_path, j);
			load_image(dt, &dt->weapon[i].frames[j], path);
			j++;
		}
		i++;
	}

	printf(TXT_GREEN "Done!\n" TXT_RESET);
	return (EXIT_SUCCESS);
}
