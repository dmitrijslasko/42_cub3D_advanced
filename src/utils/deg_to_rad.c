/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_to_rad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:42 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:10:43 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	deg_to_rad(float angle)
{
	return (angle * M_PI / 180.0);
}

float	rad_to_deg(float radians)
{
	return (radians * (180.0f / M_PI));
}
