/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:29 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:30 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_sprites(t_data *dt)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < *dt->sprite_texture_count)
	{
		j = 0;
		while (j < SPRITE_FRAMES)
		{
			if (dt->sprite_textures[i].sprite_img[j])
				mlx_destroy_image(dt->mlx_ptr, \
									dt->sprite_textures[i].sprite_img[j]);
			dt->sprite_textures[i].sprite_img[j] = NULL;
			j++;
		}
		i++;
	}
	ft_free(dt->sprite_textures);
}
