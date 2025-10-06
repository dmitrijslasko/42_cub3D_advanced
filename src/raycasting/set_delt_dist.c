/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_delt_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:05 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:08:06 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_delta_dist(t_x_y *delta_dis, t_x_y direction)
{
	delta_dis->x = fabs(1 / direction.x);
	delta_dis->y = fabs(1 / direction.y);
}
