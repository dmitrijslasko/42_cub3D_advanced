/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:04:45 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:04:46 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_img *img, int color)
{
	int	current_x;
	int	current_y;
	int	width;
	int	height;

	current_y = 0;
	width = img->width;
	height = img->height;
	while (current_y <= width)
	{
		current_x = 0;
		while (current_x <= height)
		{
			img_pix_put(img, current_x, current_y, color);
			current_x++;
		}
		current_y++;
	}
}
