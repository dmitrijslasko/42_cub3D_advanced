/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:18 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/16 19:14:33 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	render_floor_and_ceiling(t_data *dt)
{
	 if (BONUS)
	 {
	 	draw_sky(dt);
	 	// draw_textured_ceiling(dt);
	 }
	 else
		draw_ceiling(dt);
	//draw_floor(dt);
	 draw_textured_floor(dt);
	return (EXIT_SUCCESS);
}

void	render_3d_scene(t_data *dt)
{
	int	i;
	int	screen_slice_width;

	i = 0;
	screen_slice_width = WINDOW_W / CASTED_RAYS_COUNT;
	render_floor_and_ceiling(dt);
	while (i < CASTED_RAYS_COUNT)
	{
		dt->rays[i].id = i;
		render_3d_each_ray(dt, &dt->rays[i], screen_slice_width);
		i++;
	}
}
