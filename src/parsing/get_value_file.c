/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:49 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 18:38:17 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_lookup_table_index(char *str)
{
	int i;

	i = 0;
	while (g_texture_lookup[i].mapfile_identificator)
	{
		if (ft_strncmp(g_texture_lookup[i].mapfile_identificator, str, strlen(str)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

bool	get_texture_filenames(t_map *map, int fd, char **str)
{
	char	**array;
	char	*line;

	line = *str;
	int i = 0;
	print_separator_default();
	printf(TXT_CYAN"FOUND THESE TEXTURES IN THE MAP FILE:\n"TXT_RESET);
	while (line && (is_empty_line(line) || is_valid_line_texture(line)))
	{
		if (is_valid_line_texture(line))
		{
			array = ft_split_special(line, WHITESPACE);
			printf("%s: %s\n", array[0], array[1]);
			int index = get_lookup_table_index(array[0]);
			printf(TXT_YELLOW"Index in lookup table: %d\n"TXT_RESET, index);
			// map->m_textures[index].texture.xpm_file = ft_strdup(array[1]);
			// printf(">>> %s\n", map->m_textures[index].texture.xpm_file);
			if (set_color_or_texture(map, array[0], &array[1]))
			{
				free_line_get_next(line, -1);
				return (free_array_return(array, 1));
			}
			free_array(array);
		}
		line = free_line_get_next(line, fd);
	}
	print_separator_default();
	return (0);
}
bool	parse_mapfile_values(t_map *map, char *mapfile)
{
	int		fd;
	int		result;
	char	*line;

	fd = ft_open(mapfile);
	if (fd < 0)
		return (EXIT_FAILURE);
	line = free_line_get_next(NULL, fd);
	
	result = get_texture_filenames(map, fd, &line);
	
	if (result == 0)
		get_map_data_values(line, fd, map);
	
	close (fd);
	return (result);
}
