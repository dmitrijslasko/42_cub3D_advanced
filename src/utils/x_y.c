/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_y.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:11:46 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:34:32 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_values_size_t(int *new_x, int *new_y, int x, int y)
{
	*new_x = x;
	*new_y = y;
}

t_x_y	get_values_x_y(float x, float y)
{
	t_x_y	new;

	new.x = x;
	new.y = y;
	return (new);
}

void	set_values_x_y(t_x_y *new, float x, float y)
{
	new->x = x;
	new->y = y;
}

t_coor	get_values_coor(int x, int y)
{
	t_coor	new;

	new.x = x;
	new.y = y;
	return (new);
}

void	set_value_coor(t_coor *new, int x, int y)
{
	new->x = x;
	new->y = y;
}
