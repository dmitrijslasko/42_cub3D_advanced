/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:48 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:08:49 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	swap_sprites(t_sprite *a, t_sprite *b)
{
	t_sprite	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_sprites(t_sprite *sprites, size_t num_sprites)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (num_sprites == 0)
		return ;
	while (i < num_sprites - 1)
	{
		j = 0;
		while (j < num_sprites - i - 1)
		{
			if (sprites[j].distance_to_player < \
											sprites[j + 1].distance_to_player)
				swap_sprites(&sprites[j], &sprites[j + 1]);
			j++;
		}
		i++;
	}
}
