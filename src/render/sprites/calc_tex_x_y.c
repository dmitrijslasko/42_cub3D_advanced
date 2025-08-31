/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_tex_coor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:29 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:08:30 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_coor	calculate_tex_x_y(t_sprite_texture *texture, t_coor *coor, t_coor *offset, t_sprite *sprite)
{
	t_coor	tex_coor;
	t_coor	sprite_size;
	int	row;

	sprite_size = sprite->size;

	if (texture->is_sprite_sheet == 0)
	{
		// width and height are 64 px
		tex_coor.x = (coor->x - offset->x) * texture->width / sprite_size.x;
		tex_coor.y = (coor->y - offset->y) * texture->height / sprite_size.y;
	}
	else
	{
		// if (sprite->id  0)
			row = sprite->current_frame;
		// else
		// 	row = 0;
			
		float angle = 180.0f - sprite->orientation_to_player;
		int col = (int)lroundf(angle / 45.0f);

		tex_coor.x = col * 65 + 1 + (coor->x - offset->x) * ((texture->width - 9) / 8) / sprite_size.x;
		tex_coor.y = row * 65 + 1 + (coor->y - offset->y) * ((texture->height - 8) / 7) / sprite_size.y;
	}
	
	return (tex_coor);
}
