/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_dda_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:02 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/15 16:34:55 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_hit_door_cell(t_coor *coor, t_data *dt)
{
	return (ft_strchr(DOOR_TYPES, dt->map.map_data[coor->y][coor->x]));
}

int	run_dda_loop(t_data *dt, t_ray *ray, t_dda_info *info)
{
	int	door_hit;

	door_hit = 0;
	while (info->map->x < dt->map.map_size_cols
		&& info->map->y < dt->map.map_size_rows)
	{
		step_and_set_side(info);
		ray->hit_side = *(info->hit_side);
		update_ray_distance_to_cell_edge(dt, ray, info->map);
		update_ray_hit_point(dt, ray);
		if (check_hit_door_cell(info->map, dt))
		{
			door_hit = check_door_hit(dt, ray, info->map);
			if (door_hit)
				break ;
		}
		if (check_hit_wall(info->map, &dt->map, ray, *(info->hit_side)))
			break ;
	}
	return (door_hit);
}
