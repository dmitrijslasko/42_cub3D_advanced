/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_door_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:38 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:06:39 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_door	*find_door_at(t_data *dt, int x, int y)
{
	size_t	i;

	i = 0;
	while (i < dt->door_count)
	{
		if (dt->doors[i].cell_x == x && dt->doors[i].cell_y == y)
			return (&dt->doors[i]);
		i++;
	}
	return (NULL);
}
