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

bool	set_texture(t_map *map, char *identifier, char *texture_file)
{
	t_wall_orientation	wall_orientation;

	wall_orientation = check_valid_texture_identifier(identifier);
	printf("%d\n", wall_orientation);
	// if (map->textures[wall_orientation].wall_orientation != DEFAULT_WALL)
	// 	return (error_msg("Error: set texture: duplicated wall/door/floor.", 1));
	map->textures[wall_orientation].wall_orientation = wall_orientation;
	map->textures[wall_orientation].texture.file = ft_substr(texture_file, 0, ft_strlen(texture_file));
	return (0);
}
