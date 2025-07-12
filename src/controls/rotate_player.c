/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:04:14 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:04:15 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Rotate both direction and camera plane
// Rotate direction vector using rotation matrix
// Update stored angle, keeping it between 0 and 359
void	rotate_player(t_data *dt, float d_angle, int direction)
{
	float	angle_rad;
	float	old_dir_x;
	float	old_dir_y;

	dt->has_changed = 1;
	angle_rad = deg_to_rad(d_angle * -direction);
	old_dir_x = dt->player.direction_vector.x;
	old_dir_y = dt->player.direction_vector.y;
	dt->player.direction_vector.x = old_dir_x * cosf(angle_rad) - \
									old_dir_y * sinf(angle_rad);
	dt->player.direction_vector.y = old_dir_x * sinf(angle_rad) + \
									old_dir_y * cosf(angle_rad);
	dt->player.direction_vector_deg += d_angle * -direction;
	if (dt->player.direction_vector_deg >= 360.0f)
		dt->player.direction_vector_deg -= 360.0f;
	else if (dt->player.direction_vector_deg < 0.0f)
		dt->player.direction_vector_deg += 360.0f;
}
