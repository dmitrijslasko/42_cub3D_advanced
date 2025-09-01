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

int img_pix_get(t_img *img, int x, int y)
{
    char    *dst;

    dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    return (*(unsigned int*)dst);
}

int lighten_color(int color, float factor)
{
    int r = (color >> 16) & 0xFF;
    int g = (color >> 8) & 0xFF;
    int b = color & 0xFF;

    r += (int)((255 - r) * factor);
    g += (int)((255 - g) * factor);
    b += (int)((255 - b) * factor);

    return ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
}

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

void	draw_lighter_circle(t_img *img, t_coor *coor, int radius, int clr)
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
				{
						int old = img_pix_get(img, curr_x, curr_y);
						int new = lighten_color(old, 0.2f);
						img_pix_put(img, curr_x, curr_y, new);
				}
			}
			++curr_y;
		}
		++curr_x;
	}
}

void	draw_flashlight(t_data *dt, t_img *img, int radius, int clr)
{
	int	curr_x;
	int	curr_y;
	int	dx;
	int	dy;

	t_coor coor;

	coor.x = WINDOW_W / 2;
	coor.y = WINDOW_H / 2;

	curr_x = (int)coor.x - radius;
	
	size_t ray_index;

	while (curr_x < (int)coor.x + radius)
	{
		ray_index = curr_x;
		curr_y = (int)coor.y - radius;
		while (curr_y <= (int)coor.y + radius)
		{
			dx = curr_x - (int)coor.x;
			dy = curr_y - (int)coor.y;
			if (dx * dx + dy * dy <= radius * radius)
			{
				if (pixel_is_in_window(curr_x, curr_y))
				{
						int old = img_pix_get(img, curr_x, curr_y);
						float	intensity = 0.2f + 0.5f/dt->rays[ray_index].corrected_distance_to_wall;
						intensity = fmin(0.8f, intensity);
						// printf("%f\n", intensity);
						int new = lighten_color(old, intensity);
						img_pix_put(img, curr_x, curr_y, new);
				}
			}
			++curr_y;
		}
		++curr_x;
	}
}
