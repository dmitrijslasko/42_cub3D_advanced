/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_single_ray_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:57 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 18:39:01 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_single_ray_info(t_ray ray)
{
	printf(TXT_YELLOW "Ray distance:\t%f \n" TXT_RESET, ray.distance_to_wall);
	printf("Wall type: \t");
	if (ray.wall_orientation == NORTH)
		printf("NORTH\n");
	if (ray.wall_orientation == WEST)
		printf("WEST\n");
	if (ray.wall_orientation == EAST)
		printf("EAST\n");
	if (ray.wall_orientation == SOUTH)
		printf("SOUTH\n");
	printf("Ray hits wall at x == %f\n", ray.percentage_of_image);
}
