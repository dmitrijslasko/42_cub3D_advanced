/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite_by_distance.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:45 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:08:46 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites_by_distance(t_data *dt)
{
	float	dx;
	float	dy;
	size_t	i;

	i = 0;
	while (i < *dt->sprite_count)
	{
		dx = dt->sprites[i].pos.x - dt->player.pos.x;
		dy = dt->sprites[i].pos.y - dt->player.pos.y;
		dt->sprites[i].distance_to_player = dx * dx + dy * dy;
		i++;
	}
	sort_sprites(dt->sprites, *dt->sprite_count);
}
