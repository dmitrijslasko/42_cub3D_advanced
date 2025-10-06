/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:35 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 18:41:13 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_2d_map(char ***array, size_t size_row, size_t size_col, t_data *dt)
{
	size_t	curr_col;
	size_t	curr_row;
	t_mapcell	**new;
	int		cell_count;

	print_separator_default();
	printf("Initiliazing empty map cells... ");
	cell_count = 0;
	curr_row = 0;
	new = protected_malloc((size_row + 1) * sizeof(t_mapcell *), dt);
	
	new[size_row] = NULL;
	while (curr_row < size_row)
	{
		new[curr_row] = protected_malloc((size_col + 1) * sizeof(t_mapcell), dt);
		new[curr_row][size_col].map_char = '\0';
		new[curr_row][size_col].is_near_door = 0;
		curr_col = 0;
		while (curr_col < size_col)
		{
			new[curr_row][curr_col].map_char = ' ';
			new[curr_row][curr_col++].is_near_door = 0;
			cell_count++;
		}
		curr_row++;
	}
	*array = new;
	printf("Done! %d cells\n", cell_count);
	return (0);
}

bool	init_map_data(t_map *map, t_data *dt)
{
	return (init_2d_map(&map->map_data, map->map_size_rows, \
								map->map_size_cols, dt));
}
