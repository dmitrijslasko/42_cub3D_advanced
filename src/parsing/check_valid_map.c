/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:22 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:06:23 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_invalid_map(t_map *map)
{
	size_t	count;

	if (BONUS)
		return (0);
	count = count_if_there_is_others_elements(map, "10NSWE ");
	if (count > 0)
		return (error_msg("Error: There's character not allowed on the map.", 1));
	return (0);
}

bool	is_open_map(char **map, char **visited, int row, int col)
{
	if (row < 0 || col < 0 || map[row] == NULL || map[row][col] == '\0')
		return (1);
	if (ft_strchr(WALL_TYPES, map[row][col]) || visited[row][col] == 'V')
		return (0);
	visited[row][col] = 'V';
	if (is_open_map(map, visited, row + 1, col))
		return (1);
	if (is_open_map(map, visited, row - 1, col))
		return (1);
	if (is_open_map(map, visited, row, col + 1))
		return (1);
	if (is_open_map(map, visited, row, col - 1))
		return (1);
	return (0);
}

bool	check_map_is_closed(t_map *map, t_player *player, t_data *dt)
{
	char	**visited;

	init_2d_map(&visited, map->map_size_rows, map->map_size_cols, dt);
	if (is_open_map(map->map_data, visited, (int)player->pos.y, \
					(int)player->pos.x) || is_invalid_map(map))
		return (error_message_free(TXT_RED"Error: Invalid map."TXT_RESET, visited, 0));
	return (free_array_return(visited, 1));
}
