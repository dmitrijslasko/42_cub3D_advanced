/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_or_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:13 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/15 14:01:43 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/**
 * A file texture should have this format .xpm
 */
bool	check_valid_texture(char **value)
{
	int		fd_texture_file;
	size_t	len;

	if (!value || !value[0] || value[1] || ft_strlen(value[0]) < 5)
		return (0);
	len = ft_strlen(value[0]);
	if (ft_strncmp(&(value[0])[len - 4], ".xpm", 4))
	{
		return (error_message2("Error: Improper texture file extension. Should be .xpm\n", value[0], 0));
		return (0);
	}
	fd_texture_file = open(value[0], O_RDONLY);
	if (fd_texture_file < 0)
		return (error_message2("Error: Error opening texture", value[0], 0));
	close(fd_texture_file);
	return (1);
}

bool	set_color_or_texture(t_map *map, char *identifier, char **xpm_filename)
{
	int	cell_type;
	// if (!identifier || !*xpm_filename)
	// 	return (error_msg("Error: Split failed.", 1));

	cell_type = check_valid_texture_identifier(identifier);
	// if (map->textures[wall_orientation].wall_orientation != DEFAULT_WALL)
	// 	return (error_msg("Error: set texture: duplicated wall/door/floor.", 1));
	map->textures[cell_type].wall_orientation = cell_type;
	map->textures[cell_type].texture.xpm_file = ft_strdup(*xpm_filename);
	map->textures[cell_type].texture.mapfile_repr = ft_strdup(identifier);
	return (EXIT_SUCCESS);
}
