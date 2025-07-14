/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:01 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/14 19:19:41 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		count_possible_textures(void)
{
	int	result;
	int i;

	result = 0;
	i = 0;
	while(g_texture_lookup[i].mapfile_id)
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
		textures[i].type = g_texture_lookup[i].mapfile_id;
		i++;
	}
	return (EXIT_SUCCESS);
}

bool	parse_mapfile(char *file, t_data *dt)
{
	//int	possible_textures;

	//possible_textures = count_possible_textures();
	//printf("Possible textures (based on the texture lookup table): %d\n", possible_textures);
	//dt->map.number_of_textures = possible_textures;
	//dt->map.m_textures = protected_malloc(dt->map.number_of_textures, dt);
	//printf("Malloc'ed an array of %d elements.\n", dt->map.number_of_textures);

	if (init_default_map(&dt->map))
		return (1);
	// Sets the map size
	if (set_map_size_data(&dt->map, file))
		return (1);
	// Initiliazes the map with empty cell values
	if (init_map_data(&dt->map, dt))
		return (1);
	// Parses mapfile values
	if (parse_mapfile_values(&dt->map, file))
		return (1);
	print_out_texture_lookup_table(dt);
	// if (!check_valid_player(&dt->map))
	// 	return (1);
	// NOTE DL: Probably can be removed for advanced part since we don't care about color / texture checks
	// if (check_all_textures(&dt->map))
	// 	return (1);
}
