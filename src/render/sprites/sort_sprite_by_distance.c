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
	int		sprite_count;
	
	t_sprite *sprites = get_curr_level(dt)->sprites;

	sprite_count =  get_curr_level(dt)->sprite_count;
	// printf("Sorting %d sprites by distance...\n", sprite_count);

	i = 0;
	while (i < sprite_count)
	{
		dx = sprites[i].pos.x - dt->player.pos.x;
		dy = sprites[i].pos.y - dt->player.pos.y;

		sprites[i].distance_to_player = dx * dx + dy * dy;

		// printf("Sprite [%d]: %f %f\n", i, dx, dy);
		i++;
	}
	sort_sprites(sprites, get_curr_level(dt)->sprite_count);
}
