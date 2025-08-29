/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sprite_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:43 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:08:44 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	find_sprite_texture(t_data *dt)
{
	size_t	i;
	size_t	j;

	if (!dt->sprites || !dt->sprite_textures)
		return (0);
	
	i = 0;
	while (i < dt->sprite_count)
	{
		j = 0;
		while (j < dt->sprite_texture_count)
		{
			if (dt->sprites[i].type == dt->sprite_textures[j].map_char)
			{
				dt->sprites[i].texture = &dt->sprite_textures[j];
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}
