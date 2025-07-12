/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_distance_shadow.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:57 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:08:58 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	apply_distance_shadow(t_ray *ray, int *color)
{
	float	shade;
	int		r;
	int		g;
	int		b;

	shade = 1.0f / (1.0f + ray->distance_to_wall * DISTANCE_SHADOW_STRENGTH);
	if (shade < 0.1f)
		shade = 0.1f;
	r = ((*color >> 16) & 0xFF) * shade;
	g = ((*color >> 8) & 0xFF) * shade;
	b = ((*color >> 0) & 0xFF) * shade;
	*color = (r << 16) | (g << 8) | (b << 0);
	return (EXIT_SUCCESS);
}
