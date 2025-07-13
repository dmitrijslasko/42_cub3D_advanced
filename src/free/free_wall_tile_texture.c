/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_wall_tile_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:35 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:36 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_wall_tile_texture(t_data *dt)
{
	size_t	i;

	i = 0;
	while (i < NUMBER_TEXTURES)
	{
		if (!dt->map.textures[i].is_color)
			free_texture(dt, &dt->map.textures[i].texture);
		i++;
	}
	free_texture(dt, &dt->map.door.texture);
}
