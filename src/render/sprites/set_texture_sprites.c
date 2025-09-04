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

bool	set_sprite_textures(t_data *dt)
{
	size_t	i;
	size_t	j;
	

	print_separator_default();
	printf(">>> SETTING SPRITE TEXTURES!\n");
	
	if (!dt->sprites || !dt->sprite_textures)
		return (0);
	
	i = 0;
	dt->sprite_count = &get_curr_level(dt)->sprite_count;
	printf("%d\n", *dt->sprite_count);
	while (i < *dt->sprite_count)
	{
		j = 0;
		while (j < get_curr_level(dt)->sprite_texture_count)
		{
			if (dt->sprites[i].map_char == dt->sprite_textures[j].map_char)
			{
				dt->sprites[i].texture = &dt->sprite_textures[j];
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}
