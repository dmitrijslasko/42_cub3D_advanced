/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:43 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:08:44 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	set_sprite_textures(t_data *dt, int index)
{
	size_t	i;
	size_t	j;

	t_sprite *sprites;
	t_sprite_texture *sprite_textures;

	int sprite_count = dt->levels[index].sprite_count;
	int texture_count = dt->levels[index].sprite_texture_count;

	sprites = dt->levels[index].sprites;
	sprite_textures = dt->levels[index].sprite_textures;

	print_separator_default();
	printf(TXT_YELLOW">>> SETTING SPRITE TEXTURES!\n" TXT_RESET);
	
	if (!sprites || !sprite_textures)
		return (0);

	i = 0;
	while (i < sprite_count)
	{
		j = 0;
		while (j < texture_count)
		{
			if (dt->levels[index].sprites[i].map_char == dt->levels[index].sprite_textures[j].map_char)
			{
				dt->levels[index].sprites[i].texture = &dt->levels[index].sprite_textures[j];
				break ;
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
