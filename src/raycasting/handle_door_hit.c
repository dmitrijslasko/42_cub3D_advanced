/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door_hit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:50 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/18 17:22:07 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_door_hit(t_data *dt, t_ray *ray, t_coor *map)
{
	int	door_hit;
	t_coor	door_coor;

	door_hit = ray_hits_door(dt, map, ray);
	door_coor.x = ray->door->cell_x;
	door_coor.y = ray->door->cell_y;
	if (ray->door->orientation == 1)
	{
		if (ray->door_hit_coor.y < ray->door->cell_y + ray->door->open_progress)
			return (0);
	}
	else if (ray->door->orientation == 0)
	{
		if (ray->door_hit_coor.x < ray->door->cell_x + ray->door->open_progress)
			return (0);
	}
	return (door_hit);
}
