/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_or_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:13 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:07:14 by fvargas          ###   ########.fr       */
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
		return (0);
	fd_texture_file = open(value[0], O_RDONLY);
	if (fd_texture_file < 0)
		return (error_message2("Error: Opening texture", value[0], 0));
	close(fd_texture_file);
	return (1);
}

bool	set_color_or_texture(t_map *map, char *identifier, char **value)
{
	if (!identifier || !*value)
		return (error_msg("Error: Split.", 1));
	if (check_valid_texture(value))
		return (set_texture(identifier, *value, map));
	return (set_color(identifier, value, map));
}
