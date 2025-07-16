/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_map_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:54 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/16 19:17:55 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_valid_character_map(char c)
{
	if (!ft_strchr("01", c) || !ft_strchr(WHITESPACE, c))
		return (1);
	if (!ft_strchr(SPRITE_TYPES, c))
		return (1);
	return (error_msg("Error: Character in the map in not valid!", 0));
}

bool	copy_map_row(t_map *map, int row, char *line)
{
	size_t	col;
	char	c;

	col = 0;
	c = '0';
	while (line && line[col])
	{
		c = line[col];
		 if (!check_valid_character_map(c))
		 	return (EXIT_FAILURE);
		map->map_data[row][col].cell_char = c;
		col++;
	}
	return (EXIT_SUCCESS);
}

void	parse_map(t_map *map, int fd, char **line)
{
	size_t	count_row;

	count_row = 0;
	printf("NEXT LINE: %s\n", *line);
	while (*line && line_is_empty(*line) == false)
	{
		copy_map_row(map, count_row, *line);
		*line = free_line_get_next(*line, fd);
		printf("NEXT LINE: %s\n", *line);
		count_row++;
	}
	free_line_get_next(*line, -1);
}
