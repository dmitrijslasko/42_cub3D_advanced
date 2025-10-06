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
	img->mlx_img = mlx_new_image(dt->mlx_ptr, width, height);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	printf(" Done!\n");
	return (EXIT_SUCCESS);
}
