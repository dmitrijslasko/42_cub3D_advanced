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

bool	parse_map_file(t_data *dt, char *file)
{
	if (!check_type_file(file, REQUIRED_MAP_EXTENSION))
		return (1);
	if (!check_valid_wall_tile_file(file))
		return (1);
	if (init_value_map_data(file, dt))
		return (1);
	if (init_value_player(&dt->map, &dt->player))
		return (1);
	if (!map_is_closed(&dt->map, &dt->player, dt))
		return (1);
	return (0);
}
