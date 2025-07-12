/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:55 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 16:04:03 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_rays(t_data *dt)
{
	size_t	i;

	printf(TXT_YELLOW "Initializing the ray array...\n" TXT_RESET);
	printf(TXT_YELLOW "Total rays to be cast: %d\n" TXT_RESET, \
												CASTED_RAYS_COUNT);
	dt->rays = protected_malloc(sizeof(t_ray) * WINDOW_W, dt);
	i = 0;
	while (i < CASTED_RAYS_COUNT)
	{
		dt->rays[i].distance_to_wall = 0;
		dt->rays[i].distance_to_door = 0;
		dt->rays[i].percentage_of_image = 0;
		dt->rays[i].wall_hit.x = 0;
		dt->rays[i].wall_hit.y = 0;
		dt->rays[i].wall_orientation = -1;
		dt->rays[i].cell_type = -1;
		dt->rays[i].door = 0;
		dt->rays[i].hit_side = 0;
		dt->rays[i].hit_content = 0;
		dt->rays[i].wall_height = 0;
		i++;
	}
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	print_separator_default();
	return (0);
}
