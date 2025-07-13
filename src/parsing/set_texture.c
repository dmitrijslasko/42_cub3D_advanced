/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:19 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 18:32:24 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	set_texture(char *identifier, char *file_texture, t_map *map)
{
	t_wall_orientation	wall_orientation;

	wall_orientation = check_valid_identifier_texture_wall(identifier);
	// if (map->textures[wall_orientation].wall_orientation != DEFAULT_WALL)
	// 	return (error_msg("Error: set texture: duplicated wall/door/floor.", 1));
	map->textures[wall_orientation].wall_orientation = wall_orientation;
	map->textures[wall_orientation].texture.file = ft_substr(file_texture, 0, \
												ft_strlen(file_texture));
	return (0);
}
