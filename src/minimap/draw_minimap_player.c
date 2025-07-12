/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:51 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:52 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef enum e_minimap_player_display_style
{
	SQUARE,
	CIRCLE
}	t_minimap_player_display_style;

/**
 * @brief Draws the player's representation on the 2D minimap->
 *
 * @param dt
 * @return int
 */
int	draw_minimap_player(t_data *dt)
{
	t_coor	player_pos;

	player_pos.x = dt->minimap_img->width / 2;
	player_pos.y = dt->minimap_img->height / 2;
	if (MINIMAP_PLAYER_DISPLAY_STYLE == CIRCLE)
		draw_circle(dt->minimap_img, &player_pos, MINIMAP_PLAYER_SIZE_PX,
			MINIMAP_PLAYER_COLOR);
	else if (MINIMAP_PLAYER_DISPLAY_STYLE == SQUARE)
		draw_square_from_center(dt->minimap_img, &player_pos,
			MINIMAP_PLAYER_SIZE_PX, MINIMAP_PLAYER_COLOR);
	return (EXIT_SUCCESS);
}
