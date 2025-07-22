/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit_put_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:50 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:08:51 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_put_color(t_data *dt, t_sprite *sprite, \
							t_coor *coor, t_coor *tex_coor)
{
	int					time;
	t_sprite_texture	*texture;
	unsigned int		color;

	time = sprite->time;
	texture = sprite->texture;
	color = texture->sprite_data[time][tex_coor->y * texture->width + \
			tex_coor->x];
	apply_distance_shadow_distance(sprite->distance_to_player, &color);
	if (color == BLACK)
		return ;
	img_pix_put(dt->final_frame_img, coor->x, coor->y, color);
}
