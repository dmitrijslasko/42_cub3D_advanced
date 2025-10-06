/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pix_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:12 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:13 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	uint32_t	*pixel;

	pixel = (uint32_t *)(img->addr + (y * img->line_len + x * sizeof(uint32_t)));
	*pixel = (uint32_t)color;
}

// // NOTE DL: Nice experimental feature :)
// /**
// * @brief Img_pix_put with alpha channel support.
// *
// * @param img
// * @param x
// * @param y
// * @param color
// */
// void img_pix_put(t_img *img, int x, int y, int color)
// {

// 	int bytes_per_pixel = img->bpp / 8;
// 	char *pixel = img->addr + (y * img->line_len + x * bytes_per_pixel);

// 	// Extract RGBA based on whether alpha is present
// 	unsigned int raw = color;
// 	int has_alpha = (raw > 0xFFFFFF);
// 	unsigned char alpha = has_alpha ? (raw & 0xFF) : 255;

// 	unsigned char r = (raw >> (has_alpha ? 24 : 16)) & 0xFF;
// 	unsigned char g = (raw >> (has_alpha ? 16 : 8)) & 0xFF;
// 	unsigned char b = (raw >> (has_alpha ? 8 : 0)) & 0xFF;

// 	if (alpha == 255)
// 	{
// 		// Fully opaque — write directly
// 		if (img->endian == 0)
// 		{
// 			pixel[0] = b;
// 			pixel[1] = g;
// 			pixel[2] = r;
// 		}
// 		else
// 		{
// 			pixel[0] = r;
// 			pixel[1] = g;
// 			pixel[2] = b;
// 		}
// 	}
// 	else
// 	{
// 		// Alpha blending
// 		for (int i = 0; i < 3; i++)
// 		{
// 			unsigned char src = (i == 0) ? b : (i == 1) ? g : r;
// 			unsigned char dst = (unsigned char)pixel[i];
// 			pixel[i] = (dst * (255 - alpha) + src * alpha) / 255;
// 		}
// 	}
// }
