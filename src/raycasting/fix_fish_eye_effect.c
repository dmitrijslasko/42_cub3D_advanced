/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_fish_eye_effect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:43 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:07:44 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * 	fish-eye correction - angle_cos
 */
float	fix_fish_eye(t_ray *ray, t_player *player)
{
	float	angle_cos;

	angle_cos = ray->vector.x * player->orientation_vector.x + \
				ray->vector.y * player->orientation_vector.y;
	return (ray->distance_to_wall * angle_cos);
}

/**
 * 	fish-eye correction - angle_cos
 */
int	fix_fish_eye_2(t_ray *ray, t_player *player, float *distance)
{
	float	angle_cos;

	angle_cos = ray->vector.x * player->orientation_vector.x + \
				ray->vector.y * player->orientation_vector.y;
	*distance *= angle_cos;
	return (EXIT_SUCCESS);
}
