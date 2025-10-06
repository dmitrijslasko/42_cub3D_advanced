/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:04:59 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:00 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rectangle(t_img *img, t_coor top_left, \
						t_coor bottom_right, int clr)
{
	t_coor	current_vertical_line;

	while (top_left.x < bottom_right.x)
	{
		current_vertical_line.x = top_left.x;
		current_vertical_line.y = bottom_right.y;
		draw_vertical_line(img, top_left, current_vertical_line, clr);
		set_coor_values(&top_left, top_left.x + 1, top_left.y);
	}
}
