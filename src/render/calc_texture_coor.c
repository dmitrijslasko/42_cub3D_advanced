/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_texture_coor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:01 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/15 16:57:27 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_texture_coor(t_data *dt, int *texture_y, \
							float *distance_to_wall, int d)
{
	float	wall_height;
	t_coor	tex_size;

	tex_size.y = dt->map.textures->texture.height;
	wall_height = 1.0f / *distance_to_wall * SCALING;
	*texture_y = (d * tex_size.y) / (2 * wall_height);
	if (*texture_y >= tex_size.y)
		*texture_y = tex_size.y - 1;
}
