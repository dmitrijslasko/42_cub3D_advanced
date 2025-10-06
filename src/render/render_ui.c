/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:26 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:09:27 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_crosshair(t_data *dt, int color)
{
	t_coor	coor;

	coor.x = WINDOW_W / 2;
	coor.y = WINDOW_H / 2;
	draw_square_from_center(dt->final_frame_img, \
							&coor, \
							DEFAULT_CROSSHAIR_SIZE, \
							color);
}

void	render_ui(t_data *dt)
{
	if (ENABLE_CROSSHAIR)
		draw_crosshair(dt, DEFAULT_CROSSHAIR_COLOR);
}
