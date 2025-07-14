/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_identifier_texture.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:19 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/14 17:58:52 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_line_texture(char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[j] && ft_strchr(WHITESPACE, line[j]))
		j++;
	while (g_texture_lookup[i].mapfile_id)
	{
		if (!ft_strncmp(&line[j], g_texture_lookup[i].mapfile_id, g_texture_lookup[i].mapfile_len) \
			&& ft_strchr(WHITESPACE, line[j + g_texture_lookup[i].mapfile_len]))
			return (1);
		i++;
	}
	return (0);
}

t_wall_orientation	check_valid_texture_identifier(char *identifier)
{
	size_t	i;

	i = 0;
	while (g_texture_lookup[i].mapfile_id)
	{
		if (!ft_strncmp(identifier, g_texture_lookup[i].mapfile_id, ft_strlen(identifier)))
			return (g_texture_lookup[i].texture_type);
		i++;
	}
	return (DEFAULT_WALL);
}
