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
	if (!check_type_file(map_file, REQUIRED_MAP_EXTENSION))
		return (1);

	if (!check_valid_wall_tile_file(map_file))
		return (1);

	if (parse_map_file(map_file, dt))
		return (1);

	if (init_player(&dt->map, &dt->player))
		return (1);

	// if (map_is_closed(&dt->map, &dt->player, dt) == False)
	// 	return (1);

	return (0);
}
