/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:24 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:06:25 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_valid_player(t_map *map)
{
	int		count;

	count = count_elements_in_the_map(map, PLAYER_SPAWN_POINT_TYPES);
	if (count == 0)
		return (error_msg("Error: Player not found.", 0));
	else if (count > 1)
		return (error_msg("Error: Multiple player spawn points found.", 0));
	return (1);
}
