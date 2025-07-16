/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray_distance.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:32 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/15 14:46:13 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_ray_distance(t_data *dt, t_ray *ray,
			t_x_y *delta_dist, t_x_y *side_dist)
{
	t_coor		map_coor;
	t_coor		step;
	char		hit_side;
	int			door_hit;
	t_dda_info	info;

	door_hit = 0;
	hit_side = 0;
	init_raycasting(&step, &map_coor, dt, ray);
	info.map = &map_coor;
	info.step = &step;
	info.delta = delta_dist;
	info.side = side_dist;
	info.hit_side = &hit_side;
	door_hit = run_dda_loop(dt, ray, &info);
	finish_ray_casting(dt, ray, &map_coor, door_hit);
	ray->corrected_distance_to_wall = fix_fish_eye(ray, &dt->player);
}
