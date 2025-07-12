/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_ray_hit_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:18 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:08:19 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_ray_hit_point(t_data *dt, t_ray *ray)
{
	ray->wall_hit.x = dt->player.pos.x
		+ ray->vector.x * ray->distance_to_wall;
	ray->wall_hit.y = dt->player.pos.y
		+ ray->vector.y * ray->distance_to_wall;
}
