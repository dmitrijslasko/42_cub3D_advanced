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

static void	init_sprites(t_data *dt, int index)
{
	int		row;
	int		col;
	size_t	i;
	char	sprite_type;
	t_level *level = &dt->levels[index];

	i = 0;

	row = 0;
	while (row < level->map.map_size_rows && i < level->sprite_count)
	{
		col = 0;
		while (col < level->map.map_size_cols && i < level->sprite_count)
		{
			sprite_type = get_cell_by_coordinates(&level->map, row, col)->map_char;
			
			if (ft_strchr(SPRITE_TYPES, sprite_type))
			{
				level->sprites[i].id = i;
				level->sprites[i].map_char = sprite_type;
				level->sprites[i].type = STATIC;
				if (ft_strchr(CONSUMABLE_TYPES, sprite_type))
					level->sprites[i].type = PICKUP;
				if (ft_strchr(ENEMY_SPRITES, sprite_type))
					level->sprites[i].type = ENEMY;

				level->sprites[i].pos.x = col + 0.5f;
				level->sprites[i].pos.y = row + 0.5f;

				level->sprites[i].is_hidden = 0;
				level->sprites[i].y_offset = 0;
				if (sprite_type == 'Z')
					level->sprites[i].y_offset = 50;

				level->sprites[i].state = IDLE;

				level->sprites[i].current_frame = 0;
				level->sprites[i].last_frame_time = 0;
				
				i++;
			}
			col++;
		}
		row++;
	}
}
void	find_all_sprites(t_data *dt, t_map *map, int i)
{
	size_t	sprite_count;
	size_t	consumable_count;

	sprite_count = count_elements_in_the_map(map, SPRITE_TYPES);

	if (!sprite_count)
		return ;
	
	dt->levels[i].sprite_count = sprite_count;
	dt->levels[i].sprites = protected_malloc(sprite_count * sizeof(t_sprite), dt);
	
	init_sprites(dt, i);

	consumable_count = count_elements_in_the_map(map, CONSUMABLE_TYPES);
	printf("CONSUMABLES: %ld\n", consumable_count);
	dt->levels[i].level_consumable_count = consumable_count;
}
