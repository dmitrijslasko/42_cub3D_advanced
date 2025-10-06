/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward_backward.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:03:40 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/23 20:28:47 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_forward_backward(t_data *dt, int direction)
{
	t_x_y	*player_pos;
	float	new_x;
	float	new_y;
	float	speed;

	dt->player.is_moving = 1;
	player_pos = &dt->player.pos;
	speed = KEYBOARD_PLAYER_STEP_FORWARD;
	if (direction == -1)
		speed = KEYBOARD_PLAYER_STEP_BACKWARD;
	if (dt->jump_dir == 2)
		speed *= dt->player.jump_start_speed_multiplier * dt->player.selected_weapon->weight;
	else
		speed *= dt->player.move_speed_multiplier * dt->player.selected_weapon->weight;
	new_x = player_pos->x + dt->player.orientation_vector.x * speed * direction;
	new_y = player_pos->y + dt->player.orientation_vector.y * speed * direction;
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
