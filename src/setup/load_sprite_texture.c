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

int	load_sprite_textures(t_data *dt, int i)
{
	size_t	sprite_element_count;
	size_t	sprite_texture_count;
	t_map	*map;

	map = &dt->levels[i].map;

	sprite_element_count = count_elements_in_the_map(map, SPRITE_TYPES);
	dt->levels[i].sprite_count = sprite_element_count;
	printf("Sprite elements found in the map: %zu\n", sprite_element_count);
	
	sprite_texture_count = count_sprite_textures2(dt);
	dt->levels[i].sprite_texture_count = sprite_texture_count;
	printf("Sprite types found in the map: %zu\n", sprite_texture_count);
	
	load_sprite_images(dt, i);
	return (EXIT_SUCCESS);
}
