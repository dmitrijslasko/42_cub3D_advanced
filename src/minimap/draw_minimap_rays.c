/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:54 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:55 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_minimap_rays(t_data *dt, int is_direction_vector)
{
	t_coor	player_coor;
	size_t	i;

	set_coor_values(&player_coor,
		dt->minimap_img->width / 2,
		dt->minimap_img->height / 2);
	if (is_direction_vector)
		draw_minimap_ray(dt, player_coor, dt->player.orientation_vector,
			MINIMAP_DIRECTION_RAY_COLOR);
	else
	{
		i = 0;
		while (i < CASTED_RAYS_COUNT)
		{
			if (i % MINIMAP_DRAW_EVERY_NTH_RENDER_RAY == 0)
				draw_minimap_ray(dt, player_coor, dt->rays[i].vector,
					MINIMAP_RENDER_RAY_COLOR);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
