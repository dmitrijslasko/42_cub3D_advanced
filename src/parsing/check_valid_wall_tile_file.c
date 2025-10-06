/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_are_valid.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:27 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 18:09:29 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_single_line_wall_tile(char *line)
{
	char	**array;
	size_t	size;
	int		ret;

	array = ft_split_by_multiple_delimiters(line, WHITESPACE);
	size = size_array(array);
	if (size < 2)
		return (error_message_free("Not valid input!", array, 0));
	ret = check_valid_color_or_texture(array);
	free_array(array);
	return (ret);
}

bool	check_valid_wall_tile_file1(int fd)
{
	char	**array;
	char	*line;

	array = NULL;
	line = free_line_get_next(NULL, fd);
	while (line)
	{
		if (line_is_empty(line))
		{
			line = free_line_get_next(line, fd);
			continue ;
		}
		if (!is_valid_line_texture(line))
			break ;
		if (!check_single_line_wall_tile(line))
		{
			free_line_get_next(line, -1);
			return (error_msg("Error: Reading textures / colors.", 0));
		}
		line = free_line_get_next(line, fd);
	}
	free_line_get_next(line, -1);
	return (free_array_return(array, 1));
}

bool	check_textures_are_valid(char *file)
{
	int	fd;
	int	ret;
	
	printf("Checking mapfile textures...\n");
	fd = ft_open(file);
	if (fd <= 0)
		return (1);
	ret = check_valid_wall_tile_file1(fd);
	close(fd);
	return (ret);
}
