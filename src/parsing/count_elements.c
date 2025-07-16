/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:33 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/16 19:18:16 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	count_if_there_is_others_elements(t_map *map, char *element)
{
	int		row;
	int		col;
	size_t	element_count;

	element_count = 0;
	row = 0;
	while (row < map->map_size_rows)
	{
		col = 0;
		while (col < map->map_size_cols)
		{
			if (!ft_strchr(element, map->map_data[row][col].cell_char))
				return (1);
			col++;
		}
		row++;
	}
	return (element_count);
}

size_t	count_elements_in_the_map(t_map *map, char *element)
{
	int		row;
	int		col;
	size_t	element_count;

	element_count = 0;
	row = 0;
	while (row < map->map_size_rows)
	{
		col = 0;
		while (col < map->map_size_cols)
		{
			if (ft_strchr(element, map->map_data[row][col].cell_char))
			{
				element_count++;
			}
			col++;
		}
		row++;
	}
	return (element_count);
}

size_t	count_types_elements_in_the_map(t_map *map, char *element)
{
	size_t	i;
	size_t	element_type_count;
	char	*type;

	element_type_count = 0;
	i = 0;
	while (element[i])
	{
		type = ft_substr(element, i++, 1);
		if (count_elements_in_the_map(map, type) > 0)
			element_type_count++;
		free(type);
	}
	return (element_type_count);
}
