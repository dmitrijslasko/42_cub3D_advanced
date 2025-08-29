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

t_coor	calculate_tex_x_y(t_sprite_texture *texture, t_coor *coor,
	t_coor *offset, t_coor *sprite_size)
{
	t_coor	tex_coor;

	tex_coor.x = (coor->x - offset->x) * texture->width / sprite_size->x;
	tex_coor.y = (coor->y - offset->y) * texture->height / sprite_size->y;
	return (tex_coor);
}
