/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_and_set_side.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:12 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:08:13 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	step_and_set_side(t_dda_info *info)
{
	if (info->side->x < info->side->y)
	{
		info->side->x += info->delta->x;
		info->map->x += info->step->x;
		*(info->hit_side) = 'x';
	}
	else
	{
		info->side->y += info->delta->y;
		info->map->y += info->step->y;
		*(info->hit_side) = 'y';
	}
}
