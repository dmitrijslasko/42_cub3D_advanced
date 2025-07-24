/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:41 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/23 19:29:08 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_sprite(t_data *dt, t_sprite *sprite, \
					t_coor *offset, t_coor	*sprite_size)
{
				sprite_put_color(dt, sprite, &coor, &tex_coor);
			}
			coor.x++;
		}
		coor.y++;
	}
	if (sprite_at_target)
		dt->targeted_sprite = sprite;
	else
		dt->targeted_sprite = NULL;
	return (EXIT_SUCCESS);
}
