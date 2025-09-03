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

	i = 0;
	while (i < *dt->door_count)
	{
		if (dt->doors[i].cell_x == x && dt->doors[i].cell_y == y)
			return (&dt->doors[i]);
		i++;
	}
	return (NULL);
}

t_sprite	*find_sprite_at(t_data *dt, int x, int y)
{
	size_t	i;

	i = 0;
	// printf("Sprite count: %d\n", *dt->sprite_count);
	// printf("Sprite count: %d\n", dt->levels[dt->active_level].sprite_count);
	while (i < *dt->sprite_count)
	{
		if ((int)dt->sprites[i].pos.x == x && (int)dt->sprites[i].pos.y == y)
			return (&dt->sprites[i]);
		i++;
	}
	return (NULL);
}