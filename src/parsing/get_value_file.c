/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:49 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 18:38:17 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	get_value_textures(t_map *map, int fd, char **str)
{
	char	**array;
	char	*line;

	line = *str;
	while (line && (is_empty_line(line) || is_valid_line_texture(line)))
	{
		if (is_valid_line_texture(line))
		{
			array = ft_split_special(line, WHITESPACE);
			printf("%s: %s\n", array[0], array[1]);
			if (set_color_or_texture(map, array[0], &array[1]))
			{
				free_line_get_next(line, -1);
				return (free_array_return(array, 1));
			}
			free_array(array);
		}
		line = free_line_get_next(line, fd);
	}
	*str = line;
	return (0);
}

bool	get_value_file1(t_map *map, int fd)
{
	char	*line;
	bool	result;

	line = free_line_get_next(NULL, fd);
	result = get_value_textures(map, fd, &line);
	if (result == Success)
		get_value_map(line, fd, map);
	return (result);
}

bool	get_value_file(t_map *map, char *file)
{
	int	fd;
	int	result;

	fd = ft_open(file);
	if (fd < 0)
		return (1);
	result = get_value_file1(map, fd);
	close (fd);
	return (result);
}
