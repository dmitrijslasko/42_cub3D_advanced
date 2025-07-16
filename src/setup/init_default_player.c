/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_default_player_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:41 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:09:42 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Initiliaze player starting values.
 */
bool	init_default_player_values(t_player *player)
{
	player->can_move = true;
	player->is_moving = 0;
	player->move_speed_multiplier = 1;
	player->direction_vector_deg = 0.0f;
	player->plane_x = 0;
	player->plane_y = 0;
	set_values_x_y(&player->direction_vector, 0, 1);
	set_values_x_y(&player->pos, 0, 0);
	return (0);
}

bool	init_player(t_map *map, t_player *player)
{
	if (init_default_player_values(player))
		return (1);
	get_init_player_position(map, player);
	return (0);
}
