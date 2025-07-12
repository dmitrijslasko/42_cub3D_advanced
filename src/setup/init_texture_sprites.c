/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:59 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:10:00 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_text_sprites(t_sprite_texture *texture)
{
	size_t	i;

	i = 0;
	while (i < SPRITE_FRAMES)
	{
		texture->sprite_data[i] = NULL;
		texture->sprite_img[i] = NULL;
	}
	texture->filepath = NULL;
}
