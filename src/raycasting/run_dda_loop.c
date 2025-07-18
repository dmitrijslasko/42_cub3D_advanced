/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_dda_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:02 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/18 17:21:57 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_hit_door_cell(t_coor *coor, t_data *dt)
{
	return (ft_strchr(DOOR_TYPES, dt->map.map_data[coor->y][coor->x].cell_char));
}

int	run_dda_loop(t_data *dt, t_ray *ray, t_dda_info *dda_info)
{
	int	door_hit;

	door_hit = 0;
	if (check_hit_door_cell(dda_info->map_coor, dt))
	{
		door_hit = check_door_hit(dt, ray, dda_info->map_coor);
		if (door_hit)
			return (door_hit);
	}

	while (dda_info->map_coor->x < dt->map.map_size_cols
		&& dda_info->map_coor->y < dt->map.map_size_rows)
	{
		step_and_set_side(dda_info);
		ray->hit_side = *(dda_info->hit_side);
		update_ray_distance_to_cell_edge(dt, ray, dda_info->map_coor);
		update_ray_hit_point(dt, ray);

		// handle doors
		if (check_hit_door_cell(dda_info->map_coor, dt))
		{
			door_hit = check_door_hit(dt, ray, dda_info->map_coor);
			if (door_hit)
				break ;
		}
		if (check_hit_wall(dda_info->map_coor, &dt->map, ray, *(dda_info->hit_side)))
			break ;
	}
	return (door_hit);
}
