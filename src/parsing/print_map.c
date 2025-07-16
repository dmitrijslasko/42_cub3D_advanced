/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:05 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/14 19:25:14 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_level_map(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	printf(TXT_YELLOW "Printing out the level map:\n" TXT_RESET);
	print_separator(1, DEF_SEPARATOR_CHAR);
	if (!map || !map->map_data || !map->map_data[0] || !map->map_data[0][0])
		return ;
	while (row < map->map_size_rows)
	{
		col = 0;
		while (col < map->map_size_cols)
		{
			printf("%c", map->map_data[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
	print_separator_default();
}
