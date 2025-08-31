/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:39 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/23 20:27:03 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_all_sprites(t_data *dt)
{
	size_t	i;
	float	distance_to_player;

	sort_sprites_by_distance(dt);

	i = 0;
	while (i < dt->sprite_count)
	{
		get_position_and_render_sprite(dt, &dt->sprites[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
