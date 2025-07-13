/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_wall_tile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:04 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 18:52:24 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_all_wall_tile(t_map *map)
{
	int	i;

	i = 0;
	while (i < NUMBER_TEXTURES)
	{
		if (map->textures[i].wall_orientation == DEFAULT_WALL)
			return (error_msg("Error: Wall, floor or ceiling NOT DEFINED.", 0));
		if (i < NUMBER_TEXTURES - 2)
		{
			if (map->textures[i].is_color)
			{
				printf("Texture failed: %d\n", i);
				return (error_msg("Error: Walls need to be a texture.", 0));
			}
		}
		else
		{
			if (!map->textures[i].is_color)
				return (error_msg("Error: Ceiling / floor is not a color.", 0));
		}
		i++;
	}
	return (1);
}
