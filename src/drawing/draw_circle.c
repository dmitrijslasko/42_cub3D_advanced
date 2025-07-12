/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:04:48 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:04:49 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_circle(t_img *img, t_coor *coor, int radius, int clr)
{
	int	curr_x;
	int	curr_y;
	int	dx;
	int	dy;

	curr_x = (int)coor->x - radius;
	while (curr_x < (int)coor->x + radius)
	{
		curr_y = (int)coor->y - radius;
		while (curr_y <= (int)coor->y + radius)
		{
			dx = curr_x - (int)coor->x;
			dy = curr_y - (int)coor->y;
			if (dx * dx + dy * dy <= radius * radius)
			{
				if (pixel_is_in_window(curr_x, curr_y))
					img_pix_put(img, curr_x, curr_y, clr);
			}
			++curr_y;
		}
		++curr_x;
	}
}
