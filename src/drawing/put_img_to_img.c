/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:15 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/23 17:18:07 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)(img->addr + (y * img->line_len + x * (img->bpp / 8))));
}

static void	put_pixel(t_img *img, int x, int y, unsigned int src_color)
{
	*(unsigned int *)(img->addr + (y * img->line_len + x * (img->bpp / 8))) = src_color;
}

void	put_img_to_img_circle(t_img *dest, t_img *src, int dx, int dy)
{
	size_t			x;
	size_t			y;
	int				src_x;
	int				src_y;
	unsigned int	src_color;
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
				src_color = get_pixel(src, src_x, src_y);
				put_pixel(dest, x, y, src_color);
			}
			x++;
		}
		y++;
	}
}

static unsigned int blend_50(unsigned int src, unsigned int dest)
{
	unsigned char sr = (src >> 16) & 0xFF;
	unsigned char sg = (src >> 8) & 0xFF;
	unsigned char sb = src & 0xFF;

	unsigned char dr = (dest >> 16) & 0xFF;
	unsigned char dg = (dest >> 8) & 0xFF;
	unsigned char db = dest & 0xFF;

	unsigned char r = (sr + dr) / 2;
	unsigned char g = (sg + dg) / 2;
	unsigned char b = (sb + db) / 2;

	return (r << 16) | (g << 8) | b;
}

void	put_img_to_img(t_img *dest_img, t_img *src_img, int dx, int dy)
{
	int				x;
	int				y;
	unsigned int	src_color;
	unsigned int	dest_color;

	y = 0;
	while (y < src_img->height)
	{
		x = 0;
		while (x < src_img->width)
		{
			if (x + dx >= 0 && y + dy >= 0
				&& x + dx < dest_img->width && y + dy < dest_img->height)
			{
				src_color = get_pixel(src_img, x, y);
				if (src_color != BLACK)
				{
					dest_color = get_pixel(dest_img, dx + x, dy + y);
					// put_pixel(dest_img, dx + x, dy + y, blend_50(src_color, dest_color));
					put_pixel(dest_img, dx + x, dy + y, src_color);
				}
			}
			x++;
		}
		y++;
	}
}
