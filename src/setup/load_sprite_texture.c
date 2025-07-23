/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:10:31 by dmlasko           #+#    #+#             */
/*   Updated: 2025/07/23 19:32:30 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_sprite_textures(t_data *dt)
{
	size_t	sprite_element_count;

	sprite_element_count = count_elements_in_the_map(&dt->map, SPRITE_TYPES);
	count_sprite_textures(dt);
	printf("Sprite elements found in the map: %zu\n", sprite_element_count);
	printf("Sprite types found in the map: %zu\n", dt->sprite_texture_count);
	dt->sprite_texture_count = 5;
	dt->sprite_textures = protected_malloc(sizeof(t_sprite_texture) * \
		dt->sprite_texture_count, dt);
	load_sprite_images(dt);
	return (EXIT_SUCCESS);
}
