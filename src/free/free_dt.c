/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:05:21 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/16 19:22:53 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_dt(t_data *dt)
{
	ft_free(dt->doors);
	ft_free(dt->rays);
	free_array(dt->map.map_data);
	ft_free(dt->view);
	free_sprites(dt);
	free_wall_tile_texture(dt);
	// free(dt->map.malloc_textures);
	ft_free(dt->sprites);
	free_graphic(dt);
	free_mlx(dt);
	// free_audio(dt->background_music);
}
