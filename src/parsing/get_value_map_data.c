/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_map_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:54 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:06:55 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_valid_caracter_map(char c)
{
	if (!ft_strchr("01", c) || !ft_strchr(WHITE_SPACE, c))
		return (1);
	if (!ft_strchr(SPRITE_TYPES, c))
		return (1);
	return (error_msg("Error: Caracter in map not valid!", 0));
}

bool	copy_line(t_map *map, int row, char *line)
{
	size_t	col;
	char	c;

	col = 0;
	c = '0';
	while (line && line[col])
	{
		c = line[col];
		if (!check_valid_caracter_map(c))
			return (EXIT_FAILURE);
		map->map_data[row][col] = c;
		col++;
	}
	return (EXIT_SUCCESS);
}

void	get_value_map(char *line, int fd, t_map *map)
{
	size_t	count_row;

	count_row = 0;
	while (line && !is_empty_line(line))
	{
		copy_line(map, count_row, line);
		line = free_line_get_next(line, fd);
		count_row++;
	}
	free_line_get_next(line, -1);
}
