/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:39 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:08:40 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_all_sprites(t_data *dt)
{
	size_t	i;
	float	distance_to_player;

	i = 0;
	sort_sprites_by_distance(dt);
	set_texture_sprites(dt);
	while (i < dt->sprite_count)
	{
		if (dt->player.pos.x - dt->sprites[i].pos.x > 0.01)
			dt->sprites[i].pos.x += 0.01f;
		else if (dt->player.pos.x - dt->sprites[i].pos.x < 0.01)
			dt->sprites[i].pos.x -= 0.01f;
		if (dt->player.pos.y - dt->sprites[i].pos.y > 0.01)
			dt->sprites[i].pos.y += 0.01f;
		else if (dt->player.pos.x - dt->sprites[i].pos.x < 0.01)
			dt->sprites[i].pos.y -= 0.01f;
		get_position_and_render_sprite(dt, &dt->sprites[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
