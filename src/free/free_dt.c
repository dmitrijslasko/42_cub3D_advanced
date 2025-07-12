/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:21 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:05:22 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_dt(t_data *dt)
{
	ft_free(dt->doors);
	ft_free(dt->rays);
	free_array(dt->map.map_data);
	ft_free(dt->view);
	free_texture_sprite(dt);
	free_wall_tile_texture(dt);
	ft_free(dt->sprites);
	free_graphic(dt);
	// free_audio(dt->background_music);
}
