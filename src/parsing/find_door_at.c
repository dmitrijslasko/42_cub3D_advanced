/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_door_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:38 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/15 16:33:38 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_door	*find_door_at(t_data *dt, int x, int y)
{
	size_t	i;
	t_door *doors = get_curr_level(dt)->doors;

	i = 0;
	while (i < get_curr_level(dt)->door_count)
	{
		if (doors[i].cell_x == x && doors[i].cell_y == y)
			return (&doors[i]);
		i++;
	}
	return (NULL);
}

t_sprite	*find_sprite_at(t_data *dt, int x, int y)
{
	size_t	i;

	size_t	sprite_count = get_curr_level(dt)->sprite_count;
	t_sprite	*sprites = get_curr_level(dt)->sprites;

	i = 0;
	while (i < sprite_count)
	{
		if ((int)sprites[i].pos.x == x && (int)sprites[i].pos.y == y)
			return (&sprites[i]);
		i++;
	}
	return (NULL);
}