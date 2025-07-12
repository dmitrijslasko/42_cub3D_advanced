/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:32 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:33 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture(t_data *dt, t_texture *texture)
{
	if (!texture)
		return ;
	if (texture->texture_img && dt->mlx_ptr)
	{
		mlx_destroy_image(dt->mlx_ptr, texture->texture_img);
		texture->texture_img = NULL;
	}
	if (texture->file)
	{
		free(texture->file);
		texture->file = NULL;
	}
}
