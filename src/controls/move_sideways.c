/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sideways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:03:54 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 18:15:22 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO DL: rewrite this to reuse what we have in forward/backward move
int	move_sideways(t_data *dt, int to_the_right)
{
	t_x_y	*player_pos;
	float	new_x;
	float	new_y;
	t_x_y	rotated_vector;

	dt->has_changed = 1;
	dt->player.is_moving = 1;
	player_pos = &(dt->player.pos);
	rotated_vector = rotate_vector(&dt->player.direction_vector, \
									90.0f * to_the_right, dt);
	new_x = player_pos->x + rotated_vector.x * \
				KEYBOARD_PLAYER_STEP_SIDE * dt->player.move_speed_multiplier;
	new_y = player_pos->y + rotated_vector.y * \
				KEYBOARD_PLAYER_STEP_SIDE * dt->player.move_speed_multiplier;
	if (map_position_is_walkable(dt, &new_x, &new_y))
	{
		player_pos->x = new_x;
		player_pos->y = new_y;
	}
	else if (map_position_is_walkable(dt, &new_x, &player_pos->y))
		player_pos->x = new_x;
	else if (map_position_is_walkable(dt, &player_pos->x, &new_y))
		player_pos->y = new_y;
	return (EXIT_SUCCESS);
}
