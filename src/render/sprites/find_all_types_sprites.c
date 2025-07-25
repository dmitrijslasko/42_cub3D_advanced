/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_types_sprites.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:34 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/24 20:00:05 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_sprites(t_data *dt)
{
	int		row;
	int		col;
	size_t	i;
	char	c;

	i = 0;
	row = 0;
	while (row < dt->map.map_size_rows && i < dt->sprite_count)
	{
		col = 0;
		while (col < dt->map.map_size_cols && i < dt->sprite_count)
		{
			c = get_cell_type_by_coordinates(&dt->map, row, col);
			if (ft_strchr(SPRITE_TYPES, c))
			{
				dt->sprites[i].id = i;
				dt->sprites[i].type = c;
				dt->sprites[i].pos.x = col + 0.5;
				dt->sprites[i].pos.y = row + 0.5;
				dt->sprites[i].active = 1;
				dt->sprites[i].orientation = 180.0f;
				i++;
			}
			col++;
		}
		row++;
	}
}
void	find_all_sprites(t_data *dt)
{
	size_t	sprite_count;

	sprite_count = count_elements_in_the_map(&dt->map, SPRITE_TYPES);
	if (!sprite_count)
		return ;
	dt->sprites = protected_malloc(sprite_count * sizeof(t_sprite), dt);
	dt->sprite_count = sprite_count;
	find_sprites(dt);
}
