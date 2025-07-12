/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:04:56 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:04:57 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vertical_line(t_img *img, t_coor pt_1, t_coor pt_2, int color)
{
	int	curr_y;

	if (pt_1.y > pt_2.y)
		swap(&pt_1, &pt_2, sizeof(t_coor));
	curr_y = pt_1.y;
	while (curr_y < pt_2.y)
	{
		img_pix_put(img, pt_1.x, curr_y, color);
		++curr_y;
	}
}

void	set_step_bresenham(t_x_y *step, t_coor *d, t_coor p1, t_coor p2)
{
	set_value_coor(d, abs((int)p2.x - (int)p1.x), abs((int)p2.y - (int)p1.y));
	if (p1.x < p2.x)
		step->x = 1;
	else
		step->x = -1;
	if (p1.y < p2.y)
		step->y = 1;
	else
		step->y = -1;
}

/**
 * @brief Draw a line using the Bresenhamn algorithm.
 *
 * @param dt
 * @param pt1
 * @param pt2
 * @param color
 */
void	draw_line(t_img *img, t_coor p1, t_coor p2, int color)
{
	t_coor	d;
	t_x_y	step;
	int		err;
	int		e2;

	set_step_bresenham(&step, &d, p1, p2);
	err = d.x - d.y;
	while (1)
	{
		img_pix_put(img, p1.x, p1.y, color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e2 = 2 * err;
		if (e2 > -(int)d.y)
		{
			err -= d.y;
			p1.x += step.x;
		}
		if (e2 < (int)d.x)
		{
			err += d.x;
			p1.y += step.y;
		}
	}
}

// TODO DL: refactor by norm.The currect implementation provided by ChatGPT. :)
	// int dx = abs((int)pt2.x - (int)pt1.x);
	// int dy = abs((int)pt2.y - (int)pt1.y);
	// int sx = (pt1.x < pt2.x) ? 1 : -1;
	// int sy = (pt1.y < pt2.y) ? 1 : -1;
	// int err = dx - dy;
	// int e2;
// void	set_step_bresenham(int *sx, int *sy, t_coor *d, t_coor p1, t_coor p2)
// {
// 	set_value_coor(d, abs((int)p2.x - (int)p1.x), abs((int)p2.y - (int)p1.y));
// 	if (p1.x < p2.x)
// 		*sx = 1;
// 	else
// 		*sx = -1;
// 	if (p1.y < p2.y)
// 		*sy = 1;
// 	else
// 		*sy = -1;
// }

// void	draw_line(t_img *img, t_coor p1, t_coor p2, int color)
// {
// 	t_coor	d;
// 	int		err;
// 	int		sx;
// 	int		sy;
// 	int		e2;

// 	set_step_bresenham(&sx, &sy, &d, p1, p2);
// 	err = d.x - d.y;
// 	while (1)
// 	{
// 		img_pix_put(img, p1.x, p1.y, color);
// 		if (p1.x == p2.x && p1.y == p2.y)
// 			break ;
// 		e2 = 2 * err;
// 		if (e2 > -(int)d.y)
// 		{
// 			err -= d.y;
// 			p1.x += sx;
// 		}
// 		if (e2 < (int)d.x)
// 		{
// 			err += d.x;
// 			p1.y += sy;
// 		}
// 	}
// }
