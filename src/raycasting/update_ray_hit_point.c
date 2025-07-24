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

#define EPSILON 0.0001

size_t get_cell_index(double pos, double ray_dir_component)
{
	if (ray_dir_component < 0)
		return (size_t)(pos - EPSILON); // Ray coming from right or bottom
	else
		return (size_t)pos; // Ray coming from left or top
}

void	update_ray_hit_point(t_data *dt, t_ray *ray)
{
	t_mapcell	*cell;

	ray->wall_hit.x = dt->player.pos.x
		+ ray->vector.x * ray->distance_to_wall;
	ray->wall_hit.y = dt->player.pos.y
		+ ray->vector.y * ray->distance_to_wall;

	size_t map_y = get_cell_index(ray->wall_hit.y, ray->vector.y);
	size_t map_x = get_cell_index(ray->wall_hit.x, ray->vector.x);

	cell = get_cell_by_coordinates(&dt->map, map_y, map_x);
	ray->hit_cell = cell;
	if (cell->is_near_door)
		ray->door = cell->door;
}
