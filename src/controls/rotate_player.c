/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:04:14 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/12 20:21:54 by dmlasko          ###   ########.fr       */
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

	angle_rad = deg_to_rad(d_angle * -direction);
	old_dir_x = dt->player.orientation_vector.x;
	old_dir_y = dt->player.orientation_vector.y;
	dt->player.orientation_vector.x = old_dir_x * cosf(angle_rad) - \
									old_dir_y * sinf(angle_rad);
	dt->player.orientation_vector.y = old_dir_x * sinf(angle_rad) + \
									old_dir_y * cosf(angle_rad);

	dt->player.plane_x = dt->player.orientation_vector.y * (FIELD_OF_VIEW_SCALE);
	dt->player.plane_y = dt->player.orientation_vector.x * (FIELD_OF_VIEW_SCALE);

	dt->player.orientation += d_angle * -direction;
	if (dt->player.orientation >= 360.0f)
		dt->player.orientation -= 360.0f;
	else if (dt->player.orientation < 0.0f)
		dt->player.orientation += 360.0f;
}
