/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:00 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:06:01 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_minimap(t_data *dt)
{
	int	dx;
	int	dy;
	t_coor	minimap_center;

	dx = MINIMAP_SIZE / 2 - dt->player.pos.x * MINIMAP_GRID_SIZE;
	dy = MINIMAP_SIZE / 2 - dt->player.pos.y * MINIMAP_GRID_SIZE;
	if (MINIMAP_STYLE == 0)
	{
		draw_background(dt->minimap_img, MINIMAP_WALL_CELL_COLOR);
		put_img_to_img(dt->minimap_img, dt->minimap_base_img, dx, dy);
	}
	else	
	{
		set_coor_values(&minimap_center, MINIMAP_OFFSET_X + MINIMAP_SIZE / 2, MINIMAP_OFFSET_Y + MINIMAP_SIZE / 2);
		draw_circle(dt->final_frame_img, &minimap_center, MINIMAP_SIZE / 2 + 10, BLACK);
		put_img_to_img_circle(dt->minimap_img, dt->minimap_base_img, dx, dy);
	}
	draw_minimap_player(dt);
	if (MINIMAP_RENDER_RAYS_ENABLE)
		draw_minimap_rays(dt, 0);
	if (MINIMAP_DIRECTION_RAY_ENABLE)
		draw_minimap_rays(dt, 1);
	return (EXIT_SUCCESS);
}
