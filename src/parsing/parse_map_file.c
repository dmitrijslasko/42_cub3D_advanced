/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:08 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/16 19:25:31 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
bool	check_and_parse_mapfile(t_data *dt, char *map_file, int map_index)
{
	print_separator_default();
	if (!check_mapfile_extension(map_file, REQUIRED_MAP_EXTENSION))
		return (EXIT_FAILURE);

	if (!check_textures_are_valid(map_file))
		return (EXIT_FAILURE);
	
	dt->map = &dt->levels[map_index].map;
	if (parse_mapfile(map_file, dt, map_index))
		return (EXIT_FAILURE);
	print_level_map(dt->map);
	if (init_player(dt->map, &dt->player))
		return (EXIT_FAILURE);

	// if (check_map_is_closed(dt->map, &dt->player, dt) == False)
	//  	return (EXIT_FAILURE);
	printf("Parsing finished!\n");
	return (EXIT_SUCCESS);
}
