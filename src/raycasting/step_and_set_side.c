/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_and_set_side.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:12 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/18 16:52:23 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	step_and_set_side(t_dda_info *dda_info)
{
	if (dda_info->side->x < dda_info->side->y)
	{
		dda_info->side->x += dda_info->delta->x;
		dda_info->map_coor->x += dda_info->step->x;
		*(dda_info->hit_side) = 'x';
	}
	else
	{
		dda_info->side->y += dda_info->delta->y;
		dda_info->map_coor->y += dda_info->step->y;
		*(dda_info->hit_side) = 'y';
	}
}
