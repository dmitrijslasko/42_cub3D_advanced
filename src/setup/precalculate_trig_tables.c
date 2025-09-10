/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precalculate_trig_tables.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:26 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:10:27 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	precalculate_trig_tables(t_data *dt)
{
	float	angle_deg;
	float	angle_rad;
	size_t	i;

	print_separator_default();
	printf("Precalculating trig tables (%d values)...", PRECALCULATED_TRIG);
	i = 0;
	while (i < PRECALCULATED_TRIG)
	{
		angle_deg = (float)i / TRIG_PRECISION;
		angle_rad = deg_to_rad(angle_deg);
		dt->sin_table[i] = sinf(angle_rad);
		dt->cos_table[i] = cosf(angle_rad);
		i++;
	}
	printf(" Done!\n");
	return (EXIT_SUCCESS);
}
