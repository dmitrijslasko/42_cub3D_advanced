/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:10:31 by dmlasko           #+#    #+#             */
/*   Updated: 2025/07/24 19:53:25 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO DL: check difference between count_sprite_textures and count_sprite_textures2
size_t	count_sprite_textures2(t_data *dt)
{
	size_t	len;

	len = 0;
	while (g_sprites[len].mapfile_key)
		len++;
	return (len);
}

int	load_sprite_textures(t_data *dt)
{
	size_t	sprite_element_count;

	sprite_element_count = count_elements_in_the_map(dt->map, SPRITE_TYPES);
	printf("Sprite elements found in the map: %zu\n", sprite_element_count);
	
	*dt->sprite_texture_count = count_sprite_textures2(dt);
	printf("Sprite types found in the map: %zu\n", *dt->sprite_texture_count);

	dt->sprite_textures = protected_malloc(sizeof(t_sprite_texture) * *dt->sprite_texture_count, dt);
	
	load_sprite_images(dt);

	return (EXIT_SUCCESS);
}
