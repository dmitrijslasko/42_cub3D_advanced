/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_side_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:08 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 16:08:52 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_side_dist(t_x_y *side_dist, t_x_y *dir_vec, t_x_y *pos_player, \
						t_x_y *delta_dist)
{
	t_coor	coor;

	coor.x = (size_t)pos_player->x;
	coor.y = (size_t)pos_player->y;
	if (dir_vec->x < 0)
		side_dist->x = (pos_player->x - coor.x) * delta_dist->x;
	else
		side_dist->x = (coor.x + 1 - pos_player->x) * delta_dist->x;
	if (dir_vec->y < 0)
		side_dist->y = (pos_player->y - coor.y) * delta_dist->y;
	else
		side_dist->y = (coor.y + 1 - pos_player->y) * delta_dist->y;
}
