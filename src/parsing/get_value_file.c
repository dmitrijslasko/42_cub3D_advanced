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
	while (g_texture_lookup[i].mapfile_id)
	{
		if (ft_strncmp(g_texture_lookup[i].mapfile_id, str, strlen(str)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

bool	parse_textures(t_map *map, int fd, char **str)
{
	char	**array;
	char	*line;
	int 	index;

	line = *str;
	print_separator_default();
	printf(TXT_CYAN"Parsing textures in the mapfile:\n"TXT_RESET);
	// Parse textures till there is something to parse...
	while (line && is_valid_line_texture(line) || (line_is_empty(line)))
	{
		printf("[TEXTURE] current line: \"%s\"\n", line);
		if (is_valid_line_texture(line))
		{
			array = ft_split_by_multiple_delimiters(line, WHITESPACE);
			printf("%s: %s\n", array[0], array[1]);
			index = get_lookup_table_index(array[0]);
			// NOTE DL: Look into this
			//if (index == -1)
			//{
			//	printf(TXT_YELLOW">>>Key not found in the lookup table: %s\n"TXT_RESET, array[0]);
			//	continue;
			//}
			printf(TXT_YELLOW">>> Index in the texture lookup table: %d\n---\n"TXT_RESET, index);
			if (set_color_or_texture(map, array[0], &array[1]))
			{
				free_line_get_next(line, -1);
				return (free_array_return(array, 1));
			}
			free_array(array);
		}
		printf("Line: %s\n", line);
		printf(">>> Cleaning........\n", line);
		line = free_line_get_next(line, fd);
	}
	printf("[TEXTURE] last line returned: \"%s\"\n", line);
	*str = line;
	print_separator_default();
	return (EXIT_SUCCESS);
}
bool	parse_mapfile_values(t_map *map, char *mapfile)
{
	int		fd;
	int		result;
	char	*line;

	// Open file
	fd = ft_open(mapfile);
	if (fd < 0)
		return (EXIT_FAILURE);

	//line = free_line_get_next(NULL, fd);
	line = get_next_line(fd);
	printf("NEXT LINE: %s\n", line);
	// parse textures
	result = parse_textures(map, fd, &line);
	printf("[TEXTURE] last line returned: \"%s\"\n", line);
	if (result == 0)
	{
		printf(">>> Parsing the map now...\n");
		parse_map(map, fd, &line);
	}
	close(fd);
	return (result);
}
