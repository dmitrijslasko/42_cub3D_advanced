/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_render_sprites.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:36 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/23 20:27:07 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_position_and_render_sprite(t_data *dt, t_sprite *sprite)
{
	t_x_y	distance_to_player;
	float	relative_orientation;
	t_x_y	transform;
	int		sprite_screen_x;
	t_coor	sprite_size;
	t_coor	position_on_screen;

	distance_to_player.x = sprite->pos.x - dt->player.pos.x;
	distance_to_player.y = sprite->pos.y - dt->player.pos.y;

	// relative orientation to player
	relative_orientation = fmodf(dt->player.orientation - sprite->orientation, 360.0f);
	if (relative_orientation < 0)
		relative_orientation += 360.0f;
	sprite->orientation_to_player = relative_orientation;

	transform.y = (dt->player.orientation_vector.x * distance_to_player.x + dt->player.orientation_vector.y * distance_to_player.y);
	// transform.y = (distance_to_player.x * distance_to_player.x + distance_to_player.y * distance_to_player.y);
	// transform.y = 1;
	if (transform.y <= 0.1f)
		return (0);

	transform.x = (-1.0f / FIELD_OF_VIEW_SCALE) * \
					(dt->player.orientation_vector.y * distance_to_player.x - \
								dt->player.orientation_vector.x * distance_to_player.y);

	sprite_size.y = (TILE_SIZE / transform.y) * 8.5f;
	sprite_size.x = sprite_size.y;

	// scale down to 80%
	float factor = 1.0f;
	if (sprite->map_char != 'Z')
		factor = 0.8f;
	sprite_size.x *= factor;
	sprite_size.y *= factor;
	int reduction = (1 - factor) * sprite_size.y;

	sprite_screen_x = (WINDOW_W / 2) * (1 + transform.x / transform.y);
	
	t_coor offset;

	offset.x = sprite_screen_x - sprite_size.x / 2;
	offset.y = dt->view->screen_center_y - (sprite_size.y + dt->test_value_1 + sprite_size.y * dt->z_offset) / 2 + reduction / 2;

	render_sprite(dt, sprite, &offset, &sprite_size);
	return (EXIT_SUCCESS);
}
