/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_put_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:50 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/24 19:00:14 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_put_color(t_data *dt, t_sprite *sprite, t_coor *coor, t_coor *tex_coor)
{
	int					frame;
	t_sprite_texture	*texture;
	unsigned int		color;

	frame = sprite->current_frame;

	texture = sprite->texture;
	
	if (sprite->texture->is_sprite_sheet)
	// process sprite sheet
	{
		color = texture->sprite_data[0][tex_coor->y * (texture->width) + tex_coor->x];
		if (color == texture->sprite_data[0][1 * (texture->width) + 1])
			return ;
		if (color == texture->sprite_data[0][0])
			return ;
	}
	else
	{
		// process simple sprite (not a texture sheet)
		color = texture->sprite_data[frame][tex_coor->y * texture->width + tex_coor->x];
		if (color == BLACK)
			return ;
	}

	// shadowing
	apply_ambient_light_shading(sprite->distance_to_player * 2, &color);
	apply_ambient_light_shading(*dt->ambient_light, &color);
	
	img_pix_put(dt->final_frame_img, coor->x, coor->y, color);
}
