/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:04:20 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:04:21 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sin_cos_theta(t_data *dt, float *angle_degrees, 
							float *sin_theta, float *cos_theta)
{
	float	f_index;
	int		index_base;
	int		index_next;
	float	t;

	f_index = *angle_degrees * TRIG_PRECISION;
	index_base = (int)f_index;
	t = f_index - index_base;
	index_next = (index_base + 1) % PRECALCULATED_TRIG;
	*cos_theta = (1.0f - t) * dt->cos_table[index_base] + \
				(t) * dt->cos_table[index_next];
	*sin_theta = (1.0f - t) * dt->sin_table[index_base] + \
				(t) * dt->sin_table[index_next];
}

// Normalize angle
// Convert to float index in table
// Interpolate for smoothness
// Rotate vector
t_x_y	rotate_vector(t_x_y *vec, float angle_degrees, t_data *dt)
{
	t_x_y	result;
	float	cos_theta;
	float	sin_theta;

	while (angle_degrees < 0)
		angle_degrees += 360;
	while (angle_degrees >= 360)
		angle_degrees -= 360;
	ft_sin_cos_theta(dt, &angle_degrees, &sin_theta, &cos_theta);
	result.x = vec->x * cos_theta - vec->y * sin_theta;
	result.y = vec->x * sin_theta + vec->y * cos_theta;
	return (result);
}
