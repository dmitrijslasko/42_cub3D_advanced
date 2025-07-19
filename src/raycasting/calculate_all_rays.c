/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_all_rays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:29 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/15 16:33:03 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calculate_all_rays(t_data *dt)
{
	size_t	i;
	t_x_y	vector;
	double	angle;

	if (CASTED_RAYS_COUNT == 1)
		angle = 0.0f;
	else
		angle = -FIELD_OF_VIEW_DEG / 2;
	i = 0;
	while (i < CASTED_RAYS_COUNT)
	{
		vector = rotate_vector(&dt->player.direction_vector, angle, dt);
		dt->rays[i].id = i;
		dt->rays[i].vector = vector;
		dt->rays[i].door = NULL;
		update_single_ray(dt, &dt->rays[i]);
		angle += FIELD_OF_VIEW_DEG / (CASTED_RAYS_COUNT - 1);
		i++;
	}
	return (EXIT_SUCCESS);
}
