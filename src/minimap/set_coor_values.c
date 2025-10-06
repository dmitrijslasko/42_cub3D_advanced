/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coor_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:57 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:58 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_coor_values(t_coor *coor, int x, int y)
{
	coor->x = x;
	coor->y = y;
	return (EXIT_SUCCESS);
}
