/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:01 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/16 19:25:10 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		count_possible_textures(void)
{
	int	result;
	int i;

	result = 0;
	i = 0;
	while(g_texture_lookup[i].mapfile_key)
	{
		result++;
		i++;
	}
	return (result);
}

int		init_textures(t_texture *textures, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		textures[i].xpm_file = NULL;
		textures[i].type = g_texture_lookup[i].mapfile_key;
		i++;
	}
	return (EXIT_SUCCESS);
}

bool	parse_mapfile(char *file, t_data *dt, int i)
{
	print_separator_default();
	printf("Parsing mapfile...\n");
	if (init_default_map(&dt->levels[i].map))
		return (1);
	// Sets the map size
	if (set_map_size_data(&dt->levels[i].map, file))
		return (1);
	// Initiliazes the map with empty cell values
	if (init_map_data(&dt->levels[i].map, dt))
		return (1);
	// Parses mapfile values - textures and the map itself
	if (parse_mapfile_values(&dt->levels[i].map, file))
		return (1);
	//print_out_texture_lookup_table(dt);
	 if (!check_valid_player(&dt->levels[i].map))
	 	return (1);
	// NOTE DL: Probably can be removed for advanced part since we don't care about color / texture checks
	// if (check_all_textures(&dt->map))
	// 	return (1);
}
