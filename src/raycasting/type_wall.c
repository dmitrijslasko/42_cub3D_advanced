/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:15 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 16:07:00 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_wall_orientation(t_ray *ray)
{
	int		wall_orientation;
	char	hit_side;

	hit_side = ray->hit_side;
	if (hit_side == 'y' && ray->vector.y < 0)
		wall_orientation = SOUTH;
	else if (hit_side == 'y')
		wall_orientation = NORTH;
	else if (hit_side == 'x' && ray->vector.x < 0)
		wall_orientation = EAST;
	else
		wall_orientation = WEST;
	ray->wall_orientation = wall_orientation;
}
