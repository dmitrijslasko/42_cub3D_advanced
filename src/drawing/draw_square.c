/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:01 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:02 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square_from_center(t_img *img, t_coor *coor, int size, int clr)
{
	int	curr_x;
	int	curr_y;

	curr_x = coor->x - size / 2;
	while (curr_x <= coor->x + size / 2)
	{
		curr_y = coor->y - size / 2;
		while (curr_y <= coor->y + size / 2)
		{
			img_pix_put(img, curr_x, curr_y, clr);
			++curr_y;
		}
		++curr_x;
	}
}

void	draw_square_from_top_left(t_img *img, t_coor coor, int size, int clr)
{
	int	curr_x;
	int	curr_y;

	curr_x = coor.x;
	while (curr_x <= coor.x + size)
	{
		curr_y = coor.y;
		while (curr_y <= coor.y + size)
		{
			img_pix_put(img, curr_x, curr_y, clr);
			curr_y++;
		}
		curr_x++;
	}
}
