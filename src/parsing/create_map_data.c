/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:35 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 18:41:13 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	create_double_array(char ***array, size_t size_row,
	size_t size_col, t_data *dt)
{
	size_t	curr_col;
	size_t	curr_row;
	char	**new;

	curr_row = 0;
	new = protected_malloc((size_row + 1) * sizeof(char *), dt);
	new[size_row] = NULL;
	while (curr_row < size_row)
	{
		new[curr_row] = protected_malloc((size_col + 1) * sizeof(char), dt);
		new[curr_row][size_col] = '\0';
		curr_col = 0;
		while (curr_col < size_col)
			new[curr_row][curr_col++] = ' ';
		curr_row++;
	}
	*array = new;
	return (0);
}

bool	create_map_data(t_map *map, t_data *dt)
{
	return (create_double_array(&map->map_data, map->map_size_rows, \
								map->map_size_cols, dt));
}
