/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:26 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:27 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_img(t_img *img, void *mlx_ptr)
{
	if (!img || !mlx_ptr)
		return ;
	if (img->mlx_img)
		mlx_destroy_image(mlx_ptr, img->mlx_img);
	img->mlx_img = NULL;
}
