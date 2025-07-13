/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:01 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 18:41:11 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_value_map_data(char *file, t_data *dt)
{
	if (init_default_map(&dt->map))
		return (1);
	if (set_size_map_data(&dt->map, file))
		return (1);
	if (create_map_data(&dt->map, dt))
		return (1);
	dt->map.number_of_textures = NUMBER_TEXTURES;
	dt->map.m_textures = protected_malloc(dt->map.number_of_textures, dt);
	if (get_value_file(&dt->map, file))
		return (1);
	if (!check_valid_player(&dt->map))
		return (1);
	return (!check_all_wall_tile(&dt->map));
}
