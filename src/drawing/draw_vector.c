/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:03 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:04 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_ray(t_data *dt, t_coor origin, t_x_y dir, int color)
{
	t_coor	curr;
	t_coor	prev;
	t_x_y	player_pos;
	float	step_size;
	int		ray_length;

	ray_length = 0;
	step_size = 1.0f;
	set_values_x_y(&player_pos, origin.x, origin.y);
	while (ray_length < MINIMAP_GRID_SIZE * MINIMAP_RAY_LENGTH)
	{
		prev = curr;
		curr.x = (size_t)player_pos.x;
		curr.y = (size_t)player_pos.y;
		if (ray_length > 0)
		{
			draw_line(dt->minimap_img, prev, curr, color);
		}
		player_pos.x += dir.x * step_size;
		player_pos.y += dir.y * step_size;
		ray_length += step_size;
	}
}
