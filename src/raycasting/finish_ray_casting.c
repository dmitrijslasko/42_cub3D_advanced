/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_ray_casting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:40 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/15 16:33:09 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	finish_ray_casting(t_data *dt, t_ray *ray,
			t_coor *map_coor, int door_hit)
{
	// printf("Finishing ray casting...\n");
	set_cell_type(dt, ray, map_coor);
	if (door_hit == 1)
		ray->distance_to_wall += ray->distance_to_door;
	set_wall_orientation(ray);
	set_perc_wall(&dt->player.pos, ray);
}
