/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:21 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/14 14:16:24 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_empty_line_end_file(char *line, int fd)
{
	while (line && is_empty_line(line))
		line = free_line_get_next(line, fd);
	if (line)
		return (error_free_char_return("Error: unexpected line after map.", \
																	line, 1));
	return (0);
}

char	*get_first_line_map(int fd)
{
	char	*line;

	line = free_line_get_next(NULL, fd);
	while (line)
	{
		if (!is_empty_line(line) && !is_valid_line_texture(line))
			break ;
		line = free_line_get_next(line, fd);
	}
	return (line);
}

bool	set_size_map_data1(t_map *map, int fd)
{
	char	*line;
	int		count_row;
	int		count_col;
	int		ret;

	print_separator_default();
	printf("Setting map size... ");
	count_col = 0;
	count_row = 0;
	line = get_first_line_map(fd);
	if (!line)
		return (error_msg("Error: map not found.", 1));
	while (line)
	{
		if (is_empty_line(line))
			break ;
		count_row++;
		update_value_max(&count_col, line);
		line = free_line_get_next(line, fd);
	}
	ret = check_empty_line_end_file(line, fd);
	free_line_get_next(NULL, -1);
	if (ret == Success)
		set_values_size_t(&map->map_size_cols, &map->map_size_rows, \
							count_col, count_row);
	printf("%dx%d\n", count_col, count_row);
	return (ret);
}

bool	set_map_size_data(t_map *map, char *map_file)
{
	int	fd;
	int	ret;

	fd = ft_open(map_file);
	if (fd < 0)
		return (1);
	ret = set_size_map_data1(map, fd);
	close(fd);
	return (ret);
}
