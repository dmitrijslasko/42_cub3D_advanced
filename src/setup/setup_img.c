/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:28 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/10 20:13:40 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	setup_img(t_data *dt, t_img *img, size_t width, size_t height)
{
	print_separator_default();
	printf("Image setup...");
#ifdef __EMSCRIPTEN__
	img->mlx_img = NULL;
	img->width = width;
	img->height = height;
	img->bpp = 32;
	img->line_len = (int)(width * 4);
	img->endian = 0;
	if (img == dt->final_frame_img && width == WINDOW_W && height == WINDOW_H)
		img->addr = (char *)dt->framebuffer;
	else
		img->addr = (char *)protected_malloc(width * height * 4, dt);
	printf(" Done!\n");
	return (EXIT_SUCCESS);
#else
	img->mlx_img = mlx_new_image(dt->mlx_ptr, width, height);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	printf(" Done!\n");
	return (EXIT_SUCCESS);
#endif
}
