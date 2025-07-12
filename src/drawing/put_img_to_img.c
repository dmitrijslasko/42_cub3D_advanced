/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:15 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:16 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)(img->addr + \
		(y * img->line_len + x * (img->bpp / 8))));
}

static void	put_pixel(t_img *img, int x, int y, unsigned int color)
{
	*(unsigned int *)(img->addr + (y * img->line_len + \
		x * (img->bpp / 8))) = color;
}

void	put_img_to_img_circle(t_img *dest, t_img *src, int dx, int dy)
{
	size_t			x;
	size_t			y;
	int				src_x;
	int				src_y;
	unsigned int	color;
	size_t				dist_x;
	size_t				dist_y;

	y = 0;
	while ((int)y < dest->height)
	{
		x = 0;
		while ((int)x < dest->width)
		{
			src_x = x - dx;
			src_y = y - dy;
			if (x < MINIMAP_SIZE / 2)
				dist_x = MINIMAP_SIZE / 2 - x;
			else 
				dist_x = x - MINIMAP_SIZE / 2;
			if (y < MINIMAP_SIZE / 2)
				dist_y = MINIMAP_SIZE / 2 - y;
			else 
				dist_y = y - MINIMAP_SIZE / 2;
			if ((dist_x * dist_x + dist_y * dist_y) > (MINIMAP_SIZE / 2) * (MINIMAP_SIZE / 2) - 20) 
			{
				x++;
				continue;
			}
			if (src_x >= 0 && src_y >= 0 && src_x <= \
				(int)src->width && src_y <= (int)src->height)
			{
				color = get_pixel(src, src_x, src_y);
				put_pixel(dest, x, y, color);
			}
			x++;
		}
		y++;
	}
}

void	put_img_to_img(t_img *dest, t_img *src, int dx, int dy)
{
	size_t			x;
	size_t			y;
	int				src_x;
	int				src_y;
	unsigned int	color;

	y = 0;
	while ((int)y < dest->height)
	{
		x = 0;
		while ((int)x < dest->width)
		{
			src_x = x - dx;
			src_y = y - dy;
			if (src_x >= 0 && src_y >= 0 && src_x <= \
				(int)src->width && src_y <= (int)src->height)
			{
				color = get_pixel(src, src_x, src_y);
				if (color != BLACK)
					put_pixel(dest, x, y, color);
			}
			x++;
		}
		y++;
	}
}
