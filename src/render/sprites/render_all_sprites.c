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

	dt->targeted_sprite = NULL;
	sort_sprites_by_distance(dt);

	i = 0;
	while (i < *dt->sprite_count)
	{
		get_position_and_render_sprite(dt, &dt->sprites[i]);
		dt->sprites[i].start_x = -1;

		if (SHOW_TARGETED_SPRITE)
		{
			if (&dt->sprites[i] == dt->targeted_sprite)
			{
				int center_x = dt->sprites[i].center_x;
				draw_line(dt->final_frame_img, (t_coor){center_x, 100}, (t_coor){center_x, WINDOW_H - 100}, CYAN);
				
				int aim = dt->sprites[i].aim;
				draw_line(dt->final_frame_img, (t_coor){center_x - aim, 100}, (t_coor){center_x - aim, WINDOW_H - 100}, MAGENTA);
				draw_line(dt->final_frame_img, (t_coor){center_x + aim, 100}, (t_coor){center_x + aim, WINDOW_H - 100}, MAGENTA);
			}
		}
		dt->sprites[i].center_x = -1;
		i++;
	}
	


	return (EXIT_SUCCESS);
}
