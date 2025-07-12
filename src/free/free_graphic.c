/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:24 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:25 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_graphic(t_data *dt)
{
	free_img(dt->raycasting_scene_img, dt->mlx_ptr);
	free_img(dt->final_frame_img, dt->mlx_ptr);
	free_img(dt->minimap_base_img, dt->mlx_ptr);
	free_img(dt->minimap_img, dt->mlx_ptr);
	free_img(dt->sky_image, dt->mlx_ptr);
	free_img(dt->message_img, dt->mlx_ptr);
	if (dt->win_ptr)
		mlx_destroy_window(dt->mlx_ptr, dt->win_ptr);
	if (dt->mlx_ptr)
	{
		mlx_destroy_display(dt->mlx_ptr);
		free(dt->mlx_ptr);
	}
	dt->mlx_ptr = NULL;
	dt->win_ptr = NULL;
}
