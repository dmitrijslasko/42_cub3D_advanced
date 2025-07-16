/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hit_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:34 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/16 19:41:19 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	get_cell_type(t_map *map, t_coor *map_coor)
{
	return (map->map_data[map_coor->y][map_coor->x].cell_char);
}

char	get_cell_type_by_coordinates(t_map *map, size_t y, size_t x)
{
	return (map->map_data[y][x].cell_char);
}

t_mapcell	get_cell_by_coordinates(t_map *map, size_t y, size_t x)
{
	return (map->map_data[y][x]);
}

// NOTE DL: should we remove the first if?
bool	check_hit_wall(t_coor *coord, t_map *map, t_ray *ray, char side)
{
	char	tile;
	char	neighbour_right;

	tile = get_cell_type(map, coord);
	neighbour_right = get_cell_type_by_coordinates(map, coord->y, coord->x + 1);
	// NOTE DL: thin wall functionality
	if (side == 'x' && ray->vector.x > 0)
	{
		if (tile == 'v')
			return (1);
	}
	else if (side == 'x' && ray->vector.x < 0)
	{
		if (neighbour_right == 'v')
			return (1);
	}
	if (ft_strchr(WALL_TYPES, tile))
		return (1);
	return (0);
}
