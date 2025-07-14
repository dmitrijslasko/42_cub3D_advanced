/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:08 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 18:14:17 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_and_parse_map_file(t_data *dt, char *map_file)
{
	if (!check_mapfile_extension(map_file, REQUIRED_MAP_EXTENSION))
		return (EXIT_FAILURE);

	if (!check_textures_are_valid(map_file))
		return (EXIT_FAILURE);

	if (parse_mapfile(map_file, dt))
		return (EXIT_FAILURE);

	if (init_player(&dt->map, &dt->player))
		return (EXIT_FAILURE);

	// if (check_map_is_closed(&dt->map, &dt->player, dt) == False)
	// 	return (1);

	return (EXIT_SUCCESS);
}
